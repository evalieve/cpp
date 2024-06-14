/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evalieve <evalieve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 14:44:57 by evalieve      #+#    #+#                 */
/*   Updated: 2024/06/13 15:45:03 by evalieve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

bool Phonebook::add_contact(int contactCount) {
	std::string input;
	
	std::cout << std::endl;

	input = _contacts[contactCount].init("first name");
	if (input.empty())
		return false;
	_contacts[contactCount].set_first_name(input);
	std::cout << std::endl;

	input = _contacts[contactCount].init("last name");
	if (input.empty())
		return false;
	_contacts[contactCount].set_last_name(input);
	std::cout << std::endl;

	input = _contacts[contactCount].init("nickname");
	if (input.empty())
		return false;
	_contacts[contactCount].set_nickname(input);
	std::cout << std::endl;

	input = _contacts[contactCount].init("phone number");
	if (input.empty())
		return false;
	_contacts[contactCount].set_phone_number(input);
	if (input.empty())
		return false;
	std::cout << std::endl;

	input = _contacts[contactCount].init("darkest secret");
	if (input.empty())
		return false;
	_contacts[contactCount].set_darkest_secret(input);

	return true;
}

void Phonebook::display_contacts() {
	std::cout << std::endl  << std::setw(24) << "CONTACTS" << std::endl;
	std::cout << "    --------------------------------" << std::endl;
	std::cout << "   |" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "   >--------------------------------<" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << " " << i + 1 << " |";
		_contacts[i].position_name();
		std::cout << std::endl; // ?
		if (i < 7)
			std::cout << "   |----------|----------|----------|" << std::endl;
	}
	std::cout << "    --------------------------------" << std::endl;
}

bool Phonebook::search_contact() {
	std::string index;
	
	std::cout << std::endl << "Which contact would you like to display?" << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, index))
			return false;
		if (index.length() == 1 && index[0] >= '1' && index[0] <= '8')
		{
			int i = index[0] - '1';
			std::cout << std::endl;
			if (_contacts[i].get_first_name() == "")
			{
				std::cout << "This contact is empty." << std::endl;
				break ;
			}
			std::cout << "    First Name: " << _contacts[i].get_first_name() << std::endl;
			std::cout << "     Last Name: " << _contacts[i].get_last_name() << std::endl;
			std::cout << "      Nickname: " << _contacts[i].get_nickname() << std::endl;
			std::cout << "  Phone Number: " << _contacts[i].get_phone_number() << std::endl;
			std::cout << "Darkest Secret: " << _contacts[i].get_darkest_secret() << std::endl;
			break ;
		}
		else
			std::cout << std::endl << "Invalid input. Please enter a number between 1 and 8." << std::endl;
	}
	
	return true;
}



