/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:46:35 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/19 21:34:17 by meferraz         ###   ########.fr       */
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

/**
 * Sets the details of the contact.
 *
 * This function sets the first name, last name, nickname, phone number, and
 * darkest secret of the contact.
 *
 * @param first The first name of the contact.
 * @param last The last name of the contact.
 * @param nick The nickname of the contact.
 * @param phone The phone number of the contact.
 * @param secret The darkest secret of the contact.
 */
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

/**
 * Retrieves the first name of the contact.
 *
 * @return The first name as a string.
 */
std::string Contact::get_first_name(void) const
{
	return (this->first_name);
}

/**
 * Retrieves the last name of the contact.
 *
 * @return The last name as a string.
 */
std::string Contact::get_last_name(void) const
{
	return (this->last_name);
}

/**
 * Retrieves the nickname of the contact.
 *
 * @return The nickname as a string.
 */
std::string Contact::get_nickname(void) const
{
	return (this->nickname);
}

/**
 * Retrieves the phone number of the contact.
 *
 * @return The phone number as an unsigned integer.
 */
unsigned int Contact::get_phone_number(void) const
{
	return (this->phone_number);
}

/**
 * Retrieves the darkest secret of the contact.
 *
 * @return The darkest secret as a string.
 */
std::string Contact::get_darkest_secret(void) const
{
	return (this->darkest_secret);
}
