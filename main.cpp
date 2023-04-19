#include "IRCServer.hpp"

void printUsage()
{
	std::cout << "Usage:\n\n";
	std::cout << "./ircserv [host:port_network:password_network] <port> <password>\n";
}

int main(int argc, char **argv)
{
/* 	if (argc > 4 || argc < 3)
	{
		printUsage();
		exit(EXIT_FAILURE);
	} */

	IRCServer *irc = new IRCServer();
	irc->pollLoop();
	return 0;
}
