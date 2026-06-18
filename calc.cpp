#include "calc.h"

Expression::Expression(std::string new_exp) {
	exp = new_exp;
}
void Expression::cleanSpaces(){
	std::string a = "";
	for (char c : exp) {
		if (c != ' ') {
			a += c;
		}
	}
	exp = a;
}
bool Expression::allRight(){
	cleanSpaces();
	if (!exp.empty()) {
	for (char c : exp ) {
		if ((c  < '0' ||  c > '9') && ( c != '+' && c != '-' && c != '*' && c != '/')){
			return false;
		}
	}
	return exp.back() != '+' && exp.back() != '-' && exp[0] != '+' && exp[0] != '-' && exp.back() != '/' && exp.back() != '*' && exp[0] != '/' && exp[0] != '*';}
	return false;
}
void Expression::distribution() {
	std::string temp = "";
	for (char c : exp) {
		if (c >= '0' && c  <= '9') {
		temp += c;
		}
		else if  (c == '+' || c== '-' || c == '/' || c == '*') {
			numbers.emplace_back(temp);
			temp.clear();
			temp += c;
			signs.emplace_back(c);
			temp.clear();
		}
	}
	if (temp != "") {
		numbers.emplace_back(temp);
	}

}
int Expression::calculate() {
	
	if (allRight()) {
		distribution();
		int siz = signs.size();
		result = std::stoi(numbers[0]);
		for (int i = 0; i < siz; i++) {
			if (signs[i] == '+') {
				result += std::stoi(numbers[i+1]);
			}
			else if (signs[i] == '-') {
				result -= std::stoi(numbers[i+1]);
			}
			else if (signs[i] == '*') {
                                result *= std::stoi(numbers[i+1]);
                        }
			else if (signs[i] == '/') {
                                result /= std::stoi(numbers[i+1]);
                        }
		} 
	}
	return result;
}

