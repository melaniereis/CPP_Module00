/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:46:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/19 21:26:41 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

std::string format_field(const std::string &str)
{
	if (str.length() > 10)
	return str.substr(0, 9) + ".";
	return str;
}

PhoneBook::PhoneBook(void) : index(0), contact_count(0)
{
	// Initialization code if needed.
}

PhoneBook::~PhoneBook(void)
{
	// Cleanup code if needed.
}

void PhoneBook::add_contact(void)
{
	// If the array is full, start overwriting from the beginning.
	if (this->index >= 8)
		this->index = 0;

	std::string first, last, nick, phoneStr, secret;
	unsigned int phone;

	std::cout << "Enter first name: " << std::endl;
	std::getline(std::cin, first);
	while (first.empty())
	{
		std::cout << "Empty input is not allowed." << std::endl;
		std::cout << "Enter first name: " << std::endl;
		std::getline(std::cin, first);
	}
	std::cout << "Enter last name: " << std::endl;
	std::getline(std::cin, last);
	while (last.empty())
	{
		std::cout << "Empty input is not allowed." << std::endl;
		std::cout << "Enter last name: " << std::endl;
		std::getline(std::cin, last);
	}
	std::cout << "Enter nickname: " << std::endl;
	std::getline(std::cin, nick);
	while (nick.empty())
	{
		std::cout << "Empty input is not allowed." << std::endl;
		std::cout << "Enter nickname: " << std::endl;
		std::getline(std::cin, nick);
	}
	std::cout << "Enter phone number: " << std::endl;
	std::getline(std::cin, phoneStr);
	while (phoneStr.empty())
	{
		std::cout << "Empty input is not allowed." << std::endl;
		std::cout << "Enter phone number: " << std::endl;
		std::getline(std::cin, phoneStr);
	}
	try {
		phone = std::stoul(phoneStr);
	} catch (const std::exception &e) {
		std::cout << "Invalid phone number input." << std::endl;
		return;
	}
	std::cout << "Enter darkest secret: " << std::endl;
	std::getline(std::cin, secret);
	while (secret.empty())
	{
		std::cout << "Empty input is not allowed." << std::endl;
		std::cout << "Enter darkest secret: " << std::endl;
		std::getline(std::cin, secret);
	}

	// Set the contact details.
	this->contacts[this->index].set_contact(first, last, nick, phone, secret);
	// Increase contactCount if it has not reached 8 yet.
	if (this->contact_count < 8)
	this->contact_count++;
	// Move index to the next position (cyclically).
	this->index++;
}

void PhoneBook::search_contact(void)
{
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
std::cout << "Enter the index of the contact to display: ";
std::string index_input;
std::getline(std::cin, index_input);
if (index_input.length() != 1 || index_input < "0" || index_input > "7")
{
	std::cout << "Invalid index." << std::endl;
	return;
}

int idx = index_input[0] - '0';
if (idx >= contact_count)
{
	std::cout << "No contact exists at this index." << std::endl;
	return;
}

// Display full details of the chosen contact.
std::cout << "First name: " << contacts[idx].get_first_name() << std::endl;
std::cout << "Last name: " << contacts[idx].get_last_name() << std::endl;
std::cout << "Nickname: " << contacts[idx].get_nickname() << std::endl;
std::cout << "Phone number: " << contacts[idx].get_phone_number() << std::endl;
std::cout << "Darkest secret: " << contacts[idx].get_darkest_secret() << std::endl;
}
