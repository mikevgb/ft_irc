/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:51:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/05 19:27:58 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reply.hpp"

// Constructors
Reply::Reply()
{
}

Reply::Reply(const int code)
{
	this->_code = code;
}

Reply::Reply(const Reply &copy) : Message(copy)
{
	this->_targets = copy._targets;
	this->_code = copy._code;
}

// Destructor
Reply::~Reply()
{
}

// Operators
Reply &Reply::operator=(const Reply &assign)
{
	if (this != &assign)
	{
		this->_code = assign._code;
		this->_targets = assign._targets;
		this->_msg = assign._msg;
	}
	return *this;
}

// Getters and Setters
int Reply::getCode() const
{
	return this->_code;
}

void Reply::setCode(const int code)
{
	this->_code = code;
}

void Reply::addTarget(const int & fd)
{
	this->_targets.insert(fd);
}

std::set<int> Reply::getTargets() const
{
	return this->_targets;
}

std::string Reply::getReplyMsg() const
{
	//TODO: Build the whole reply adding hostname and converting code to a string
	//msg = std::string(IRCServer::_hostname) +std::to_string(this->getCode()) + " " + this->getMsg();
	return this->getMsg() + "\n";
}
