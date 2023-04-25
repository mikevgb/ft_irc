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

#include "include/BSLogger.hpp"

#define MSG "ECHO Daemon v1.0 \r\n"

class Socket
{
	friend class IRCServer;

public:
	static const size_t buff_size = 1024;

private:
	int sockfd;
	struct sockaddr_in addr;
	char buff_tx[buff_size];
	char buff_rx[buff_size];
	unsigned int lenaddr;
	Socket();

public:
	Socket(const char *ip, const uint16_t port);
	bool initSocket();
	~Socket();
};

#endif
