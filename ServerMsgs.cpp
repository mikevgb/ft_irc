/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerMsgs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 12:45:42 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerMsgs.hpp"

ServerMsgs::ServerMsgs(/* args */)
{
}

ServerMsgs::~ServerMsgs()
{
}

std::string ServerMsgs::getWelcomeMsg(const std::string &nick, const std::string &user)
{
	return Msg::getColon() + Msg::getServerName() + std::string(" 001 ") + nick + Msg::getColon() + Msg::getWelcomeMsg() + nick + std::string("!") + user + std::string("@") + Msg::getServerName();
}

std::string ServerMsgs::getErrNickname(const std::string &nick)
{
	return std::string("No implementado ") + nick;
}
