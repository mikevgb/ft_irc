/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListChannels.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/05 11:39:42 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CHANNELS_HPP
#define LIST_CHANNELS_HPP
#include "lib2.h"

class User;
class Channel;

class ListChannels
{
private:
	std::map<std::string, Channel *> _channels;
	bool hasKey(const std::string &key);

public:
	typedef std::map<std::string, Channel>::const_iterator iterator;
	ListChannels();
	~ListChannels();
	Channel *addChannel(const std::string &name);
	int removeChannel(User *admin, const std::string name);
	int removeChannel(Channel *channel);
	void removeEmptyChannels();
	Channel *getChannel(const std::string &name);
	int outOfChannel(User *user, const std::string &name);
	std::set<User *> getUsersFrom(const std::string &name);
	bool removeUserFromChannels(User *);
	std::string getListOfChannels() const;
};

#endif
