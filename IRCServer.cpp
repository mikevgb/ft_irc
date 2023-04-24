/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRCServer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:06 by mvillaes          #+#    #+#             */
/*   Updated: 2023/04/19 13:55:13 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

IRCServer::IRCServer(const char *ip, const uint16_t port)
{
	_handleCmds = new HandleCmds();
	serverSocket = new Socket(ip, port);
	this->startServer();

	/*server data*/
	if (gethostname(_hostname, sizeof(_hostname)) != -1)
		std::cout << "IRCServer:Host: " << _hostname << std::endl;
	_p_he = gethostbyname(_hostname);

	if (_p_he != 0)
	{
		for (int i = 0; _p_he->h_addr_list[i] != 0; i++)
		{
			memcpy(&_addr, _p_he->h_addr_list[i], sizeof(struct in_addr));
			std::cout << "IRCServer:IP address: " << inet_ntoa(_addr) << std::endl;
		}
	}
	std::cout << "IRCServer:Port: " << (int)ntohs(bindSocket.sin_port) << std::endl;

	this->pollLoop();
}

//TODO: Convert this constructor to the constructor above
//TODO: Understand what setsocketopt do and simplify it

IRCServer::IRCServer()
{
	_handleCmds = new HandleCmds();
	_opt = 1;
	_nfds = 1;
	_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	ft_result(_sockfd, "socket");

	/*make the socket reusable*/
	_sock_opt = setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&_opt,
						   sizeof(_opt));
	ft_result(_sock_opt, "setsockopt");

	/*bind*/
	memset(&bindSocket, 0, sizeof(bindSocket));
	bindSocket.sin_family = AF_INET;
	bindSocket.sin_port = htons(4242);
	bindSocket.sin_addr.s_addr = INADDR_ANY;
	_socketBind = bind(_sockfd, (struct sockaddr *)&bindSocket, sizeof(bindSocket));
	ft_result(_socketBind, "bind");

	/*listen*/
	_escucha = listen(_sockfd, 2); // that 2 should be the max number of connex
	ft_result(_escucha, "listen");

	/*server data*/
	if (gethostname(_hostname, sizeof(_hostname)) != -1)
		std::cout << "IRCServer:Host: " << _hostname << std::endl;
	_p_he = gethostbyname(_hostname);

	if (_p_he != 0)
	{
		for (int i = 0; _p_he->h_addr_list[i] != 0; i++)
		{
			memcpy(&_addr, _p_he->h_addr_list[i], sizeof(struct in_addr));
			std::cout << "IRCServer:IP address: " << inet_ntoa(_addr) << std::endl;
		}
	}
	std::cout << "IRCServer:Port: " << (int)ntohs(bindSocket.sin_port) << std::endl;

	this->pollLoop();
}

IRCServer::~IRCServer()
{
	close(_sockfd);
	delete _handleCmds;
}

bool IRCServer::startServer()
{
	if (bind(serverSocket->sockfd, (struct sockaddr *)&serverSocket->addr, sizeof(serverSocket->addr)) == -1)
	{
		logg(LOG_ERROR) << "Failed to bind to port " << ntohs(serverSocket->addr.sin_port) << " | errno: " << errno << "\n";
		exit(EXIT_FAILURE);
	}

	logg(LOG_INFO) << "Socket successfully binded.\n";

	if (listen(serverSocket->sockfd, MAX_USERS) < 0)
	{
		logg(LOG_ERROR) << "Failed to listen on socket. errno: " << errno << "\n";
		exit(EXIT_FAILURE);
	}

	logg(LOG_INFO) << "Listening on IP: " << inet_ntoa(serverSocket->addr.sin_addr) << " | Port: " << ntohs(serverSocket->addr.sin_port) << "\n";
	return true;
}

void IRCServer::acceptConex()
{
	if (_acceptConexSocket != -1)
	{
		_acceptConexSocket = accept(_sockfd, (struct sockaddr *)&bindSocket, &_addr_size);
		if (_acceptConexSocket < 0)
			if (errno != EWOULDBLOCK)
				ft_result(_acceptConexSocket, "accept");
		_pollFds[_nfds].fd = _acceptConexSocket;
		_pollFds[_nfds].events = POLLIN;
		_handleCmds->newUser(_pollFds[_nfds].fd);
		_nfds++;
	}
	setNonBlocking(_pollFds[_nfds].fd);
}

void IRCServer::setUpPoll()
{
	// Clear the poll file descriptors array
	memset(&_pollFds, 0, sizeof(_pollFds));

	// Set up the server socket
	_pollFds[0].fd = _sockfd;
	_pollFds[0].events = POLLIN;
}

void IRCServer::lostConex(int i)
{
	std::cout << "IRCServer:connection lost on fd: " << _pollFds[i].fd << std::endl;
	int closeReturn = close(_pollFds[i].fd);
	ft_result(closeReturn, "close");
	_handleCmds->removeUser(_pollFds[i].fd);
	_pollFds[i].fd = 0; // not sure of this
	_nfds--;
}

void IRCServer::pollLoop()
{
	_acceptConexSocket = 0;
	setUpPoll();

	while (1)
	{
		_pollReturn = poll(_pollFds, _nfds, 3000);
		if (_pollReturn < 0)
			ft_result(_pollReturn, "poll");
		for (int i = 0; i < _nfds; i++)
		{
			if (_pollFds[i].revents == 0)
				continue;
			{
				if (_pollFds[i].fd == _sockfd)
					acceptConex();
				else
				{
					bool dataReceived = false;
					memset(&_buf, 0, sizeof(_buf));
					std::string data;
					_rcv = -1;
					while (!dataReceived)
					{
						_rcv = 0;
						_rcv = recv(_pollFds[i].fd, _buf, sizeof(_buf), 0);
						if (_rcv == 0)
						{
							lostConex(i);
							break;
						}
						else if (_rcv > 0)
						{
							dataReceived = true;
							// data.append(_buf, _rcv);
							data = std::string(_buf, _rcv);
							memset(&_buf, 0, sizeof(_buf));
						}
						else if (_rcv == -1)
							ft_result(_rcv, "recv");
					}
					if (dataReceived)
					{
						std::cout << "IRCServer:dataReceived" << std::endl;
						recvMessage(data, _pollFds[i].fd);
					}
				}
			}
		}
	}
}

// TODO:
// handle poll time out -> use epoll -> https://stackoverflow.com/questions/40070698/how-to-detect-a-timed-out-client-with-poll
// check for errors (errors!)
// replace structs with vectors

void IRCServer::recvMessage(std::string s, int fd)
{
	// std::string s(msg);
	std::cout << "IRCServer:INSIDE recvMessage: " << s << std::endl;
	(void)fd;
	std::list<std::string> comandos(Command::split(s, "\r\n"));
	// comandos.push_back(Command::split(s,"\r\n"));
	for (std::list<std::string>::iterator itcmd = comandos.begin(); itcmd != comandos.end(); itcmd++)
	{
		Command *cmd = new Command(fd, *itcmd);
		std::list<ResultCmd> results = _handleCmds->executeCmd(cmd);
		std::list<ResultCmd>::iterator it;

		if (!results.empty())
		{
			for (it = results.begin(); it != results.end(); it++)
			{
				ResultCmd result = *it;
				std::cout << "IRCServer:recvMessage: " << result.getMsg() << std::endl;
				std::set<int> users = result.getUsers();
				std::set<int>::iterator itusers;
				for (itusers = users.begin(); itusers != users.end(); itusers++)
				{
					int fdUser = *itusers;
					std::string tmp = result.getMsg();
					std::cout << "IRCServer:recvMessage send to fd: " << fdUser << std::endl;
					if (!tmp.empty())
					{
						tmp += "\n";
						const char *arrayMsg = tmp.c_str();
						send(fdUser, arrayMsg, std::strlen(arrayMsg), 0);
					}
				}
			}
			// TODO: Aquí tienes enviar la lista de resultados por sus respectivos fds
			// cada result tiene una lista de usuarios a los que se manda el mismo mensaje
		}
		else
			std::cout << "IRCServer:*** _handleCmds->executeCmd fail! (IRCServer::recvMessage) ***" << std::endl;
	}
}

void IRCServer::ft_result(int var, std::string function)
{
	if (var < 0)
	{
		logg(LOG_ERROR) << std::strerror(errno) << "\n";
		exit(1);
	}
	else
		logg(LOG_INFO) << function << " OK:IRCServer\n";
}

void IRCServer::setNonBlocking(int fdIn)
{
	int opts = fcntl(fdIn, F_GETFL); // get current fd flags
	ft_result(opts, "fcntl");
	fcntl(fdIn, F_SETFL, opts | O_NONBLOCK); // bitwise 0x01 (READONLY flag) + 0x80 (NONBLOCK flag) = 0x81
}
