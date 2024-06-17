#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <string>
# include <fstream>

class Replace {
	private:
		std::ifstream	infile;
		std::ofstream	outfile;
		std::string		file_name;
		std::string		s1;
		std::string		s2;

	public:
		Replace(std::string file, std::string s1, std::string s2);
		void build_file();
		std::string replace_occurrence(std::string line);
};

#endif