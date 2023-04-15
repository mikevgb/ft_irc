

#include "HandleCmds.hpp"

int main() {
	/*
	ListUsers users;
	ListChannels channels;
	
	users.createUser(2);
	User* user = users.getUser(2);
	user->setNick("pepe");
	std::cout << "User " << user->getNick() <<std::endl;
	channels.joinChannel("#micanal", user);
	
	Channel* c = channels.getChannel("#micanal");
	std::cout <<" está en el canal " << c->getName() <<std::endl;
	*/
	/*
	HandleCmds* server = new HandleCmds();

	server->newUser(5);
	ListUsers * users = server->getUsers();
	users->setNick("Laura", 5);
	users->setUser("LAURAGOMEZ", 5);
	ListUsers::iterator it;
	for(it = users->begin(); it != users->end(); it++)
	{
		User* user = it->second;
		std::cout << "fd: " << user->getFd() << std::endl;
		std::cout << "nick: " << user->getNick() << std::endl;
	}
	*/

	//Command cmd(5,"NICK Laura");
	//server.executeCmd(cmd);
	
	
	socketIRC *newSocket = new socketIRC();
	newSocket->pollLoop();
	
	
	return 0;
}