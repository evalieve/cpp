#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contacts {
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
	
	public:
		Contacts();
		~Contacts();

		void		set_first_name(std::string first_name);
		void		set_last_name(std::string last_name);
		void		set_nickname(std::string nickname);
		void		set_phone_number(std::string phone_number);
		void		set_darkest_secret(std::string darkest_secret);

		const std::string	get_first_name() const;
		const std::string	get_last_name() const;
		const std::string	get_nickname() const;
		const std::string	get_phone_number() const;
		const std::string	get_darkest_secret() const;
		
		std::string truncate(std::string str);
		std::string	init(std::string member);
		void		position_name();


};

#endif