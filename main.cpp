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
/* 	if (argc > 4 || argc < 3)
	{
		printUsage();
		exit(EXIT_FAILURE);
	}
 */
	IRCServer irc("127.0.0.1", 4242);
	(void)argv;
	(void)argc;
	return 0;
}
