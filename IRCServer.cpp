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
	_cmdHandler = new CommandHandler();
	_nfds = 1;
	_password = password;

	/*server data*/ // FIXME: Handle main arguments
	if (gethostname(_hostname, sizeof(_hostname)) == -1)
	{
		throwError("Gethostname() failed");
	}

	logg(LOG_INFO) << BLUE << "Host: " << _hostname << RESET << "\n";
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
	int new_sd = 0;

	if (new_sd != -1)
	{
		new_sd = accept(_serverSocket->sockfd, (struct sockaddr *)&_serverSocket->addr, &_serverSocket->lenaddr);
		if (new_sd < 0)
		{
			if (errno != EWOULDBLOCK)
			{
				throwError("accept() failed");
			}
		}
		logg(LOG_INFO) << "New incoming connection - [" << BLUE << new_sd << RESET << "]\n";
		_pollFds[_nfds].fd = new_sd;
		_pollFds[_nfds].events = POLLIN;
		_cmdHandler->newUser(_pollFds[_nfds].fd);
		_nfds++;
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
	logg(LOG_INFO) << "Connection lost on - fd[" << BLUE << _pollFds[i].fd << RESET << "]\n";
	if (close(_pollFds[i].fd) < 0)
	{
		throwError("Close() Error");
	}
	_cmdHandler->removeUser(_pollFds[i].fd);
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
							//recvMessage(std::string(_buf, rc), _pollFds[i].fd);
						}
						break;
					}
				}
			}
		}
	}
}

// TODO: Recive msg. CHECK IT AND FORMAT STRUCTURE!
// check for errors (errors!)

void IRCServer::recvMessage(std::string msg, int fd) // FIXME: Reformat output messages
{
	logg(LOG_DEBUG) << "Data:" << msg << "\n";
	std::list<std::string> commands(Command::split(msg, "\r\n"));
	for (std::list<std::string>::iterator itcmd = commands.begin(); itcmd != commands.end(); itcmd++)
	{
		Command *cmd = new Command(fd, *itcmd);
		std::list<ResultCmd> results = _cmdHandler->executeCmd(cmd);
		std::list<ResultCmd>::iterator it;

		if (!results.empty())
		{
			for (it = results.begin(); it != results.end(); it++)
			{
				ResultCmd result = *it;
				logg(LOG_DEBUG) << "recvMessage: " << result.getMsg() << "\n";
				std::set<int> users = result.getUsers();
				std::set<int>::iterator itusers;
				for (itusers = users.begin(); itusers != users.end(); itusers++)
				{
					int fdUser = *itusers;
					std::string tmp = result.getMsg();
					logg(LOG_DEBUG) << "recvMessage send to fd: " << fdUser << "\n"; // TODO: Why the next FD is the sum of the previous fd plus 2?
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
			logg(LOG_ERR) << "IRCServer:*** _cmdHandler->executeCmd fail! (IRCServer::recvMessage) ***\n";
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
		throwError("ftcntl() failed"); //FIXME: Set non blocking failed
	}
	fcntl(fd, F_SETFL, opts | O_NONBLOCK); // bitwise 0x01 (READONLY flag) + 0x80 (NONBLOCK flag) = 0x81
}
