/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRCServer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:06 by mvillaes          #+#    #+#             */
/*   Updated: 2023/04/19 13:55:13 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "lib.h"
#include "CommandHandler.hpp"

class IRCServer
{
	private:
	int _opt;
	int _nfds;
	int _rcv;
	int _sockfd;
	int _sock_opt;
	struct sockaddr_in bindSocket;
	socklen_t _addr_size;
	int _socketBind;
	char _hostname[80];
	int _escucha;
	struct hostent* host;
	struct in_addr _addr;
	struct pollfd _pollFds[420];
	int _pollReturn;
	char _buf[512];
	int _new_sd;

	public:

	void throwError(int var, std::string function)
	{
		char errbuf[256];
		if (var < 0)
		{
			strerror_r(errno, errbuf, 256);
			std::cout << function << " error: " << errbuf << std::endl;
			exit(1);
		}
		else
			std::cout << function << " OK" << std::endl;
	}

	IRCServer()
	{
		_opt = 1;
		_nfds = 1;
		_sockfd = socket(AF_INET, SOCK_STREAM, 0);
		throwError(_sockfd, "socket");

		/*make fd reusable*/
		_sock_opt = setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&_opt,
				sizeof(_opt));
		throwError(_sock_opt, "setsockopt");

		/*bind*/
		memset(&bindSocket, 0, sizeof(bindSocket));
		bindSocket.sin_family = AF_INET;
		bindSocket.sin_port = htons(4242);
		bindSocket.sin_addr.s_addr = INADDR_ANY;
		_socketBind = bind(_sockfd, (struct sockaddr*)&bindSocket, sizeof(bindSocket));
		throwError(_socketBind, "bind");

		/*listen*/
		_escucha = listen(_sockfd, 2);
		throwError(_escucha, "listen");

		/*server data*/
		if (gethostname(_hostname, sizeof(_hostname)) != -1)
			std::cout << "Host: " << _hostname << std::endl;
		host = gethostbyname(_hostname);

		if (host != 0)
		{
			for (int i = 0; host->h_addr_list[i] != 0; i++)
			{
				memcpy(&_addr, host->h_addr_list[i], sizeof(struct in_addr));
				std::cout << "IP address: " << inet_ntoa(_addr) << std::endl;
			}
		}
		std::cout << "Port: " << (int)ntohs(bindSocket.sin_port) << std::endl;
	}

	void pollLoop()
	{
		memset(&_pollFds, 0, sizeof(_pollFds));
		_new_sd = 0;
		char welcomemssg[18] = "lemIRC server v0\n";

		_pollFds[0].fd = _sockfd;
		_pollFds[0].events = POLLIN;

		CommandHandler server;

		while(1)
		{
			_pollReturn = poll(_pollFds, _nfds, 3000);
			if (_pollReturn < 0)
				throwError(_pollReturn, "poll");
			for (int i = 0; i < _nfds; i++)
			{
				memset(&_buf, 0, sizeof(_buf));
				if (_pollFds[i].revents == 0)
					continue;
				{
					if (_pollFds[i].fd == _sockfd)
					{
						if (_new_sd != -1)
						{
							_new_sd = accept(_sockfd, (struct sockaddr*)&bindSocket, &_addr_size);
							if (_new_sd < 0)
								if (errno != EWOULDBLOCK)
									throwError(_new_sd, "accept");
							_pollFds[_nfds].fd = _new_sd;
							_pollFds[_nfds].events = POLLIN;
							send(_pollFds[_nfds].fd, welcomemssg, sizeof(welcomemssg), 0);							
							server.newUser(_pollFds[i].fd);
							_nfds++;
						}
					}
					else
					{
						_rcv = recv(_pollFds[i].fd, _buf, sizeof(_buf), 0);
						if (_rcv == 0)
						{
							std::cout << "connection lost on fd: " << _pollFds[i].fd <<
								std::endl;
							close(_pollFds[i].fd);
							_pollFds[i].fd = 0;
							server.removeUser(_pollFds[i].fd);
						}
						if (_rcv > 0)
						{
							/*
							for (int x = 0; x < _nfds; x++)
							{
								if (x != i)
									send(_pollFds[x].fd, _buf, _rcv, 0);
							}
							*/

							/*
							Command cmd(_pollFds[i].fd, _buf);
							ResultCmd res = server.CommandHandler(cmd);
							std::set<int> users = res.getUsers();
							*/
							recvMessage(_buf, _pollFds[i].fd);
							std::cout << "fd: " << _pollFds[i].fd << std::endl;
							std::cout << "message: " << _buf << std::endl;
						}
					}
				}
			}
		}
	}

	void recvMessage(char *command, int fd)
	{
		std::string s(command);
		Command cmd(fd, s);
		//parse Message
		//sendMessage(command);
	}

	void sendMessage(std::string command)
	{
		std::set<int> users = result.getUsers(); //getUsers to send msg
		std::set<int>::iterator it;
		const char *str = command.c_str(); //transform string to char array
		int n = command.length();
		for (it = users.begin(); it != users.end(); it++)
		{
			send(*it, str, n, 0);
			std::cout << "Message send to fd " << *it << std::endl;
		}
	}

   	~IRCServer() {};

};

#endif
