/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:47:24 by mvillaes          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:26 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H
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