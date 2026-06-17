#pragma once
#include <string>
#include <vector>

class Expression {

public:
	Expression(std::string new_exp);
	void cleanSpaces();
	bool allRight();
	void dstribution();
	void calculate();
private:
	std::string exp;
	std::vector<std::string> numbers;
	std::vector<std::string> signs;
	int result;
};
