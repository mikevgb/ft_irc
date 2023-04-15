/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:06 by mvillaes          #+#    #+#             */
/*   Updated: 2022/12/08 20:23:32 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

socketIRC::socketIRC()
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
    _socketBind = bind(_sockfd, (struct sockaddr*)&bindSocket, sizeof(bindSocket));
    ft_result(_socketBind, "bind");

    /*listen*/
    _escucha = listen(_sockfd, 2); //that 2 should be the max number of connex 
    ft_result(_escucha, "listen");

    /*server data*/
    if (gethostname(_hostname, sizeof(_hostname)) != -1)
        std::cout << "socketIRC:Host: " << _hostname << std::endl;
    _p_he = gethostbyname(_hostname);

    if (_p_he != 0)
    {
        for (int i = 0; _p_he->h_addr_list[i] != 0; i++)
        {
            memcpy(&_addr, _p_he->h_addr_list[i], sizeof(struct in_addr));
            std::cout << "socketIRC:IP address: " << inet_ntoa(_addr) << std::endl;
        }
    }
    std::cout << "socketIRC:Port: " << (int)ntohs(bindSocket.sin_port) << std::endl;
}

socketIRC::~socketIRC()
{
    std::cout << "socketIRC:socket obj destructor called" << std::endl;
    close(_sockfd);
    delete _handleCmds;
}

void socketIRC::acceptConex()
{
    if (_acceptConexSocket != -1)
    {
        _acceptConexSocket = accept(_sockfd, (struct sockaddr*)&bindSocket, &_addr_size);
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

void socketIRC::setUpPoll()
{
    // Clear the poll file descriptors array
    memset(&_pollFds, 0, sizeof(_pollFds));

    // Set up the server socket
    _pollFds[0].fd = _sockfd;
    _pollFds[0].events = POLLIN;
}

void socketIRC::lostConex(int i)
{
    std::cout << "socketIRC:connection lost on fd: " << _pollFds[i].fd << std::endl;
    int closeReturn = close(_pollFds[i].fd);
    ft_result(closeReturn, "close");
    _handleCmds->removeUser(_pollFds[i].fd);
    _pollFds[i].fd = 0; //not sure of this
    _nfds--;
}

void socketIRC::pollLoop()
{
    _acceptConexSocket = 0;
    setUpPoll();

    while(1)
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
                    while(!dataReceived)
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
                            //data.append(_buf, _rcv);
                            data = std::string(_buf, _rcv);
                            memset(&_buf, 0, sizeof(_buf));
                        }   
                        else if (_rcv == -1)
                            ft_result(_rcv, "recv");
                        
                    }
                    if (dataReceived)
                    {
                        std::cout << "socketIRC:dataReceived" << std::endl;
                        recvMessage(data, _pollFds[i].fd);
                    }
                        
                }
            }
        }
    }
}


//TODO: 
//handle poll time out -> use epoll -> https://stackoverflow.com/questions/40070698/how-to-detect-a-timed-out-client-with-poll
//check for errors (errors!)
//replace structs with vectors

void socketIRC::recvMessage(std::string s, int fd)
{
    // std::string s(msg);
    std::cout << "socketIRC:INSIDE recvMessage: " << s << std::endl;
    (void)fd;
    std::list<std::string> comandos(Command::split(s,"\r\n"));
    //comandos.push_back(Command::split(s,"\r\n"));
     for (std::list<std::string>::iterator itcmd=comandos.begin(); itcmd != comandos.end(); itcmd++)
    {
        Command* cmd = new Command(fd, *itcmd);
        std::list<ResultCmd> results = _handleCmds->executeCmd(cmd);
        std::list<ResultCmd>::iterator it;
        
        if (!results.empty())
        {
            for(it = results.begin(); it != results.end(); it++)
            {            
                ResultCmd result = *it;
                std::cout << "socketIRC:recvMessage: " << result.getMsg() << std::endl;
                std::set<int> users = result.getUsers();
                std::set<int>::iterator itusers;
                for(itusers = users.begin(); itusers != users.end(); itusers++)
                {
                    int fdUser = *itusers;
                    std::string tmp = result.getMsg();
                    std::cout << "socketIRC:recvMessage send to fd: " << fdUser << std::endl;
                    if (!tmp.empty())
                    {
                        tmp += "\n";
                        const char *arrayMsg = tmp.c_str();
                        send(fdUser, arrayMsg, std::strlen(arrayMsg), 0);
                    }
                }
            }
            //TODO: Aquí tienes enviar la lista de resultados por sus respectivos fds
            //cada result tiene una lista de usuarios a los que se manda el mismo mensaje
        }
        else
            std::cout << "socketIRC:*** _handleCmds->executeCmd fail! (socketIRC::recvMessage) ***" << std::endl;
    }
}

void socketIRC::ft_result(int var, std::string function)
{
    if (var < 0)
    {
        std::cerr << function << " socketIRC:error: " << std::strerror(errno) << std::endl;
        exit(1);
    }
    else
        std::cout << function << " OK:socketIRC" << std::endl;
}

void socketIRC::setNonBlocking(int fdIn)
{
    int opts = fcntl(fdIn, F_GETFL); //get current fd flags
    ft_result(opts, "fcntl");
    fcntl(fdIn, F_SETFL, opts | O_NONBLOCK); //bitwise 0x01 (READONLY flag) + 0x80 (NONBLOCK flag) = 0x81
}
