/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoticeCmd.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:30:27 by enena             #+#    #+#             */
/*   Updated: 2022/03/07 21:23:04 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTICECMD_HPP
#define NOTICECMD_HPP
#include "ACommand.hpp"

class NoticeCmd : public ACommand
{
public:
	NoticeCmd(Message& msg, Server* owner = NULL, User* sender = NULL);
	~NoticeCmd(void);
	void	whyNotAllowed(void) const;
	void	execute(void);
};
#endif