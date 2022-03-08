/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:29:13 by enena             #+#    #+#             */
/*   Updated: 2022/03/08 06:03:08 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JoinCmd.hpp"

JoinCmd::JoinCmd(Message& msg, Server* owner, User* sender) :
	ACommand(msg, owner, sender)
{
	_reqCountParam = 1;
	_allowed = (this->_sender) && (this->_sender->getFlags() & REGISTERED);
}

JoinCmd::~JoinCmd(void){}

void	JoinCmd::whyNotAllowed(void) const
{
	throw Error(Error::ERR_NOTREGISTERED, this->_sender);
}

void	JoinCmd::validateChannelName(std::string channelName)
{
	if (!(channelName[0] == '&' || channelName[0] == '#'))
		throw Error(Error::ERR_NOSUCHCHANNEL, this->_sender, channelName);
	if (channelName.find_first_of(" ,") != std::string::npos || channelName.find(7) != std::string::npos)
		throw Error(Error::ERR_NOSUCHCHANNEL, this->_sender, channelName);
}

void	JoinCmd::connectToChannel(std::string channelName)
{
	if (this->_sender)
	{
		std::cout << "1" << std::endl;
		if (this->_sender->getChannels().size() >= this->_owner->getMaxChannels())
			throw Error(Error::ERR_TOOMANYCHANNELS, this->_sender, channelName);
		std::cout << "2" << std::endl;
		std::string key = "";
		bool newChannel = false;
		Channel* toConnect;
		std::cout << "3" << std::endl;
		if (this->_keys.size() > 0)
		{
			std::cout << "4" << std::endl;
			key = this->_keys.front();
			this->_keys.pop();
		}
		std::cout << "5" << std::endl;
		try
		{
			std::cout << "6" << std::endl;
			toConnect = this->_owner->getChannels().at(channelName);
		}
		catch(const std::exception& e)
		{
			std::cout << "7" << std::endl;
			newChannel = true;
			this->_owner->getChannels().insert(std::pair<std::string, Channel*>(channelName, new Channel(channelName, *(this->_sender), key)));
		}
		std::cout << "8" << std::endl;
		if (newChannel)
			toConnect->addConnect(*(this->_sender), key);
		std::cout << "9" << std::endl;
		this->_sender->addChannel(*(this->_owner->getChannels().at(channelName)));
		std::cout << "10" << std::endl;
	}
}

void	JoinCmd::execute(void)
{
	checkCountParam();
	this->_channels = split(this->_base.getParams()[0], ',', false);
	if (this->_countParams > 1)
		_keys = split(this->_base.getParams()[1], ',', false);
	for (; _channels.size() > 0; _channels.pop())
	{
		std::string curChannelName = _channels.front();
		validateChannelName(curChannelName);
		connectToChannel(curChannelName);
	}
}