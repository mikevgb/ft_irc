#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

int main()
{
	std::ifstream file("CoMeList");
	if (!file.is_open())
	{
		std::cout << "Error: could not open CoMeList" << std::endl;
		return 1;
	}

	std::map<std::string, std::string> string_map;
	std::string line;

	while (std::getline(file, line))
	{
		size_t equal_sign_pos = line.find(' ');
		std::string name = line.substr(0, equal_sign_pos);
		std::string value = line.substr(equal_sign_pos + 1);
		string_map[name] = value;
	}

	file.close();

	std::map<std::string, std::string>::const_iterator x;
	for (x = string_map.begin(); x != string_map.end(); ++x)
		std::cout << x->first << " = " << x->second << std::endl;

	return 0;
}
