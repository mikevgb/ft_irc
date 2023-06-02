/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:41 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/22 17:32:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CommandHandler.hpp"

CommandHandler::CommandHandler(ListUsers *listUsers, ListChannels *listChannels)
{
	_listUsers = listUsers;
	_listChannels = listChannels;
	_firstTimeFlag = 0;
	this->_cmd = new Command("");
}

CommandHandler::~CommandHandler()
{
	delete _listUsers;
	delete _listChannels;
	delete _cmd;
}


std::list<Reply> CommandHandler::executeCmd()
{
	std::list<Reply> replies;

	if (this->_cmd->commandMap.find(this->_msg.getCmd()) != this->_cmd->commandMap.end())
	{
		replies = this->_cmd->commandMap[this->_msg.getCmd()](this->_msg.getParams(), this->_sender);
	}
	return replies;
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
	this->_cmd->setCommand(msg.getCmd());
}

void CommandHandler::setUser(const int fd)
{
	this->_sender = _listUsers->getUser(fd);
}

std::list<User *> CommandHandler::getTargets() const
{
	return this->_targets2;
}
