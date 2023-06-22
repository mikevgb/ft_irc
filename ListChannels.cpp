/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListChannels.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:00 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/21 12:57:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListChannels.hpp"

ListChannels::ListChannels()
	: _channels()
{
}

ListChannels::~ListChannels()
{
	std::map<std::string, Channel *>::iterator it;

	for (it = this->_channels.begin(); it != _channels.end(); it++)
	{
		delete it->second;
	}
}

bool ListChannels::hasKey(const std::string &key)
{
	return _channels.find(key) != _channels.end();
}

Channel *ListChannels::getChannel(const std::string &name)
{
	if (hasKey(name))
		return _channels[name];
	return NULL;
}

Channel *ListChannels::addChannel(const std::string &name)
{
	Channel *ch = new Channel(name);

	this->_channels[name] = ch;

	logg(LOG_INFO) << "New Channel: " ORANGE << name << RESET << "\n";
	return ch;
}

bool ListChannels::removeUserFromChannels(User *user)
{
	std::map<std::string, Channel *>::iterator it;

	for (it = this->_channels.begin(); it != _channels.end(); it++)
	{
		it->second->removeUser(user);
	}
	return true;
}

std::string ListChannels::getListOfChannels() const
{
	std::string list;
	std::map<std::string, Channel *>::const_iterator it;

	//TODO: Remove last comma
	for (it = this->_channels.begin(); it != _channels.end(); it++)
	{
		list += it->first + ",";
	}

	return list;
}

int ListChannels::removeChannel(User *admin, const std::string name)
{
	// TODO comprobar si existe esta opción
	Channel *channel = _channels[name];
	if (channel->isAdmin(admin))
		removeChannel(channel);
	return 0;
}

int ListChannels::removeChannel(Channel *channel)
{
	logg(LOG_INFO) << channel->getName() << " removed\n";
	_channels.erase(channel->getName());
	delete channel;
	return 0;
}

std::set<User *> ListChannels::getUsersFrom(const std::string &name)
{
	Channel *channel = _channels[name];

	return channel->getUsers();
}

int ListChannels::outOfChannel(User *user, const std::string &name)
{
	// TODO comprobar que pasa si se intenta salir de un canal en el que no estás
	Channel *channel = _channels[name];
	channel->removeUser(user);
	if (channel->isEmpty())
		removeChannel(channel);
	return 0;
}
