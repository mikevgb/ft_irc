/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListUsers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:54 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/06 18:02:22 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListUsers.hpp"

ListUsers::ListUsers(/* args */)
	: _usersByNick(), _usersByFd()
{
}

ListUsers::~ListUsers()
{
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

/* int ListUsers::setNick(const std::string &nick, const size_t fd)
{
	std::cout << "set nick: " << nick << std::endl;
	// TODO comprobar que pasa en IRC si el usuario que tiene size_tenta ponerse el mismo nick
	User *user = getUser(fd);
	const std::string &oldNick = user->getNick();
	if (_usersByNick.find(nick) == _usersByNick.end())
	{
		user->setNick(nick);
		if (user->isLogged())
		{
			_usersByNick.erase(oldNick);
			addUser(user);
			return 0;
		}
		else if (!user->isLogged() && user->getUsername().length() > 0)
		{
			user->changeToLogged();
			addUser(user);
			std::cout << "nick 2: " << user->getNick() << std::endl;
			return CODE_WELCOME;
		}
	}
	else if (oldNick != nick)
	{
		return ERR_NICKNAMEINUSE;
	}
	return 0;
} */

/* int ListUsers::setUser(const std::string &name, const size_t fd)
{
	// TODO crear excepciones si no existe el usuario en la lista
	User *user = getUser(fd);
	user->setUsername(name);
	std::cout << "nick: " << user->getNick() << std::endl;
	std::cout << "user: " << user->getUsername() << std::endl;
	if (!user->isLogged() && user->getNick().length() > 0)
	{
		user->changeToLogged();
		addUser(user);
		std::cout << "user 2: " << user->getUsername() << std::endl;
		return CODE_WELCOME;
	}
	return 0;
} */

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
		delete user;
	}
	catch (const std::exception &e)
	{
		logg(LOG_ERROR) << e.what() << '\n';
	}

	return 0;
}
