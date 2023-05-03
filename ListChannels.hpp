/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListChannels.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 12:45:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CHANNELS_H
#define LIST_CHANNELS_H
#include "lib2.h"

class User;
class Channel;

class ListChannels
{
private:
	std::map<std::string, Channel *> _channels;
	int removeChannel(Channel *channel);
	bool hasKey(const std::string &key);

public:
	typedef std::map<std::string, Channel>::const_iterator iterator;
	ListChannels();
	~ListChannels();
	std::list<ResultCmd> joinChannel(const std::string &name, User *user);
	int removeChannel(User *admin, const std::string name);
	Channel *getChannel(const std::string &name);
	int outOfChannel(User *user, const std::string &name);
	std::set<int> getUsersFrom(const std::string &name);
	std::string getChannelResponse(std::string channel, std::string code, User *user, bool igual);
};

#endif
