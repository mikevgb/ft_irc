/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:51:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/22 17:38:59 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reply.hpp"

// Constructors
Reply::Reply()
{
}

Reply::Reply(const int code)
{
	this->code = code;
}

Reply::Reply(const Reply &copy) : Message(copy)
{
	(void)copy;
}

// Destructor
Reply::~Reply()
{
}

// Operators
Reply &Reply::operator=(const Reply &assign)
{
	(void)assign;
	return *this;
}

// Getters and Setters
int Reply::getCode() const
{
	return this->code;
}

void Reply::setCode(const int code)
{
	this->code = code;
}

void Reply::addTarget(int fd)
{
	this->targets.insert(fd);
}

std::set<int> &Reply::getTargets()
{
	return this->targets;
}