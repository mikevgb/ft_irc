/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/16 18:37:00 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP
#include "lib2.h"
#define PRIVMSG "PRIVMSG"
#define JOIN "JOIN"
#define USER "USER"
#define CAPASUPPORTANSWER "CAP * LS :"
#include "Reply.hpp"
#include <map>

class User;
class ListUsers;
class ListChannels;
class Command;
class ResultCmd;
class Message;
class Reply;

class CommandHandler
{
private:
	ListUsers *_listUsers;
	ListChannels *_listChannels;
	User *_sender;
	std::list<std::string> _targets;
	Command *_cmd;
	Message _msg;
	int _firstTimeFlag;

	std::map<std::string, int(*)(std::list<std::string>)> commandMap;

	void initCommandMap();

	// Command functions
	static int nick(std::list<std::string> params);
	static int user(std::list<std::string> params);

public:
	void sendPRIVMSG(const std::string &nick);
	CommandHandler(ListUsers *listUsers, ListChannels *listChannels);
	~CommandHandler();
	int executeCmd(const std::string cmd, std::list<std::string> params);
	std::list<ResultCmd> executeCmd(Command *cmd, int fd);
	User *newUser(const int fd);
	bool removeUser(const int fd);
	ListUsers *getUsers();
	void sendFt(std::string sendToMySelf, int fd = 0); // if no fd is provided it will send to user that call's it
	Message getMessage() const;
	void setMessage(const Message &msg);
	void setUser(const int fd);
};

#endif
