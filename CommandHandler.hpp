/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/12 20:13:02 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_CMDS_HPP
#define HANDLE_CMDS_HPP
#include "lib2.h"
#define PRIVMSG "PRIVMSG"
#define JOIN "JOIN"
#define USER "USER"
#define CAPASUPPORTANSWER "CAP * LS :"

class User;
class ListUsers;
class ListChannels;
class Command;
class ResultCmd;

class CommandHandler
{
private:
	ListUsers *_listUsers;
	ListChannels *_listChannels;
	std::string _sender;
	Command *_cmd;
	int _firstTimeFlag;

public:
	void sendPRIVMSG(const std::string &nick);
	CommandHandler(ListUsers *listUsers, ListChannels *listChannels);
	~CommandHandler();
	std::list<ResultCmd> executeCmd(Command *cmd);
	User *newUser(const int fd);
	bool removeUser(const int fd);
	ListUsers *getUsers();
	void sendFt(std::string sendToMySelf, int fd = 0); // if no fd is provided it will send to user that call's it
	std::list<ResultCmd> mierdaDeFuncionDeMiguelQueNoSabeProgramarNiEscuchar();
};

#endif
