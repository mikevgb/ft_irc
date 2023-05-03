/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:04 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 17:02:08 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
#define USER_HPP
#include "lib2.h"

// class Channel;

class User
{
private:
	size_t _fd;
	std::string _nick;
	std::string _user;
	bool _isLogged;
	std::set<Channel *> _channels;

public:
	User(size_t fd);
	~User();
	size_t getFd();
	void setNick(const std::string &nick);
	const std::string &getNick() const;
	void setUser(const std::string &user);
	const std::string &getUser() const;
	bool isLogged() const;
	int changeToLogged();
	const std::string getFullName() const;
	void addChannel(Channel *channel);
	void removeChannel(Channel *channel);
	bool operator==(const User &other) const;
	void eraseUser();
};

#endif
