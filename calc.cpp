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
	for (char c : exp ) {
		if (c  < '0' && c > '9' && c != '+' && c != '-'){
			return false;
		}
	}
	return true;
}
void Exprssion::distribution() {
	
}
