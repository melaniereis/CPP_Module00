/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:46:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/22 09:35:16 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * Truncates a string to 10 characters and appends a period if it exceeds
 * that length.
 *
 * @param str The string to truncate.
 *
 * @return The formatted string.
 */
std::string format_field(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

/**
 * PhoneBook constructor.
 *
 * This constructor initializes the member variables index and contact_count
 * to 0. The index variable keeps track of the next available position in the
 * contacts array, and the contact_count variable keeps track of the number of
 * contacts in the array.
 */
PhoneBook::PhoneBook(void) : index(0), contact_count(0)
{
	// Initialization code if needed.
}

/**
 * PhoneBook destructor.
 *
 * This destructor is empty because the class does not have any dynamically
 * allocated memory that needs to be cleaned up.
 */
PhoneBook::~PhoneBook(void)
{
	// Cleanup code if needed.
}

/**
 * Prompts the user for input until a non-empty string is provided.
 *
 * @param prompt The message displayed to the user.
 * @return A non-empty string entered by the user.
 */

std::string PhoneBook::get_valid_input(const std::string &prompt)
{
	std::string input;
	do
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Empty input is not allowed." << std::endl;
	} while (input.empty());
	return input;
}

/**
 * Adds a new contact to the phonebook.
 *
 * This function prompts the user to enter the contact's first name, last name,
 * nickname, phone number, and darkest secret. The input is validated to ensure
 * that the phone number is a valid unsigned integer. If the contact count is
 * less than 8, it is incremented; otherwise, the index is reset to 0. Finally,
 * the contact details are stored in the contacts array and the user is notified
 * that the contact has been added successfully.
 */
void PhoneBook::add_contact(void)
{
	if (this->index >= 8)
		this->index = 0;

	std::string first = get_valid_input("Enter first name: ");
	std::string last = get_valid_input("Enter last name: ");
	std::string nick = get_valid_input("Enter nickname: ");

	std::string phoneStr;
	unsigned int phone;
	while (true)
	{
		phoneStr = get_valid_input("Enter phone number: ");
		try
		{
			char *endptr;
			unsigned long temp = strtoul(phoneStr.c_str(), &endptr, 10);
			if (endptr == phoneStr.c_str() || *endptr != '\0')
				throw std::invalid_argument("Invalid phone number input.");
			phone = static_cast<unsigned int>(temp);
			break;
		}
		catch (const std::exception &e)
		{
			std::cout << "Invalid phone number input." << std::endl;
			continue;
		}
	}

	std::string secret = get_valid_input("Enter darkest secret: ");

	this->contacts[this->index].set_contact(first, last, nick, phone, secret);
	if (this->contact_count < 8)
		this->contact_count++;
	this->index++;

	std::cout << "Contact successfully added!" << std::endl;
}

/**
 * Displays a list of contacts and allows the user to view detailed information
 * about a specific contact.
 *
 * This function prints a formatted table of contacts with their index, first name,
 * last name, and nickname. The user is prompted to enter an index to view more
 * details about a specific contact. If the index is valid, the full details of the
 * selected contact are displayed, including the first name, last name, nickname,
 * phone number, and darkest secret. If the phonebook is empty or an invalid index
 * is entered, an appropriate message is displayed.
 */
void PhoneBook::search_contact(void)
{
	if (this->contact_count == 0)
	{
		std::cout << "The phonebook is empty, no contacts available." << std::endl;
		return;
	}

	// Print table header.
	std::cout << std::setw(10) << "Index" << " |"
			  << std::setw(10) << "First Name" << " |"
			  << std::setw(10) << "Last Name" << " |"
			  << std::setw(10) << "Nickname" << std::endl;

	// Use contactCount to loop only through valid contacts.
	for (int i = 0; i < this->contact_count; i++)
	{
		std::cout << std::setw(10) << i << " |"
				  << std::setw(10) << format_field(contacts[i].get_first_name()) << " |"
				  << std::setw(10) << format_field(contacts[i].get_last_name()) << " |"
				  << std::setw(10) << format_field(contacts[i].get_nickname()) << std::endl;
	}
	if (this->contact_count == 0)
	{
		std::cout << "The phonebook is empty, no contacts available." << std::endl;
		return;
	}

	// Prompt for the index to display.
	int idx;
	while (true)
	{
		std::cout << "Enter the index of the contact to display: ";
		std::string index_input;
		std::getline(std::cin, index_input);

		if (index_input.length() != 1 || index_input < "0" || index_input > "7")
		{
			std::cout << "Invalid index. Please enter a number between 0 and 7." << std::endl;
			continue;
		}

		idx = index_input[0] - '0';
		if (idx >= contact_count)
		{
			std::cout << "No contact exists at this index. Please try again." << std::endl;
			continue;
		}
		break;
	}

	// Display full details of the chosen contact.
	std::cout << "First name: " << contacts[idx].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[idx].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[idx].get_nickname() << std::endl;
	std::cout << "Phone number: " << contacts[idx].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[idx].get_darkest_secret() << std::endl;
}
