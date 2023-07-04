/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:04 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/04 18:05:36 by mmateo-t         ###   ########.fr       */
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
	int _fd;
	std::string _nick;
	std::string _username;
	std::string _realname;
	bool _isLogged;
	bool _welcomeFlag;
	bool _operator;
	std::set<Channel *> _channels;
	const std::string forbittenChar;

public:
	User(int fd);
	~User();
	int getFd() const;
	bool setNick(const std::string &nick);
	const std::string &getNick() const;
	bool setUsername(const std::string &user);
	const std::string &getUsername() const;
	std::string getRealName() const;
	void setRealName(const std::string &user);
	bool isLogged() const;
	bool isOperator() const;
	bool isWelcomeSent() const;
	void setWelcomeFlag();
	void changeToLogged();
	void changeToOperator();
	const std::string getFullName() const;
	void addChannel(Channel *channel);
	void removeChannel(Channel *channel);
	void removeAllChannels();
};

#endif
