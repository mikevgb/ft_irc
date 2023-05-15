/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:50:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/15 17:01:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <iostream>
#include <string>
#include <list>

#define MSG_DELIMITER "\r\n"

class Message
{
public:
	// Constructors
	Message(std::string msg);
	Message(const Message &copy);

	// Destructor
	~Message();

	// Operators
	Message &operator=(const Message &assign);

	// Getters / Setters
	std::string getPrefix() const;
	std::string getCmd() const;
	std::list<std::string> getParams() const;
	std::string getMsg() const;
	void setMsg(const std::string &msg);
	void setPrefix(const std::string &prefix);
	void setCmd(const std::string &cmd);
	void setParams(const std::list<std::string> &params);

	static std::list<std::string> split(std::string &msg, std::string delimiter);

	static const size_t MAX_PARAMS = 15;
	static const size_t MAX_SIZE = 512;

protected:
	std::string _prefix;
	std::string _msg;
	std::string _cmd;
	std::list<std::string> _params;

	Message();
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Message &object);

#endif
