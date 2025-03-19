/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:46:35 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/19 21:20:46 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

// Constructor
Contact::Contact(void)
{
	// Initialization code if needed.
}

// Destructor
Contact::~Contact(void)
{
	// Cleanup code if needed.
}

void Contact::set_contact(const std::string &first, const std::string &last,
						const std::string &nick, unsigned int phone,
						const std::string &secret)
{
	this->first_name = first;
	this->last_name = last;
	this->nickname = nick;
	this->phone_number = phone;
	this->darkest_secret = secret;
}
std::string Contact::get_first_name(void) const
{
	return (this->first_name);
}

std::string Contact::get_last_name(void) const
{
	return (this->last_name);
}

std::string Contact::get_nickname(void) const
{
	return (this->nickname);
}

unsigned int Contact::get_phone_number(void) const
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
	return (this->darkest_secret);
}
