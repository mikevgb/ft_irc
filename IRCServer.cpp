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

IRCServer::IRCServer(const uint16_t port, const std::string password)
{
	_listUsers = new ListUsers();
	_listChannels = new ListChannels();
	_cmdHandler = new CommandHandler(_listUsers, _listChannels);
	_nfds = 1;
	_password = password;

	/*server data*/ // FIXME: Handle main arguments
	if (gethostname(_hostname, sizeof(_hostname)) == -1)
	{
		throwError("Gethostname() failed");
	}

	logg(LOG_INFO) << ROSE << "Host: " << _hostname << RESET << "\n";
	host = gethostbyname(_hostname);

	if (host != 0)
	{
		for (int i = 0; host->h_addr_list[i] != 0; i++)
		{
			memcpy(&_addr, host->h_addr_list[i], sizeof(struct in_addr));
		}
	}
	_serverSocket = new Socket(inet_ntoa(_addr), port);
	this->startServer();
	logg(LOG_INFO) << YELLOW << "IP address: " << inet_ntoa(_addr) << RESET << "\n";
	logg(LOG_INFO) << GREEN << "Port: " << (int)ntohs(_serverSocket->addr.sin_port) << RESET << "\n";
	this->pollLoop();
}

IRCServer::~IRCServer()
{
	close(_serverSocket->sockfd);
	delete _cmdHandler;
	delete _serverSocket;
	for (int i = 0; i < _nfds; i++)
	{
		if (_pollFds[i].fd >= 0)
		{
			close(_pollFds[i].fd);
			_pollFds[i].fd = -1;
		}
	}
}

bool IRCServer::startServer()
{
	setNonBlocking(_serverSocket->sockfd);

	if (bind(_serverSocket->sockfd, (struct sockaddr *)&_serverSocket->addr, sizeof(_serverSocket->addr)) == -1)
	{
		logg(LOG_ERROR) << "Failed to bind to port " << ntohs(_serverSocket->addr.sin_port) << "\n";
		exit(EXIT_FAILURE);
	}

	logg(LOG_DEBUG) << "Socket successfully binded.\n";

	if (listen(_serverSocket->sockfd, MAX_USERS) < 0)
	{
		throwError("Failed to listen on socket");
	}
	return true;
}

void IRCServer::acceptConnection()
{
	int new_sd;

	while ((new_sd = accept(_serverSocket->sockfd, (struct sockaddr *)&_serverSocket->addr, &_serverSocket->lenaddr)) != -1)
	{
		if (new_sd < 0)
		{
			if (errno != EWOULDBLOCK)
			{
				throwError("accept() failed");
			}
		}

		logg(LOG_INFO) << "New incoming connection - [" << ROSE << new_sd << RESET << "]\n";
		for (int i = 0; i <= _nfds; i++)
		{
			if (_pollFds[i].fd <= 0)
			{
				_pollFds[i].fd = new_sd;
				_pollFds[i].events = POLLIN;
				_listUsers->createUser(_pollFds[i].fd);
				_nfds++;
				break;
			}
		}
	}
}

void IRCServer::setUpPoll()
{
	// Clear the poll file descriptors array
	memset(&_pollFds, 0, sizeof(_pollFds));

	// Set up the server socket
	_pollFds[0].fd = _serverSocket->sockfd;
	_pollFds[0].events = POLLIN;
}

void IRCServer::loseConnection(int i)
{
	logg(LOG_INFO) << "Connection lost on - fd[" << ROSE << _pollFds[i].fd << RESET << "]\n";
	if (close(_pollFds[i].fd) < 0)
	{
		throwError("Close() Error");
	}
	_listUsers->removeUser(_pollFds[i].fd);
	_pollFds[i].fd = -1;
	_nfds--;
}

void IRCServer::pollLoop()
{
	int rc = 1;

	setUpPoll();
	while (true)
	{
		logg(LOG_DEBUG) << "Waiting on poll()...\n";
		rc = poll(_pollFds, _nfds, -1);
		if (rc < 0)
		{
			throwError("poll() failed");
		}
		else
		{
			for (int i = 0; i < _nfds; i++)
			{
				if (_pollFds[i].revents == 0)
				{
					continue;
				}
				if (_pollFds[i].fd == _serverSocket->sockfd)
				{
					acceptConnection();
				}
				else
				{
					memset(&_buf, 0, sizeof(_buf));
					while (true)
					{
						rc = recv(_pollFds[i].fd, _buf, sizeof(_buf), 0);
						if (rc < 0)
						{
							if (errno != EWOULDBLOCK)
							{
								logg(LOG_ERR) << "  recv() failed\n";
							}
						}
						else if (rc == 0)
						{
							loseConnection(i);
						}
						else
						{
							// recvMessage(std::string(_buf, rc), _pollFds[i].fd);
							processMessage(std::string(_buf, rc), _pollFds[i].fd);
						}
						break;
					}
				}
			}
		}
	}
}

void IRCServer::processMessage(std::string buff, int fd)
{
	std::list<std::string> msgList = Message::split(buff, MSG_DELIMITER);
	std::list<Reply> replies;
	_cmdHandler->setUser(fd);

	for (std::list<std::string>::iterator it = msgList.begin(); it != msgList.end(); it++)
	{
		Message msg(*it);
		_cmdHandler->setMessage(msg);
		std::cout << _cmdHandler->getMessage();
		_cmdHandler->executeCmd(replies);

		for (std::list<Reply>::iterator rp = replies.begin(); rp != replies.end(); rp++)
		{
			std::set<int> targets = (*rp).getTargets();
 			for (std::set<int>::iterator user = targets.begin(); user != targets.end(); user++)
			{
				std::string msg = (*rp).getReplyMsg();
				logg(LOG_DEBUG) << "Reply: " << RED << msg << RESET << "\n";
				send(*user, msg.c_str(), msg.length(), 0);
			}
		}
	}
}

void IRCServer::throwError(std::string msg)
{
	logg(LOG_ERROR) << msg << " | Errno: " << std::strerror(errno) << "\n";
	exit(EXIT_FAILURE);
}

void IRCServer::setNonBlocking(int fd)
{
	int opts = fcntl(fd, F_GETFL); // get current fd flags
	if (opts < 0)
	{
		throwError("ftcntl() failed");
	}
	fcntl(fd, F_SETFL, opts | O_NONBLOCK); // bitwise 0x01 (READONLY flag) + 0x80 (NONBLOCK flag) = 0x81
}
