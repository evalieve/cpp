# include "Replace.hpp"

Replace::Replace(std::string file, std::string s1, std::string s2) : file_name(file), s1(s1), s2(s2) {
	this->infile.open(this->file_name, std::ios::in);
	if (!this->infile.is_open()) {
		std::cout << "Error: could not open the file " << this->file_name << std::endl;
		exit(1);
	}
	this->outfile.open(this->file_name + ".replace", std::ios::out);
	if (!this->outfile.is_open()) {
		std::cout << "Error: could not create the file " << this->file_name + ".replace" << std::endl;
		exit(1);
	}
}

std::string	Replace::replace_occurrence(std::string line) {
	size_t pos;
	
	pos = line.find(s1);
	while (pos != std::string::npos) {
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos = line.find(s1);
	}

	return line;
}

void	Replace::build_file() {
	std::string line;

	while (std::getline(infile, line)) {
		outfile << this->replace_occurrence(line) << std::endl;
	}
	infile.close();
	outfile.close();
}