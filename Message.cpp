/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:50:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/15 17:02:36 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

// Constructors
Message::Message(const std::string buff)
{
	this->setMsg(buff);

	std::list<std::string> components = split(this->_msg, " ");

	if (components.front().front() == ':')
	{
		this->_prefix = components.front();
		components.pop_front();
	}
	this->setCmd(components.front());
	components.pop_front();
	this->setParams(components);
}

Message::Message()
{
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
Message &Message::operator=(const Message &assign)
{
	_prefix = assign.getPrefix();
	_cmd = assign.getCmd();
	_params = assign.getParams();
	_msg = assign.getMsg();
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

std::string Message::getMsg() const
{
	return _msg;
}

std::list<std::string> Message::getParams() const
{
	return _params;
}

void Message::setMsg(const std::string &msg)
{
	this->_msg = msg;

	if (this->_msg.size() > MAX_SIZE)
	{
		this->_msg.resize(MAX_SIZE);
		this->_msg.replace(MAX_SIZE - 2, 2, MSG_DELIMITER);
	}
}

void Message::setPrefix(const std::string &prefix)
{
	this->_prefix = prefix;
}

void Message::setCmd(const std::string &cmd)
{
	this->_cmd = cmd;
	for (size_t i = 0; i < cmd.size(); i++)
	{
		this->_cmd[i] = toupper(cmd[i]);
	}
}

void Message::setParams(const std::list<std::string> &params)
{
	this->_params = params;
	if (this->_params.size() > MAX_PARAMS)
	{
		this->_params.resize(this->MAX_PARAMS);
	}
}

std::list<std::string> Message::split(std::string &msg, std::string delimiter)
{
	size_t pos = 0;
	std::string copy(msg);
	std::list<std::string> tokens;

	while ((pos = copy.find(delimiter)) != std::string::npos)
	{
		if (!(copy.substr(0, delimiter.size())).compare(delimiter))
		{
			copy.erase(0, delimiter.size());
			continue;
		}
		std::string token = copy.substr(0, pos);
		tokens.push_back(token);
		copy.erase(0, pos + delimiter.length());
	}
	if (!copy.empty())
		tokens.push_back(copy);
	return tokens;
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Message &object)
{
	stream << "Message: " << object.getMsg() << std::endl;
	stream << "Prefix: " << object.getPrefix() << std::endl;
	stream << "Cmd: " << object.getCmd() << std::endl;

	std::list<std::string> params = object.getParams();
	for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
	{
		stream << "Param: " << *it << std::endl;
	}
	return stream;
}
