#include "calc.h"
#include <iostream>


int main() {
	std::string ans = "", temp = "";
	char tr = 'y';
	std::cout <<  "Hello and wellcome to calculator!" << std::endl;
	while ((tr | 32) != 'n') {
		std::cout << "Write any expression using \"+\", \"-\", \"/\" or \"*\" with positive"
			" prime numbers: ";
		std::getline(std::cin, ans);
		Expression e = Expression(ans);
		while (!e.allRight()) {
			std::cout << "That's wrong expression! Please, write it again: ";
			std::getline(std::cin, ans);
			e = Expression(ans);
		}

		std::cout << e.calculate() << std::endl << "That's your answer! Do you want to try"
		" another one [y/n]? ";
		std::getline(std::cin, temp);
		tr = temp[0];
		while (((tr | 32) != 'n' && (tr | 32) != 'y') || temp == "") {
			std::cout << "Please, write \"y\" or \"n\": ";
			std::getline(std::cin, temp);
			tr = temp[0]; 
		}
	}


}
