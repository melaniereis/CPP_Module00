/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:08 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/19 21:34:12 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"
# include "PhoneBook.hpp"

/**
 * Program entry point.
 *
 * This function implements a simple command loop that allows the user to add
 * contacts to the phonebook, search for contacts, and exit the program. The
 * loop prompts the user for a command, executes the selected action, and
 * displays an appropriate message if an invalid command is entered.
 */
int main(void)
{
	PhoneBook phonebook;
	std::string command;
	while (command != "EXIT")
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command != "EXIT")
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}
