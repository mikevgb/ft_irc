/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:41 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/10 19:57:02 by mmateo-t         ###   ########.fr       */
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

std::list<User *> CommandHandler::getTargets() const
{
	return this->_targets;
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
	this->commandMap["PING"] = &CommandHandler::ping;
	this->commandMap["PONG"] = &CommandHandler::pong;
	this->commandMap["JOIN"] = &CommandHandler::join;
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
	/* 	// if (_sender.getMode() == 'r')
		{
			// rp.setReplyMsg(ERR_RESTRICTED);
		} */
	else if (_sender->setNick(nick))
	{
		rp.setReplyMsg(C_ERR_ERRONEUSNICKNAME, ERR_ERRONEUSNICKNAME(nick));
	}
	else
	{
		logg(LOG_INFO) << "New Nickname: " LBLUE << nick << RESET << "\n";
	}
	rp.addTarget(_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::user(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	size_t i = 1;

	if (params.size() < 4)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else
	{
		_sender->setUsername(params.front());
		params.pop_front();
		for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
		{
			if (i == 1)
			{
				// TODO: Implement mode
				// this->_sender.setMode(*it);
			}
			if (i >= 3)
			{
				this->_sender->setRealName(*it);
			}
			i++;
		}
		this->_sender->changeToLogged();
		logg(LOG_INFO) << "Username: " << ORANGE << this->_sender->getUsername() << RESET << " logged\n";
		logg(LOG_INFO) << "User: [" << this->_sender->getUsername() << "] | Real name: [" << this->_sender->getRealName() << "]\n";
		if (this->_sender->isLogged() && !this->_sender->getNick().empty())
		{
			rp.setReplyMsg(C_RPL_WELCOME, RPL_WELCOME(this->_sender->getNick()));
		}
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::quit(std::list<std::string> params, std::list<Reply> &replies)
{
	(void)replies;
	// TODO: Send msg to all users of channels
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
	std::string msg;
	User *user;

	if (params.size() < 2)
	{
		this->_msg.setMsg(ERR_NORECIPIENT(this->_msg.getCmd()));
		rp.addTarget(this->_sender->getFd());
	}
	else
	{
		user = this->_listUsers->getUser(params.front());
		if (!user)
		{
			rp.setReplyMsg(C_ERR_NOSUCHNICK, ERR_NOSUCHNICK(params.front()));
			rp.addTarget(this->_sender->getFd());
			return;
		}
		rp.addTarget(user->getFd());
		params.pop_front();
		for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
		{
			msg += (" " + *it);
		}
		rp.setMsg(msg);
	}
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

void CommandHandler::ping(std::list<std::string> params, std::list<Reply> &replies)
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

void CommandHandler::pong(std::list<std::string> params, std::list<Reply> &replies)
{
	(void)replies;
	(void)params;
}

void CommandHandler::join(std::list<std::string> params, std::list<Reply> &replies)
{
	(void)replies;
	(void)params;
}
