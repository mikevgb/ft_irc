/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:47:24 by mvillaes          #+#    #+#             */
/*   Updated: 2023/06/02 15:04:05 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
#define ERROR_HPP
#include "lib2.h"

class Error
{
private:
	Error();

public:
	Error(int errNum)
	{
		std::cout << errNum << std::endl;
	}
	~Error();
};

#endif
