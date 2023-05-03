/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Msg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:28 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 12:45:36 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Msg.hpp"
Msg::Msg(/* args */)
{
}

Msg::~Msg()
{
}

std::string Msg::getSpace()
{
	return std::string(SPACE);
}
std::string Msg::getColon()
{
	return std::string(COLON);
}
std::string Msg::getAt()
{
	return std::string(AT);
}

std::string Msg::getExclamation()
{
	return std::string(EXCLAMATION);
}

std::string Msg::getLineBreak()
{
	return std::string(LINE_BREAK);
}
std::string Msg::getServerName()
{
	return std::string(SERVER_NAME);
}
/*
std::string Msg::getErrNickName()
{
	return std::string(ERR_NICKNAMEINUSE);
}
std::string Msg::getCodWelcome()
{
	return std::string(CODE_WELCOME);
}*/
std::string Msg::getWelcomeMsg()
{
	return std::string(WELCOME_MSG);
}
std::string Msg::getDuplicateNickMsg()
{
	return std::string(DUPLICATE_NICK_MSG);
}
