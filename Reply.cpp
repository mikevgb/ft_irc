/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:51:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/16 15:19:49 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reply.hpp"

// Constructors
Reply::Reply()
{
}

Reply::Reply(const Reply &copy) : Message(copy)
{
	(void) copy;
}


// Destructor
Reply::~Reply()
{
}


// Operators
Reply & Reply::operator=(const Reply &assign)
{
	(void) assign;
	return *this;
}
