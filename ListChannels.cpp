/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListChannels.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:00 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/15 13:04:48 by mmateo-t         ###   ########.fr       */
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


/*
std::list<ResultCmd> ListChannels::joinChannel(const std::string &name, User *user)
{
	std::list<ResultCmd> results;
	std::cout << "ListChannels:name in joinchanel: " << name << std::endl;
	std::cout << "ListChannels:user: " << user->getNick() << std::endl;
	if (name.empty() || (name[0] != '#' && name[0] != '&'))
	{
		// TODO buscar error si el nombre no es correcto
	}
	Channel *channel;
	if (hasKey(name))
		channel = _channels[name];
	else
	{
		channel = new Channel(name);
		_channels[name] = channel;
	}

	int response = channel->addUser(user, std::string());
	if (response == 0)
	{
		ResultCmd msgToUsers;
		msgToUsers.setMsg(user->getFullName() + std::string("JOIN") + Msg::getSpace() + Msg::getColon() + name);
		msgToUsers.setUsers(getUsersFrom(name));
		results.push_back(msgToUsers);
		ResultCmd topic;
		topic.addUser(user->getFd());
		ResultCmd users(topic);
		ResultCmd endUsers(topic);
		ResultCmd modes(topic);
		topic.setMsg(getChannelResponse(name, RPL_TOPIC, user, false) + channel->getTopic());
		modes.setMsg(Msg::getColon() + Msg::getServerName() + std::string("MODE ") + name + Msg::getSpace() + channel->getModes());
		users.setMsg(getChannelResponse(name, RPL_NAMREPLY, user, true) + channel->getListUsers());
		endUsers.setMsg(getChannelResponse(name, RPL_ENDOFNAMES, user, false) + std::string("End of NAMES list."));
		results.push_back(modes);
		results.push_back(topic);
		results.push_back(users);
		results.push_back(endUsers);
	}
	else
	{
		// TODO Manejar errores de canal
	}

	return results;
}

std::string ListChannels::getChannelResponse(std::string channel, std::string code, User *user, bool igual)
{
	std::string msg;
	msg = Msg::getColon() + Msg::getServerName() + code + Msg::getSpace() + user->getNick();
	if (igual)
		msg += std::string(" =");
	msg += Msg::getSpace() + channel + Msg::getSpace() + Msg::getColon();
	return msg;
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
	_channels.erase(channel->getName());
	delete channel;
	return 0;
}

std::set<int> ListChannels::getUsersFrom(const std::string &name)
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
 */
