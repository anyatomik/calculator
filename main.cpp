#include "calc.h"
#include <iostream>


int main() {
	std::string ans = "";
	char tr = 'y';
	std::cout <<  "Hello and wellcome to calculator!" << std::endl;
	while (tr != 'n') {
		std::cout << "Write any expression using \"+\" and \"-\" with positive"
			" prime numbers: ";
		std::cin >> ans;
		Expression e = Expression(ans);
		while (!e.allRight()) {
			std::cout << "That's wrong expression! Please, write it again:\n";
			std::cin >> ans;
			e = Expression(ans);
		}

		std::cout << e.calculate() << std::endl << "That's your answer! Do you want to try"
		" another one [y/n]? ";
		std::cin >> tr;
	}


}
