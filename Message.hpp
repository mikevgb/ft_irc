/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:31 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 12:45:36 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
#define MESSAGE_H
#include <cstring>
#include "User.hpp"
class Message
{
private:
	int _fd;
	std::string _msg;

public:
	Message(int fd, std::string msg);
	~Message();
};

Message::Message(int fd, std::string msg)
	: _fd(), _msg()
{
}

Message::~Message()
{
}

#endif
