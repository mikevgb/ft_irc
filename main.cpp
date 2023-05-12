/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/12 18:42:24 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void printUsage()
{
	std::cout << "Usage:\t./ircserv [host:port_network:password_network] <port> <password>\n\n";
	std::cout << "Parameters:\n";
	std::cout << "\t[host]: the hostname on which IRC must connect to join a already existing network\n";
	std::cout << "\t[port_network]: the server port on which IRC must connect on host\n";
	std::cout << "\t[password_network]: the password needed to connect on host\n";
	std::cout << "\t<port>: port number on which your server will accept incoming connections.\n";
	std::cout << "\t<password>: the password needed by any IRC client who wants to connect to your server\n";
}

int main(int argc, char **argv)
{
	 	if (argc != 3)
		{
			printUsage();
			exit(EXIT_FAILURE);
		}
	
	logg.set_log_level(LOG_DEBUG);

	IRCServer irc((uint16_t)atoi(argv[1]), argv[2]);
	return 0;
}
