#include <iostream>
#include <fstream> 
#include <string>

# define EMPTY_STRING 1
# define USAGE_ERROR 2
# define FILE_NOT_EXIST 3
# define OPEN_ERROR 4

void	error_msg(int code) {
	if (code == EMPTY_STRING) {
		std::cout << "error: parsing: one of strings are empty" << std::endl;
	} else if (code == USAGE_ERROR) { 
		std::cout << "error: usage:  <filename> <str1> <str2>" << std::endl;
	} else if (code == FILE_NOT_EXIST) {
		std::cout << "error: open: file don't exist" << std::endl;
	} else if (code == OPEN_ERROR) {
		std::cout << "error: open: cannot open file" << std::endl;
	}
}

bool file_exists(std::string& filename) {
	std::ifstream file;
	file.open(filename, std::ios::in);
	if (file) { file.close(); return (true); }
	error_msg(FILE_NOT_EXIST);
	return (false);
}

bool	valid_str(std::string& s1, std::string& s2) { if (s1.empty() || s2.empty()) { error_msg(EMPTY_STRING); return (false); } return (true); }

std::string	replaced(std::string& line, std::string& s1, std::string& s2) {
	std::size_t	end = 0;
	std::size_t start = 0;
	std::string new_line;

	while ((end = line.find(s1, start)) != std::string::npos) {
		new_line += line.substr(start, end - start);
		new_line += s2;
		start = end + s1.length();
	}
	new_line += line.substr(start);
	if (new_line.empty()) { return (line); }
	return (new_line);
}

int	ReplaceLine(std::string& filename, std::string& s1, std::string& s2) {
	std::ifstream file;
	std::ofstream file_out;
	std::string line;
	int size = 0;

	file.open(filename, std::ios::in);
	file_out.open(filename + "_replaced.txt", std::ios::out);
	if (!file.is_open() || !file_out.is_open()) { error_msg(OPEN_ERROR); return (1); }
	while (std::getline(file, line)) { file_out << replaced(line, s1 ,s2) << std::endl; }
	file.close();
	file_out.close();
	return (0);
}

int main(int argc, char **argv) {
	if (argc != 4) { error_msg(USAGE_ERROR); return (1); }
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (file_exists(filename) == false || valid_str(s1, s2) == false) { return (1); }
	return(ReplaceLine(filename, s1, s2));
}
