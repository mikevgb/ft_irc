#include "IRCServer.hpp"

int main()
{

	IRCServer *newSocket = new IRCServer();
	newSocket->pollLoop();

	return 0;
}
