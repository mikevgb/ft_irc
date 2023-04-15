/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:06 by mvillaes          #+#    #+#             */
/*   Updated: 2022/12/06 22:31:38 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
#define SOCKET_H
#define MAX_USERS 420
#define MAXMSGSIZE 512

#include "lib2.h"

class HandleCmds;

class socketIRC
{
	private:
	HandleCmds* _handleCmds; //std::unique_ptr

	//socket options
	int _opt;
	int _nfds;
	int _rcv;
	int _sockfd;
	int _sock_opt;

	//socket address
	struct sockaddr_in bindSocket;
	socklen_t _addr_size;

	//server data
	int _socketBind;
	char _hostname[80];
	int _escucha;
	struct hostent* _p_he;
	struct in_addr _addr;

	//poll fds
	struct pollfd _pollFds[MAX_USERS];
	int _pollReturn;

	//receive buffer
	char _buf[MAXMSGSIZE];

	//accepted client socket
	int _acceptConexSocket;
	

	public:
	socketIRC();
	~socketIRC();

	void pollLoop();
	void recvMessage(std::string s, int fd);
	void ft_result(int var, std::string function);
	void setUpPoll();
	void acceptConex();
	void lostConex(int i);
	void setNonBlocking(int fdIn);

};

#endif
