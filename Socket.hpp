/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:41:49 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 21:29:41 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
#define SOCKET_HPP
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>

#include "include/Logger.hpp"

#define MSG "ECHO Daemon v1.0 \r\n"
#define IP "127.0.0.1"

class Socket
{
	friend class IRCServer;

public:
	static const size_t buff_size = 512;

private:
	int sockfd;
	struct sockaddr_in addr;
	char buff_tx[buff_size];
	char buff_rx[buff_size];
	unsigned int lenaddr;
	Socket();

public:
	Socket(const uint16_t port);
	bool initSocket();
	~Socket();
};

#endif
