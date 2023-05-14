/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/14 19:42:20 by mmateo-t         ###   ########.fr       */
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
class Message;

class CommandHandler
{
private:
	ListUsers *_listUsers;
	ListChannels *_listChannels;
	User *_sender;
	std::list<std::string> _targets;
	Command *_cmd;
	Message *msg;
	int _firstTimeFlag;

public:
	void sendPRIVMSG(const std::string &nick);
	CommandHandler(ListUsers *listUsers, ListChannels *listChannels);
	~CommandHandler();
	std::list<ResultCmd> executeCmd(Command *cmd, int fd);
	bool executeCmd(Message *msg, int fd);
	User *newUser(const int fd);
	bool removeUser(const int fd);
	ListUsers *getUsers();
	void sendFt(std::string sendToMySelf, int fd = 0); // if no fd is provided it will send to user that call's it
	std::list<ResultCmd> mierdaDeFuncionDeMiguelQueNoSabeProgramarNiEscuchar();
};

#endif
