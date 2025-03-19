/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:10:17 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/19 21:34:15 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		unsigned int phone_number;
		std::string darkest_secret;

	public:
		// Constructor and Destructor
		Contact(void);
		~Contact(void);

		// Sets the contact details
		void set_contact(const std::string &first_name, const std::string &last_name,
						const std::string &nickname, unsigned int phone_number,
						const std::string &darkest_secret);

		// Gets the contact details
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nickname(void) const;
		unsigned int get_phone_number(void) const;
		std::string get_darkest_secret(void) const;
};

#endif
