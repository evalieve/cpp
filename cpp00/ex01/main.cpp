/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: evalieve <evalieve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 14:49:35 by evalieve      #+#    #+#                 */
/*   Updated: 2024/06/13 15:29:38 by evalieve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int main(int argc, char *argv[]) {
	Phonebook phonebook;
	std::string command;
	int contactCount = 0;

	if (argc != 1)
	{
		std::cout << "Usage: ./phonebook" << std::endl;
		return 1;
	}
	(void)argv;
	
	std::cout << std::endl << "Welcome to the phonebook!" << std::endl;
	std::cout << ">>> Please enter ADD, SEARCH, or EXIT. <<<" << std::endl;

	while (std::getline(std::cin, command))
	{
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			if (!phonebook.add_contact(contactCount))
				break ;
			contactCount++;
			contactCount %= 8;
		}
		else if (command == "SEARCH")
		{
			phonebook.display_contacts();
			if (!phonebook.search_contact())
				break ;
		}
		else
			std::cout << "\"" << command << "\"" << " is not a command!" << std::endl;
		std::cout << std::endl << ">>> Please enter ADD, SEARCH, or EXIT. <<<" << std::endl;
	}
	std::cout << std::endl << "Your phonebook has been wiped. Goodbye! (ง'̀-'́)ง" << std::endl << std::endl;
	return 0;
}