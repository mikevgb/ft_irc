/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/15 12:43:31 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User(size_t fd)
	: _fd(fd), _nick(""), _username(""), _realname(""), _channels(), forbittenChar(",!?*@.&#")
{
	_isLogged = false;
	_isOperator = false;
}

User::~User()
{
	if (close(this->_fd) < 0)
	{
		logg(LOG_ERROR) << "Close() Error\n";
	}
}

size_t User::getFd() const
{
	return _fd;
}

bool User::setNick(const std::string &nick)
{
	bool isForbbiten = false;

	if (nick.at(0) == '$' || nick.at(0) == ':')
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

void User::addChannel(Channel *channel)
{
	_channels.insert(channel);
}

void User::removeChannel(Channel *channel)
{
	_channels.erase(channel);
}

std::string User::getRealName() const
{
	return this->_realname;
}

void User::setRealName(const std::string &user)
{
	if (this->_realname.empty())
	{
		if (user.at(0) == ':')
		{
			this->_realname = user.substr(1);
		}
		else
		{
			this->_realname = user;
		}
	}
	else
	{
		this->_realname += (" " + user);
	}
}

void User::removeAllChannels()
{
	this->_channels.clear();
}
