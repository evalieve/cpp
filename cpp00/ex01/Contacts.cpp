/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contacts.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evalieve <evalieve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/21 12:37:18 by evalieve      #+#    #+#                 */
/*   Updated: 2024/06/13 15:44:10 by evalieve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "Contacts.hpp"

Contacts::Contacts() : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {
}

Contacts::~Contacts() {
}

void	Contacts::set_first_name(std::string first_name) {
	this->_first_name = first_name;
}

void	Contacts::set_last_name(std::string last_name) {
	this->_last_name = last_name;
}

void	Contacts::set_nickname(std::string nickname) {
	this->_nickname = nickname;
}

void	Contacts::set_phone_number(std::string phone_number) {
	this->_phone_number = phone_number;
}

void	Contacts::set_darkest_secret(std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
}

const std::string	Contacts::get_first_name() const {
	return (_first_name);
}

const std::string	Contacts::get_last_name() const {
	return (_last_name);
}

const std::string	Contacts::get_nickname() const {
	return (_nickname);
}

const std::string	Contacts::get_phone_number() const {
	return (_phone_number);
}

const std::string	Contacts::get_darkest_secret() const {
	return (_darkest_secret);
}

std::string Contacts::truncate(std::string str) {
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	return (str);
}

void	Contacts::position_name() {
	std::cout << std::setw(10) << truncate(_first_name) << "|";
	std::cout << std::setw(10) << truncate(_last_name) << "|";
	std::cout << std::setw(10) << truncate(_nickname) << "|";
}

std::string	Contacts::init(std::string member) {
	std::string input;

	while (true) {
		std::cout << "Please enter " << member << ": ";
		if (!std::getline(std::cin, input))
			return "";
		if (!input.empty())
			break ;
		std::cout << "Don't leave " << member << " empty!" << std::endl << std::endl;
	}

	return input;
}