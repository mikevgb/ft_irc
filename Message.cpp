/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:50:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/14 15:07:04 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

// Constructors
Message::Message(std::string buff)
{
	std::list<std::string> msg = split(buff, " ");

	//TODO: Extract prefix, cmd and params
	if (msg.front().front() == ':')
	{
		this->_prefix = msg.front();
		msg.pop_front();
	}
	this->_cmd = msg.front();
	msg.pop_front();
	this->_params = msg;
}

Message::Message(const Message &copy)
{
	_prefix = copy.getPrefix();
	_cmd = copy.getCmd();
	_params = copy.getParams();
}

// Destructor
Message::~Message()
{
}


// Operators
Message & Message::operator=(const Message &assign)
{
	_prefix = assign.getPrefix();
	_cmd = assign.getCmd();
	_params = assign.getParams();
	return *this;
}


// Getters / Setters
std::string Message::getPrefix() const
{
	return _prefix;
}
std::string Message::getCmd() const
{
	return _cmd;
}
std::list<std::string> Message::getParams() const
{
	return _params;
}

std::list<std::string> Message::split(std::string &msg, std::string delimiter)
{
	size_t pos = 0;
	std::string copy(msg);
	std::list<std::string> tokens;

	while ((pos = copy.find(delimiter)) != std::string::npos)
	{
		std::string token = copy.substr(0, pos);
		tokens.push_back(token);
		copy.erase(0, pos + delimiter.length());
	}
	if (!copy.empty())
		tokens.push_back(copy);
	return tokens;
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Message &object)
{
	stream << "Prefix: " << object.getPrefix() << std::endl;
	stream << "Cmd: " << object.getCmd() << std::endl;

	std::list<std::string> params = object.getParams();
	for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
	{
		stream << "Param: " << *it << std::endl;
	}
	return stream;
}
