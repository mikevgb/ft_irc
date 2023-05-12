/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListUsers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:54 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/12 20:30:15 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListUsers.hpp"

ListUsers::ListUsers(/* args */)
	: _usersByName(), _usersByFd()
{
}

ListUsers::~ListUsers()
{
}

bool ListUsers::addUser(User *user)
{
	if (_usersByName.find(user->getNick()) == _usersByName.end())
	{
		std::cout << "nick " << user->getNick() << std::endl;
		_usersByName.insert(std::pair<std::string, User *>(user->getNick(), user));
		std::cout << "nick " << user->getNick() << std::endl;
		std::cout << "user " << _usersByName[user->getNick()]->getUsername() << std::endl;
		return true;
	}
	return false;
}

User *ListUsers::createUser(const size_t fd)
{
	User *user = new User(fd);
	std::map<size_t, User *>::iterator it = _usersByFd.find(fd);
	std::map<size_t, User *>::iterator it2 = _usersByFd.end();
	logg(LOG_DEBUG) << "New user | fd: " << BLUE << fd << RESET << "\n";
	if (it != it2)
	{
		std::cout << "MIGUEL!!!! ME CAGO EN TUS MUERTOS!!!!!" << std::endl;
		return NULL;
	}
	_usersByFd[user->getFd()] = user;
	return user;
}

int ListUsers::setNick(const std::string &nick, const size_t fd)
{
	std::cout << "set nick: " << nick << std::endl;
	// TODO comprobar que pasa en IRC si el usuario que tiene size_tenta ponerse el mismo nick
	User *user = getUser(fd);
	const std::string &oldNick = user->getNick();
	if (_usersByName.find(nick) == _usersByName.end())
	{
		user->setNick(nick);
		if (user->isLogged())
		{
			_usersByName.erase(oldNick);
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
}

int ListUsers::setUser(const std::string &name, const size_t fd)
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
}

User *ListUsers::getUser(const std::string &nick)
{
	std::cout << "buscar por: " << nick << std::endl;
	if (_usersByName.find(nick) != _usersByName.end())
		return _usersByName[nick];
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
		_usersByName.erase(user->getNick());
		_usersByFd.erase(fd);
		delete user;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
