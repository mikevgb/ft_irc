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
	_serverSocket = new Socket(ip, port);
	_nfds = 1;

	this->startServer();

	/*server data*/
	if (gethostname(_hostname, sizeof(_hostname)) != -1)
		logg(LOG_INFO) << colors::blue << "Host: " << _hostname << colors::reset << "\n";
	host = gethostbyname(_hostname);

	if (host != 0)
	{
		for (int i = 0; host->h_addr_list[i] != 0; i++)
		{
			memcpy(&_addr, host->h_addr_list[i], sizeof(struct in_addr));
			logg(LOG_INFO) << colors::yellow << "IP address: " << inet_ntoa(_addr) << colors::reset << "\n";
		}
	}
	logg(LOG_INFO) << colors::bright_green << "Port: " << (int)ntohs(_serverSocket->addr.sin_port) << colors::reset << "\n";

	this->pollLoop();
}

IRCServer::~IRCServer()
{
	close(_serverSocket->sockfd);
	delete _handleCmds;
	delete _serverSocket;
	for (int i = 0; i < _nfds; i++)
	{
		if (_pollFds[i].fd >= 0)
		{
			close(_pollFds[i].fd);
		}
	}
}

bool IRCServer::startServer()
{
	if (bind(_serverSocket->sockfd, (struct sockaddr *)&_serverSocket->addr, sizeof(_serverSocket->addr)) == -1)
	{
		logg(LOG_ERROR) << "Failed to bind to port " << ntohs(_serverSocket->addr.sin_port) << " | errno: " << errno << "\n";
		exit(EXIT_FAILURE);
	}

	logg(LOG_DEBUG) << "Socket successfully binded.\n";

	if (listen(_serverSocket->sockfd, MAX_USERS) < 0)
	{
		logg(LOG_ERROR) << "Failed to listen on socket. errno: " << errno << "\n";
		exit(EXIT_FAILURE);
	}
	return true;
}

void IRCServer::acceptConnection()
{
	int new_sd = 0;

	if (new_sd != -1)
	{
		new_sd = accept(_serverSocket->sockfd, (struct sockaddr *)&_serverSocket->addr, &_serverSocket->lenaddr);
		if (new_sd < 0)
		{
			if (errno != EWOULDBLOCK)
			{
				logg(LOG_ERR) << "accept() failed\n";
				exit(EXIT_FAILURE);
			}
		}
		logg(LOG_INFO) << "New incoming connection - " << new_sd << "\n";
		_pollFds[_nfds].fd = new_sd;
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
	_pollFds[0].fd = _serverSocket->sockfd;
	_pollFds[0].events = POLLIN;
}

void IRCServer::closeConnection(int i)
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
	int rc = 1;
	std::string data;
	bool dataReceived;

	setUpPoll();

	while (1)
	{
		logg(LOG_DEBUG) << "Waiting on poll()...\n";
		rc = poll(_pollFds, _nfds, TIMEOUT);
		if (rc < 0)
		{
			logg(LOG_ERROR) << "poll() failed | errno: " << errno << "\n";
			exit(EXIT_FAILURE);
		}
		else if (rc == 0)
		{
			logg(LOG_ERROR) << "poll() timed out.  End program.\n\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			for (int i = 0; i < _nfds; i++)
			{
				if (_pollFds[i].revents == 0)
				{
					continue;
				}
				if (_pollFds[i].revents != POLLIN) //FIXME: What happens if Client insert Ctrl + D
				{
					logg(LOG_ERROR) << "  Error! revents = " << _pollFds[i].revents << "\n";
					exit(EXIT_FAILURE);
				}
				if (_pollFds[i].fd == _serverSocket->sockfd)
				{
					acceptConnection();
				}
				else
				{
					memset(&_buf, 0, sizeof(_buf));
					dataReceived = false;
					while (!dataReceived)
					{
						rc = recv(_pollFds[i].fd, _buf, sizeof(_buf), 0);
						if (rc < 0)
						{
							if (errno != EWOULDBLOCK)
							{
								logg(LOG_ERR) << "  recv() failed\n";
							}
							break;
						}
						else if (rc == 0)
						{
							closeConnection(i);
							break;
						}
						else
						{
							dataReceived = true;
							// data.append(_buf, rc);
							data = std::string(_buf, rc);
							memset(&_buf, 0, sizeof(_buf));
						}
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
