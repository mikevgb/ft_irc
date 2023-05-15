#ifndef REPLY_HPP
# define REPLY_HPP

# include <iostream>
# include <string>
# include "Message.hpp"

class Reply : public Message
{
	public:
		// Constructors
		Reply();
		Reply(const Reply &copy);

		// Destructor
		~Reply();

		// Operators
		Reply & operator=(const Reply &assign);

	private:

};

#endif
