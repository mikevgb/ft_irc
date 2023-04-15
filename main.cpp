
//#include "Command.hpp"
//#include <iostream>
#include "Socket.hpp"

int main() {
	// SuperMap<std::string, std::string> myMap;
	// myMap.emplace("hola", "caracola");
	// myMap.emplace("pepe", "amigo");
	// std::string& value = myMap.getValue("pepe");
	// std::cout << value << std::endl;
	// value = "enemingo";
	// std::cout << myMap.getValue("pepe") << std::endl;;
	
	/*
	Command *C = new Command(":localhost:3000 325 /ban");

	C->parseStr();

	std::cout << *C;

	delete C;
	*/

	socketIRC *newSocket = new socketIRC();
	newSocket->pollLoop();

	return 0;
}
