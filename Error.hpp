/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:47:24 by mvillaes          #+#    #+#             */
/*   Updated: 2023/05/20 11:03:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
#define ERROR_HPP
#include "lib2.h"
#include "ErrorList.h"

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
