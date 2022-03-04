/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:33:06 by enena             #+#    #+#             */
/*   Updated: 2022/03/04 07:40:50 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PassCmd.hpp"

PassCmd::PassCmd(Message& msg, Server* owner, User* sender) :
	ACommand(msg, owner, sender){}

PassCmd::~PassCmd(){}

int	PassCmd::execute()
{
	//if (!this->_base.getParams().empty())
		// throw error
	if (this->_sender)
		this->_sender->setPassword(this->_base.getParams()[0]);
	return 1;
}
