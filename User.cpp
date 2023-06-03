/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/03 17:44:29 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User(size_t fd)
	: _fd(fd), _nick(), _username(), _channels(), forbittenChar(",!?*@.&#")
{
	_isLogged = false;
}

User::~User()
{
	close(this->_fd);
}

size_t User::getFd() const
{
	return _fd;
}

bool User::setNick(const std::string &nick)
{
	bool isForbbiten = false;

	if (nick.front() == '$' || nick.front() == ':')
	{
		isForbbiten = true;
		return isForbbiten;
	}
	for (size_t i = 0; i < this->forbittenChar.size(); i++)
	{
		if (nick.find(this->forbittenChar[i]) != std::string::npos)
		{
			isForbbiten = true;
			break;
		}
	}
	if (!isForbbiten)
		_nick = nick;

	return isForbbiten;
}

const std::string &User::getNick() const
{
	return _nick;
}

bool User::setUsername(const std::string &username)
{
	_username = username;
	return true;
}
const std::string &User::getUsername() const
{
	return _username;
}

bool User::isLogged() const
{
	return _isLogged;
}
void User::changeToLogged()
{
	_isLogged = true;
}

const std::string User::getFullName() const
{
	return std::string(Msg::getColon() + _nick + Msg::getExclamation() + _username + Msg::getAt() + Msg::getServerName());
}

void User::addChannel(Channel *channel)
{
	_channels.insert(channel);
}

void User::removeChannel(Channel *channel)
{
	_channels.erase(channel);
}
