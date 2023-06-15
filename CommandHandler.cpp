/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:41 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/16 00:12:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CommandHandler.hpp"

CommandHandler::CommandHandler(IRCServer *server, ListUsers *listUsers, ListChannels *listChannels)
{
	this->server = server;
	_listUsers = listUsers;
	_listChannels = listChannels;
	_firstTimeFlag = 0;
	this->initCommandMap();
}

CommandHandler::~CommandHandler()
{
	delete _listUsers;
	delete _listChannels;
}

void CommandHandler::executeCmd(std::list<Reply> &replies)
{
	if (this->commandMap.find(this->_msg.getCmd()) != this->commandMap.end())
	{
		CommandFunction cf = this->commandMap[this->_msg.getCmd()];
		(this->*cf)(this->_msg.getParams(), replies);
	}
}

ListUsers *CommandHandler::getUsers()
{
	return _listUsers;
}

Message CommandHandler::getMessage() const
{
	return this->_msg;
}

void CommandHandler::setMessage(const Message &msg)
{
	this->_msg = msg;
}

void CommandHandler::setUser(const int fd)
{
	this->_sender = _listUsers->getUser(fd);
}

bool CommandHandler::sendAsyncMessage(int fd, std::string msg)
{
	std::string toSend = ":" + this->server->getHostname() + " " + msg + "\n";
	if (send(fd, toSend.c_str(), toSend.length(), 0) == -1)
	{
		logg(LOG_ERROR) << "An expected error occurs while sending a message\n";
		return false;
	}
	logg(LOG_INFO) << "Sent: " << ROSE << toSend << RESET;
	return true;
}

void CommandHandler::initCommandMap()
{
	this->commandMap["NICK"] = &CommandHandler::nick;
	this->commandMap["USER"] = &CommandHandler::user;
	this->commandMap["QUIT"] = &CommandHandler::quit;
	this->commandMap["PRIVMSG"] = &CommandHandler::privmsg;
	this->commandMap["CAP"] = &CommandHandler::cap;
	this->commandMap["PING"] = &CommandHandler::pong;
	this->commandMap["JOIN"] = &CommandHandler::join;
	this->commandMap["PART"] = &CommandHandler::part;
	this->commandMap["PASS"] = &CommandHandler::pass;
}

void CommandHandler::nick(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	std::string nick = params.front();

	if (params.empty())
	{
		rp.setReplyMsg(C_ERR_NONICKNAMEGIVEN, ERR_NONICKNAMEGIVEN());
	}
	else if (this->_listUsers->getUser(nick))
	{
		rp.setReplyMsg(C_ERR_NICKNAMEINUSE, ERR_NICKNAMEINUSE(nick));
	}
	else
	{
		if (_sender->setNick(nick))
			rp.setReplyMsg(C_ERR_ERRONEUSNICKNAME, ERR_ERRONEUSNICKNAME(nick));
		else
		{
			if (!this->_sender->getNick().empty() && !this->_sender->getUsername().empty())
				this->_sender->changeToLogged();
			logg(LOG_INFO) << "New Nickname: " LBLUE << nick << RESET << "\n";
			if (!this->_sender->getNick().empty() && !this->_sender->getUsername().empty())
			{
				rp.setReplyMsg(C_RPL_WELCOME, RPL_WELCOME(this->_sender->getNick(), this->_sender->getUsername(), this->server->getHostname()));
			}
		}
	}
	rp.addTarget(_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::user(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	size_t i = 1;

	if (!this->_sender->getUsername().empty())
	{
		rp.setReplyMsg(C_ERR_ALREADYREGISTRED, ERR_ALREADYREGISTRED());
	}
	else if (params.size() < 4)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else
	{
		_sender->setUsername(params.front());
		params.pop_front();
		for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
		{
			if (i >= 3)
			{
				this->_sender->setRealName(*it);
			}
			i++;
		}
		logg(LOG_INFO) << "Username: " << ORANGE << this->_sender->getUsername() << RESET << " logged\n";
		logg(LOG_INFO) << "User: [" << this->_sender->getUsername() << "] | Real name: [" << this->_sender->getRealName() << "]\n";
		if (!this->_sender->getNick().empty() && !this->_sender->getUsername().empty())
		{
			rp.setReplyMsg(C_RPL_WELCOME, RPL_WELCOME(this->_sender->getNick(), this->_sender->getUsername(), this->server->getHostname()));
		}
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::quit(std::list<std::string> params, std::list<Reply> &replies)
{
	(void)replies;
	std::string msg;

	msg = "QUIT";
	for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
	{
		msg += (" " + *it);
	}
	this->sendAsyncMessage(this->_sender->getFd(), msg);
	this->server->disconnect(this->_sender->getFd());
}

void CommandHandler::privmsg(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	Channel *ch;
	std::string msg;
	User *user;
	std::string msgtarget;
	std::set<User *> users;

	if (params.size() < 2)
	{
		rp.setReplyMsg(C_ERR_NORECIPIENT, ERR_NORECIPIENT(this->_msg.getCmd()));
	}
	else
	{
		msgtarget = params.front();
		params.pop_front();
		for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
		{
			msg += (" " + *it);
		}

		ch = this->_listChannels->getChannel(msgtarget);
		if (ch != NULL)
		{
			users = ch->getUsers();

			for (std::set<User *>::iterator it = users.begin(); it != users.end(); it++)
			{
				if ((*it)->getFd() != this->_sender->getFd())
				{
					sendAsyncMessage((*it)->getFd(), msg);
				}
			}
		}
		else
		{
			user = this->_listUsers->getUser(msgtarget);
			if (!user)
			{
				rp.setReplyMsg(C_ERR_NOSUCHNICK, ERR_NOSUCHNICK(msgtarget));
			}
			else
			{
				sendAsyncMessage(user->getFd(), msg);
			}
		}
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::cap(std::list<std::string> params, std::list<Reply> &replies)
{
	std::string msg;

	if (params.front() == "LS" || params.front() == "LIST")
	{
		msg = "CAP * " + params.front() + " :";
		this->sendAsyncMessage(this->_sender->getFd(), msg);
	}
	(void)replies;
}

void CommandHandler::pong(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	std::string msg;

	if (params.empty())
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	msg = "PONG " + params.front();
	this->sendAsyncMessage(this->_sender->getFd(), msg);
	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::join(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp1;
	Reply rp2;
	std::string msg;
	Channel *ch;

	if (params.size() != 1)
	{
		rp1.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else if (params.front() == ":")
	{
		this->sendAsyncMessage(this->_sender->getFd(), this->_listChannels->getListOfChannels());
	}
	else if (params.front() == "#0")
	{
		this->_listChannels->removeUserFromChannels(this->_sender);
		this->_sender->removeAllChannels();
		logg(LOG_INFO) << this->_sender->getNick() + " has exited from all channels\n";
	}
	else
	{
		ch = this->_listChannels->getChannel(params.front());
		if (!ch)
		{
			rp1.setReplyMsg(C_ERR_NOSUCHCHANNEL, ERR_NOSUCHCHANNEL(params.front()));
			ch = this->_listChannels->addChannel(params.front());
		}
		msg = "JOIN " + params.front();
		this->sendAsyncMessage(this->_sender->getFd(), msg);
		rp1.setReplyMsg(C_RPL_TOPIC, RPL_TOPIC(ch->getName(), ch->getTopic()));
		// Add user to the channel
		ch->addUser(this->_sender);
		rp2.setReplyMsg(C_RPL_NAMREPLY, RPL_NAMREPLY(ch->getModes(), ch->getName(), ch->getListUsers()));
	}

	rp1.addTarget(this->_sender->getFd());
	rp2.addTarget(this->_sender->getFd());
	replies.push_back(rp1);
	replies.push_back(rp2);
}

void CommandHandler::part(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	Channel *ch;
	std::string name = params.front();
	std::string msg;

	if (params.size() != 1)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else if (!(ch = this->_listChannels->getChannel(name)))
	{
		rp.setReplyMsg(C_ERR_NOSUCHCHANNEL, ERR_NOSUCHCHANNEL(name));
	}
	else if (!ch->isUser(this->_sender))
	{
		rp.setReplyMsg(C_ERR_NOTONCHANNEL, ERR_NOTONCHANNEL(name));
	}
	else
	{
		msg = "PART " + name;
		this->_sender->removeChannel(ch);
		ch->removeUser(this->_sender);
		this->sendAsyncMessage(this->_sender->getFd(), msg);
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::pass(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	std::string password = params.front();

	if (params.size() != 1)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else if (this->_sender->isLogged())
	{
		rp.setReplyMsg(C_ERR_ALREADYREGISTRED, ERR_ALREADYREGISTRED());
	}
	else if (this->server->_password == password)
	{
		this->_sender->changeToLogged();
		logg(LOG_INFO) << GREEN << "Successful Authentication\n"
					   << RESET;
	}
	else
	{
		rp.setReplyMsg(C_ERR_PASSWDMISMATCH, ERR_PASSWDMISMATCH());
	}
	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::error(const std::string reason, int fd)
{
	std::string msg;

	msg = "ERROR :" + reason;
	logg(LOG_ERR) << reason << "\n";
	this->sendAsyncMessage(fd, msg);
}
