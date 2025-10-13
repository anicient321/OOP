/*#include <iostream>
#include <string>
#include <cctype>

int main() {
	std::string s;
	std::getline(std::cin, s);

	for (char& c : s) { //petlja, svaki karakter stringa se dodjeljuje varijabli c (& znaci "referenca")
		if (std::isdigit(c)) {
			c = '*';
		}
		else if (std::isspace(c)) {
			c = '_';
		}
		else {
			c = std::toupper(c);
		}
	}

	std::cout << s << std::endl;

	return 0;
}*/


https://stackoverflow.com/questions/1452721/whats-the-problem-with-using-namespace-std
https://en.cppreference.com/w/cpp/string/basic_string/getline.html
https://stackoverflow.com/questions/17136315/entry-point-not-found