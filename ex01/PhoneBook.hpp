/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:59:13 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/20 15:23:16 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# include <iostream>
# include <iomanip>
# include <string>

class PhoneBook
{
	private:
		Contact contacts[8];
		int index;
		int contact_count;
		private:
		std::string get_valid_input(const std::string &prompt);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add_contact(void);
		void search_contact(void);
};

#endif
