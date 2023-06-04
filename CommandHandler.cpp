/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:41 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/04 17:13:19 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CommandHandler.hpp"

CommandHandler::CommandHandler(ListUsers *listUsers, ListChannels *listChannels)
{
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

void CommandHandler::initCommandMap()
{
	this->commandMap["NICK"] = &CommandHandler::nick;
	this->commandMap["USER"] = &CommandHandler::user;
	this->commandMap["QUIT"] = &CommandHandler::quit;
}

// FIXME: Set errors in Reply

void CommandHandler::nick(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;

	std::string nick = params.front();

	if (params.empty())
	{
		rp.setMsg("Error");
		// rp.setMsg(ERR_NONICKNAMEGIVEN())
	}
	if (this->_listUsers->getUser(nick))
	{
		// rp.setMsg(ERR_NICKNAMEINUSE(nick));
	}
	if (_sender->setNick(nick))
	{
		rp.setMsg("Error");
		// rp.setMsg(ERR_ERRONEUSNICKNAME(params.front))
	}
	// if (_sender.getMode() == 'r')
	{
		// rp.setMsg(ERR_RESTRICTED);
	}
	rp.addTarget(_sender->getFd());
	replies.push_back(rp);
}

void CommandHandler::user(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;

	if (params.empty())
	{
		return;
	}
	_sender->setUsername(params.front());
	logg(LOG_INFO) << "USER:" << params.front();
	replies.push_back(rp);
}

void CommandHandler::quit(std::list<std::string> params, std::list<Reply> &replies)
{
	Reply rp;

	this->_listUsers->removeUser(_sender->getFd());
	rp.setCode(0);
	rp.setMsg(params.front());
	replies.push_back(rp);
}
