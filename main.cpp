/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:42:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/21 12:19:18 by mmateo-t         ###   ########.fr       */
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
	std::cout << "\t<password>: the password needed by any IRC client who wants to connect to your server (max 16 characters)\n";
	std::cout << std::endl;
	logg(LOG_WARN) << "Server to server communication is not implemented\n";
}

void simpleErrorExit(const char *errorMessage)
{
	logg(LOG_ERROR) << errorMessage << " | Errno: " << std::strerror(errno) << "\n";
	exit(EXIT_FAILURE);
}

void parsePort(const char *portChar)
{
	for (int i = 0; portChar[i] != '\0'; ++i)
		if (!isalnum(portChar[i]))
			simpleErrorExit("Invalid port number");
	int port = atoi(portChar);
	if (port < 0 || port > 65535)
		simpleErrorExit("Invalid port range");
}

void parsePass(const char *pass)
{
	int len = strlen(pass);
	if (len > 16)
		simpleErrorExit("Password must be 16 characters length");
	for (int i = 0; pass[i] != '\0'; ++i)
		if (!isalnum(pass[i]))
			simpleErrorExit("Password must be alphanumeric");
}


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printUsage();
		exit(EXIT_FAILURE);
	}

	parsePort(argv[1]);
	parsePass(argv[2]);
	logg.set_log_level(LOG_DEBUG);

	IRCServer irc((uint16_t)atoi(argv[1]), argv[2]);
	return 0;
}
