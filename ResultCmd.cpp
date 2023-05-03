/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResultCmd.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:20 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 12:45:39 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResultCmd.hpp"

ResultCmd::ResultCmd()
	: _msg(), _users()
{
	_hasError = false;
}

ResultCmd::ResultCmd(int resultCode)
	: _resultCode(resultCode), _msg(), _users()
{
	_hasError = false;
}

ResultCmd::~ResultCmd()
{
}

void ResultCmd::setMsg(const std::string &msg)
{
	_msg = msg;
}

void ResultCmd::addToMsg(const std::string &msg)
{
	_msg += msg;
}

void ResultCmd::addUser(int fd)
{
	_users.insert(fd);
}

void ResultCmd::setUsers(const std::set<int> &fds)
{
	_users = fds;
}

void ResultCmd::setError(int errorCode)
{
	_hasError = true;
	_resultCode = errorCode;
}

int ResultCmd::getResultCode()
{
	return _resultCode;
}

const std::string &ResultCmd::getMsg()
{
	if (_msg.empty())
	{
		// TODO desde aquí se monta el mensaje, si no existe ya
	}

	return _msg;
}

std::set<int> &ResultCmd::getUsers()
{
	return _users;
}
