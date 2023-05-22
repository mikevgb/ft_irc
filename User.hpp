/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:04 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/22 14:22:06 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
#define USER_HPP

#include "Channel.hpp"
#include <string>
#include <set>

class Channel;

class User
{
private:
	size_t _fd;
	std::string _nick;
	std::string _username;
	bool _isLogged;
	std::set<Channel *> _channels;
	const std::string forbittenChar;

public:
	User(size_t fd);
	~User();
	size_t getFd();
	void setNick(const std::string &nick);
	const std::string &getNick() const;
	void setUsername(const std::string &user);
	const std::string &getUsername() const;
	bool isLogged() const;
	void changeToLogged();
	const std::string getFullName() const;
	void addChannel(Channel *channel);
	void removeChannel(Channel *channel);
};

#endif
