/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:41 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/02 17:07:55 by mmateo-t         ###   ########.fr       */
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
		replies = (this->*cf)(this->_msg.getParams(), this->_sender);
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

void CommandHandler::setMessage(const Message msg)
{
	this->_msg = msg;
}

void CommandHandler::setUser(const int fd)
{
	this->_sender = _listUsers->getUser(fd);
}

std::list<User *> CommandHandler::getTargets() const
{
	return this->_targets2;
}

void CommandHandler::initCommandMap()
{
	this->commandMap["NICK"] = &CommandHandler::nick;
	this->commandMap["USER"] = &CommandHandler::user;
	this->commandMap["QUIT"] = &CommandHandler::quit;
}

//FIXME: Set errors in Reply

std::list<Reply> CommandHandler::nick(std::list<std::string> params, User *sender)
{
	std::list<Reply> list;
	Reply rp;

	if (params.empty())
	{
		rp.setCode(1);
	}
	sender->setNick(params.front());
	rp.addTarget(sender->getFd());
	rp.setMsg("CHAOS");
	list.push_back(rp);
	return list;
}

std::list<Reply> CommandHandler::user(std::list<std::string> params, User *sender)
{
	std::list<Reply> list;
	Reply rp;

	if (params.empty())
	{
		return list;
	}
	sender->setUsername(params.front());
	logg(LOG_INFO) << "USER:" << params.front();
	list.push_back(rp);
	return list;
}

std::list<Reply> CommandHandler::quit(std::list<std::string> params, User *sender)
{
	std::list<Reply> list;
	Reply rp;

	this->_listUsers->removeUser(sender->getFd());
	rp.setCode(0);
	rp.setMsg(params.front());
	list.push_back(rp);
	return (list);
}
