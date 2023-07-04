/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:41 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/04 15:26:59 by mmateo-t         ###   ########.fr       */
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

std::string CommandHandler::getPrefix(const User *user) const
{
	return user->getNick() + "!" + user->getUsername() + "@" + this->server->getHostname();
}

bool CommandHandler::sendAsyncMessage(int fd, std::string prefix, std::string msg)
{
	std::string toSend = ":" + prefix + " " + msg + "\n";
	if (send(fd, toSend.c_str(), toSend.length(), 0) == -1)
	{
		logg(LOG_ERROR) << "An expected error occurs while sending a message\n";
		return false;
	}
	logg(LOG_INFO) << "Sent TO: [" << ORANGE << fd << RESET << "]\t" << ROSE << toSend << RESET;
	return true;
}

std::list<std::string> CommandHandler::parseList(const std::string &list)
{
	return Message::split(list, ",");
}

void CommandHandler::initCommandMap()
{
	this->commandMap["OPER"] = &CommandHandler::oper;
	this->commandMap["KILL"] = &CommandHandler::kill;
	this->commandMap["NICK"] = &CommandHandler::nick;
	this->commandMap["USER"] = &CommandHandler::user;
	this->commandMap["QUIT"] = &CommandHandler::quit;
	this->commandMap["PRIVMSG"] = &CommandHandler::privmsg;
	this->commandMap["NOTICE"] = &CommandHandler::notice;
	this->commandMap["CAP"] = &CommandHandler::cap;
	this->commandMap["PING"] = &CommandHandler::pong;
	this->commandMap["JOIN"] = &CommandHandler::join;
	this->commandMap["PART"] = &CommandHandler::part;
	this->commandMap["PASS"] = &CommandHandler::pass;
	this->commandMap["KICK"] = &CommandHandler::kick;
	this->commandMap["INVITE"] = &CommandHandler::invite;
	this->commandMap["TOPIC"] = &CommandHandler::topic;
	this->commandMap["MODE"] = &CommandHandler::mode;
}

void CommandHandler::oper(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	std::string name;
	std::string password;
	User *user;

	if (params.size() != 2)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else
	{
		name = params.front();
		params.pop_front();
		password = params.front();
		user = this->_listUsers->getUser(name);
		if (!user)
		{
			rp.setReplyMsg(C_ERR_NOOPERHOST, ERR_NOOPERHOST());
		}
		else if (password != this->server->_password)
		{
			rp.setReplyMsg(C_ERR_PASSWDMISMATCH, ERR_PASSWDMISMATCH());
		}
		else
		{
			if (user->isOperator())
			{
				rp.setReplyMsg(C_RPL_YOUREOPER, RPL_YOUREOPER());
			}
			else
			{
				user->changeToOperator();
			}
		}
	}

	rp.addTarget(_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::kill(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	std::string nick;
	std::string comment;
	std::string prefix;
	std::string msg;
	User *user;

	if (params.size() != 2)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else
	{
		nick = params.front();
		params.pop_front();
		user = this->_listUsers->getUser(nick);
		for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
		{
			comment += (*it) + " ";
		}
		if (!user)
		{
			rp.setReplyMsg(C_ERR_NOSUCHSERVER, ERR_NOSUCHSERVER(this->server->getHostname()));
		}
		else if (!this->_sender->isOperator())
		{
			rp.setReplyMsg(C_ERR_NOPRIVILEGES, ERR_NOPRIVILEGES());
		}
		else
		{
			prefix = this->_sender->getNick();
			msg = "KILL";
			// this->sendAsyncMessage(user->getFd(),)
			this->server->disconnect(user->getFd());
		}
	}

	rp.addTarget(_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::nick(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	std::string nick = params.front();
	std::string old_nick = this->_sender->getNick();
	std::string prefix;
	std::string msg;

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
			if (!this->_sender->getNick().empty() && !this->_sender->getUsername().empty() && !this->_sender->isLogged())
			{
				rp.setReplyMsg(C_RPL_WELCOME, RPL_WELCOME(this->_sender->getNick(), this->_sender->getUsername(), this->server->getHostname()));
				this->_sender->changeToLogged();
			}
			prefix = old_nick + "!" + this->_sender->getUsername() + "@" + this->server->getHostname();
			msg = "NICK " + nick;
			sendAsyncMessage(this->_sender->getFd(), prefix, msg);
			logg(LOG_INFO) << "New Nickname: " LBLUE << nick << RESET << "\n";
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
	this->sendAsyncMessage(this->_sender->getFd(), this->server->getHostname(), msg);
	this->server->disconnect(this->_sender->getFd());
}

void CommandHandler::privmsg(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	Channel *ch;
	std::string prefix;
	std::string msg;
	std::string sendMsg;
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
			prefix = this->getPrefix(this->_sender);
			users = ch->getUsers();

			for (std::set<User *>::iterator it = users.begin(); it != users.end(); it++)
			{
				if ((*it)->getFd() != this->_sender->getFd())
				{
					sendMsg = "PRIVMSG " + ch->getName() + msg;
					sendAsyncMessage((*it)->getFd(), prefix, sendMsg);
				}
			}
		}
		else
		{
			prefix = this->_sender->getNick();
			user = this->_listUsers->getUser(msgtarget);
			if (!user)
			{
				rp.setReplyMsg(C_ERR_NOSUCHNICK, ERR_NOSUCHNICK(msgtarget));
			}
			else
			{
				sendMsg = user->getNick() + msg;
				sendAsyncMessage(user->getFd(), prefix, sendMsg);
			}
		}
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::notice(std::list<std::string> params, std::list<Reply> &replies)
{
	Channel *ch;
	std::string msg;
	std::string prefix;
	User *user;
	std::string msgtarget;
	std::string sendMsg;
	std::set<User *> users;

	if (params.size() < 2)
	{
		return;
	}

	msgtarget = params.front();
	params.pop_front();
	for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
	{
		msg += (" " + *it);
	}
	ch = this->_listChannels->getChannel(msgtarget);
	if (ch != NULL)
	{
		prefix = this->getPrefix(this->_sender);
		users = ch->getUsers();

		for (std::set<User *>::iterator it = users.begin(); it != users.end(); it++)
		{
			if ((*it)->getFd() != this->_sender->getFd())
			{
				sendMsg = "NOTICE " + ch->getName() + msg;
				sendAsyncMessage((*it)->getFd(), prefix, sendMsg);
			}
		}
	}
	else
	{
		prefix = this->_sender->getNick();
		user = this->_listUsers->getUser(msgtarget);
		if (!user)
		{
			return;
		}
		else
		{
			sendMsg = user->getNick() + msg;
			sendAsyncMessage(user->getFd(), prefix, sendMsg);
		}
	}
	(void)replies;
}

void CommandHandler::cap(std::list<std::string> params, std::list<Reply> &replies)
{
	std::string msg;

	if (params.front() == "LS" || params.front() == "LIST")
	{
		msg = "CAP * " + params.front() + " :";
		this->sendAsyncMessage(this->_sender->getFd(), this->server->getHostname(), msg);
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
	this->sendAsyncMessage(this->_sender->getFd(), this->server->getHostname(), msg);
	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::join(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp1;
	Reply rp2;
	std::string prefix;
	std::string msg;
	Channel *ch;

	if (params.size() != 1)
	{
		rp1.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else if (params.front() == ":")
	{
		this->sendAsyncMessage(this->_sender->getFd(), this->server->getHostname(), this->_listChannels->getListOfChannels());
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
		if (ch && ch->isUser(this->_sender))
		{
			logg(LOG_WARN) << this->_sender->getNick() << " is already added to the channel\n";
			return;
		}
		if (!ch)
		{
			rp1.setReplyMsg(C_ERR_NOSUCHCHANNEL, ERR_NOSUCHCHANNEL(params.front()));
			ch = this->_listChannels->addChannel(params.front());
		}
		if (ch->isInviteOnly() && !ch->isInvited(this->_sender))
		{
			rp2.setReplyMsg(C_ERR_INVITEONLYCHAN, ERR_INVITEONLYCHAN(ch->getName()));
		}
		else
		{
			msg = "JOIN " + params.front();
			prefix = this->getPrefix(this->_sender);
			this->sendAsyncMessage(this->_sender->getFd(), prefix, msg);
			rp1.setReplyMsg(C_RPL_TOPIC, RPL_TOPIC(ch->getName(), ch->getTopic()));
			// Add user to the channel
			ch->addUser(this->_sender);
			rp2.setReplyMsg(C_RPL_NAMREPLY, RPL_NAMREPLY(ch->getModes(), ch->getName(), ch->getListUsers()));
		}
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
	std::string prefix;

	if (params.size() < 1)
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
		logg(LOG_INFO) << this->_sender->getNick() << " leaves the channel (" << ch->getName() << ")\n";
		if (ch->isEmpty())
		{
			this->_listChannels->removeChannel(ch);
		}
		prefix = this->getPrefix(this->_sender);
		this->sendAsyncMessage(this->_sender->getFd(), prefix, msg);
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
	this->sendAsyncMessage(fd, this->server->getHostname(), msg);
}

void CommandHandler::kick(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	Channel *ch;
	std::string ch_name;
	std::string username;
	std::string prefix;
	std::string msg;
	User *user;

	if (params.size() < 2)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else
	{
		ch_name = params.front();
		params.pop_front();
		username = params.front();
		params.pop_front();
		user = this->_listUsers->getUser(username);
		ch = this->_listChannels->getChannel(ch_name);
		if (!ch)
		{
			rp.setReplyMsg(C_ERR_NOSUCHCHANNEL, ERR_NOSUCHCHANNEL(ch_name));
		}
		else if (!ch->isUser(user))
		{
			rp.setReplyMsg(C_ERR_USERNOTINCHANNEL, ERR_USERNOTINCHANNEL(username, ch_name));
		}
		else if (!ch->isAdmin(this->_sender))
		{
			rp.setReplyMsg(C_ERR_CHANOPRIVSNEEDED, ERR_CHANOPRIVSNEEDED(ch_name));
		}
		else
		{
			ch->removeUser(user);
			prefix = this->getPrefix(this->_sender);
			msg = "KICK " + ch_name + " " + username;
			this->sendAsyncMessage(user->getFd(), prefix, msg);
		}
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::invite(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	Channel *ch;
	std::string ch_name;
	std::string nickname;
	std::string prefix;
	std::string msg;
	User *user;

	if (params.size() != 2)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else
	{
		nickname = params.front();
		params.pop_front();
		ch_name = params.front();
		user = this->_listUsers->getUser(nickname);
		ch = this->_listChannels->getChannel(ch_name);
		if (!ch)
		{
			rp.setReplyMsg(C_ERR_NOSUCHCHANNEL, ERR_NOSUCHCHANNEL(ch_name));
		}
		else if (!user)
		{
			rp.setReplyMsg(C_ERR_NOSUCHNICK, ERR_NOSUCHNICK(nickname));
		}
		else if (!ch->isUser(this->_sender))
		{
			rp.setReplyMsg(C_ERR_NOTONCHANNEL, ERR_NOTONCHANNEL(ch_name));
		}
		else if (ch->isUser(user))
		{
			rp.setReplyMsg(C_ERR_USERONCHANNEL, ERR_USERONCHANNEL(nickname, ch_name));
		}
		else if (!ch->isAdmin(this->_sender) && ch->isInviteOnly())
		{
			rp.setReplyMsg(C_ERR_CHANOPRIVSNEEDED, ERR_CHANOPRIVSNEEDED(ch_name));
		}
		else if (ch->isInvited(user))
		{
			rp.setReplyMsg(C_ERR_USERONCHANNEL, ERR_USERONCHANNEL(user->getNick(), ch->getName()));
		}
		else
		{
			ch->inviteUser(user);
			rp.setReplyMsg(C_RPL_INVITING, RPL_INVITING(ch_name, nickname));
			prefix = this->getPrefix(this->_sender);
			msg = "INVITE " + nickname + " " + ch_name;
			this->sendAsyncMessage(user->getFd(), prefix, msg);
		}
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::topic(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	std::string ch_name;
	std::string new_topic;
	std::string prefix;
	std::string msg;
	Channel *ch;
	std::set<User *> users;

	if (params.size() < 1)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else
	{
		ch_name = params.front();
		params.pop_front();
		ch = this->_listChannels->getChannel(ch_name);
		if (!ch)
		{
			rp.setReplyMsg(C_ERR_NOSUCHCHANNEL, ERR_NOSUCHCHANNEL(ch_name));
		}
		else
		{
			if (!ch->isUser(this->_sender))
			{
				rp.setReplyMsg(C_ERR_NOTONCHANNEL, ERR_NOTONCHANNEL(ch_name));
			}
			else
			{
				if (!ch->isTopicBlock() || ch->isAdmin(this->_sender))
				{
					for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
					{
						if ((*it).at(0) == ':')
						{
							new_topic += (*it).substr(1);
						}
						else
						{
							new_topic += *it;
						}
						new_topic += " ";
					}
					ch->setTopic(new_topic);
					msg = "TOPIC " + RPL_TOPIC(ch_name, ch->getTopic());
					users = ch->getUsers();
					for (std::set<User *>::iterator it = users.begin(); it != users.end(); it++)
					{
						prefix = this->getPrefix(*it);
						this->sendAsyncMessage((*it)->getFd(), prefix, msg);
					}
				}
				else
				{
					rp.setReplyMsg(C_ERR_CHANOPRIVSNEEDED, ERR_CHANOPRIVSNEEDED(ch_name));
				}
			}
		}
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::mode(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;
	std::string ch_name;
	std::string modestring;
	std::string msg;
	std::set<User *> users;
	Channel *ch;

	if (params.size() < 1)
	{
		rp.setReplyMsg(C_ERR_NEEDMOREPARAMS, ERR_NEEDMOREPARAMS(this->_msg.getCmd()));
	}
	else
	{
		ch_name = params.front();
		ch = this->_listChannels->getChannel(ch_name);
		params.pop_front();
		if (!ch)
		{
			rp.setReplyMsg(C_ERR_NOSUCHCHANNEL, ERR_NOSUCHCHANNEL(ch_name));
		}
		else if (!ch->isAdmin(this->_sender))
		{
			rp.setReplyMsg(C_ERR_CHANOPRIVSNEEDED, ERR_CHANOPRIVSNEEDED(ch_name));
		}
		else
		{
			modestring = params.front();
			if (!ch->setMode(modestring))
			{
				rp.setReplyMsg(C_ERR_NOCHANMODES, ERR_NOCHANMODES(ch_name));
			}
			else
			{
				msg = "MODE " + ch->getName() + " " + modestring;
				users = ch->getUsers();
				for (std::set<User *>::iterator it = users.begin(); it != users.end(); it++)
				{
					sendAsyncMessage((*it)->getFd(), this->getPrefix(this->_sender), msg);
				}
			}
		}
	}

	rp.addTarget(this->_sender->getFd());
	replies.push_back(rp);
}
