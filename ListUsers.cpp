/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListUsers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:54 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/13 19:42:23 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListUsers.hpp"

ListUsers::ListUsers(/* args */)
	: _usersByNick(), _usersByFd()
{
}

ListUsers::~ListUsers()
{
	std::set<User *>::iterator it;

	for (it = _listOfUsers.begin(); it != _listOfUsers.end(); it++)
	{
		delete *it;
	}
}

bool ListUsers::addUser(User *user)
{
	if (_usersByNick.find(user->getNick()) == _usersByNick.end())
	{
		_usersByNick.insert(std::pair<std::string, User *>(user->getNick(), user));
		std::cout << "nick " << user->getNick() << std::endl;
		std::cout << "user " << _usersByNick[user->getNick()]->getUsername() << std::endl;
		return true;
	}
	return false;
}

bool ListUsers::createUser(const size_t fd)
{
	User *user = new User(fd);

	if (_usersByFd.find(fd) != _usersByFd.end())
	{
		logg(LOG_ERROR) << "An unexpected issue occurs creating a new user\n";
		return false;
	}
	this->_listOfUsers.insert(user);
	_usersByFd[user->getFd()] = user;
	logg(LOG_DEBUG) << "New user | fd: " << ROSE << fd << RESET << "\n";
	return true;
}

User *ListUsers::getUser(const std::string &nick)
{
	for (std::set<User *>::iterator it = this->_listOfUsers.begin(); it != this->_listOfUsers.end(); it++)
	{
		if ((*it)->getNick() == nick)
		{
			return *it;
		}
	}
	return NULL;
}
User *ListUsers::getUser(const size_t fd)
{
	std::map<size_t, User *>::iterator it;

	it = _usersByFd.find(fd);
	if (it == _usersByFd.end())
		logg(LOG_ERROR) << "User with fd " << fd << " does not exists\n";
	return _usersByFd[fd];
}

int ListUsers::removeUser(const size_t fd)
{
	try
	{
		User *user = getUser(fd);
		_usersByNick.erase(user->getNick());
		_usersByFd.erase(fd);
		this->_listOfUsers.erase(user);
		if (!user->getNick().empty() && !user->getUsername().empty())
		{
			logg(LOG_INFO) << "User -> [Nick: " << user->getNick() << " | User: " << user->getUsername() << "] disconnected\n"
						   << RESET;
		}
		else
		{
			logg(LOG_INFO) << "User -> [FD: " << user->getFd() << "] disconnected\n"
						   << RESET;
		}
		delete user;
	}
	catch (const std::exception &e)
	{
		logg(LOG_ERROR) << e.what() << '\n';
	}

	return 0;
}
