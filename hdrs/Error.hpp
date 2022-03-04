/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:59:49 by enena             #+#    #+#             */
/*   Updated: 2022/03/04 16:59:49 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
#define ERROR_HPP
#include <exception>
#include "ACommand.hpp"
#include "Message.hpp"

class Error : public std::exception
{
public:
typedef enum errType
{
    ERR_NEEDMOREPARAMS,
    ERR_ALREADYREGISTRED,
    ERR_ERRONEUSNICKNAME,
}   errType;
private:
    ACommand&   _cmd;
    errType     _type;
public:
    Error(errType type, ACommand& cmd);
    ~Error();
    Message*    getMessage() const throw();
};

#endif