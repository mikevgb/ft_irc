/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRCServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:11 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 12:45:33 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
#define IRCSERVER_HPP
#define MAX_USERS 1024
#define MAXMSGSIZE 512
#define HOST_SIZE 128

#include "lib2.h"
#include "Socket.hpp"
#include "include/BSLogger.hpp"
#include "include/Colors.hpp"

class CommandHandler;
class logger;

class IRCServer
{
private:
	CommandHandler *_cmdHandler; // std::unique_ptr

	Socket *_serverSocket;

	// server data
	char _hostname[HOST_SIZE];
	struct hostent *host;
	struct in_addr _addr;

	// poll fds
	struct pollfd _pollFds[MAX_USERS];
	int _nfds;

	// receive buffer
	char _buf[MAXMSGSIZE];

public:
	IRCServer(const char *ip, const uint16_t port);
	~IRCServer();

	bool startServer();
	void pollLoop();
	void recvMessage(std::string s, int fd);
	void throwError(std::string msg);
	void setUpPoll();
	void acceptConnection();
	void loseConnection(int i);
	void setNonBlocking(int fdIn);
};

#endif
