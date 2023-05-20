/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/20 11:41:51 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command(const std::string &cmd) : _cmd(cmd)
{
	this->initCommandMap();
}

Command::Command(const Command &other)
{
	*this = other;
}

Command::~Command()
{
}

std::string Command::getCommand() const
{
	return _cmd;
}

void Command::setCommand(const std::string &cmd)
{
	this->_cmd = cmd;
}

Command &Command::operator=(const Command &other)
{
	_cmd = other._cmd;
	return *this;
}

void Command::initCommandMap()
{
	this->commandMap["NICK"] = &nick;
	this->commandMap["USER"] = &user;
}

//FIXME: Set errors in Reply

Reply Command::nick(std::list<std::string> params, User *sender)
{
	Reply rp;

	if (params.empty())
	{
		rp.setCode(1);
	}
	sender->setNick(params.front());
	logg(LOG_INFO) << "NICK:" << params.front();
	return rp;
}

Reply Command::user(std::list<std::string> params, User *sender)
{
	Reply rp;

	if (params.empty())
	{
		return rp;
	}
	sender->setUsername(params.front());
	logg(LOG_INFO) << "USER:" << params.front();
	return rp;
}
