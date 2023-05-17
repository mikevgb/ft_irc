/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/17 19:09:37 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command(const std::string &cmd) : _cmd(cmd)
{
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
