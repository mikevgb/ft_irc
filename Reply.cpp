/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:51:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/10 20:01:43 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reply.hpp"

// Constructors
Reply::Reply() : _code("")
{
}

Reply::Reply(const std::string code)
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
std::string Reply::getCode() const
{
	return this->_code;
}

void Reply::setCode(const std::string code)
{
	this->_code = code;
}

void Reply::addTarget(const int &fd)
{
	this->_targets.insert(fd);
}

std::set<int> Reply::getTargets() const
{
	return this->_targets;
}

std::string Reply::getReplyMsg(const std::string hostname, const std::string nick) const
{
	if (!this->_code.empty())
	{
		return ":" + hostname + " " + this->_code + " " + nick + " " + this->_msg + "\n";
	}
	return "";
}

void Reply::setReplyMsg(const std::string code, const std::string message)
{
	this->_code = code;
	this->_msg = message;
}
