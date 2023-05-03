/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Msg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:23 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 12:45:37 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
#define MSG_H
#include <string>
// #include "ServerMsgs.hpp"
#define SPACE " "
#define COLON ":"
#define AT "@"
#define EXCLAMATION "!~"

#define LINE_BREAK "\n"
#define SERVER_NAME "localhost "
#define DUPLICATE_NICK_MSG "Nickname is already in use"
#define WELCOME_MSG "Welcome to the Internet Relay Network"
class Msg
{
private:
	/* data */
public:
	Msg(/* args */);
	~Msg();
	static std::string getSpace();
	static std::string getColon();
	static std::string getAt();
	static std::string getExclamation();
	static std::string getLineBreak();
	static std::string getServerName();
	static std::string getErrNickName();
	static std::string getCodWelcome();
	static std::string getWelcomeMsg();
	static std::string getDuplicateNickMsg();
};

#endif
