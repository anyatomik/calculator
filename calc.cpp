#include "calc.h"
#include <algorithm>
#include <stdexcept>

Expression::Expression(std::string new_exp) {
    exp = new_exp;
}

void Expression::cleanSpaces() {
    exp.erase(std::remove(exp.begin(), exp.end(), ' '), exp.end());
}

bool Expression::allRight() {
    cleanSpaces();
    if (exp.empty() || exp.back() == '+' || exp.back() == '-' || exp.front() == '+' || exp.front() == '-' || exp.back() == '/' || exp.back() == '*' || exp.front() == '/' || exp.front() == '*') {
        return false;
    }
    for (int i = exp.size() - 1; i  >= 0; i--) {
        if ((exp[i]  < '0' ||  exp[i] > '9') && (exp[i]  != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/')) {
            return false;
        }
    }
    return true;
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
            signs.emplace_back(c);
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
        int temp = 0;
        int i = 0;
        while (i < signs.size()) {
            if (signs[i] == '*') {
                temp = std::stoi(numbers[i+1]) * std::stoi(numbers[i]);
                numbers[i] = std::to_string(temp);
                numbers.erase(numbers.begin() + i + 1);
                signs.erase(signs.begin()+ i);
            }
            else if (signs[i] == '/') {
                if (std::stoi(numbers[i+1]) == 0) {
                    throw std::runtime_error("Division by zero!");
                }
                 temp = std::stoi(numbers[i]) / std::stoi(numbers[i+1]);
                 numbers[i] = std::to_string(temp);
                 numbers.erase(numbers.begin() + i + 1);
                 signs.erase(signs.begin()+ i);
            }
            else {
                i++;
            }
        }
        result = std::stoi(numbers[0]);
        for (int i = 0; i < siz; i++) {
            if (signs[i] == '+') {
                result += std::stoi(numbers[i+1]);
            }
            else if (signs[i] == '-') {
                result -= std::stoi(numbers[i+1]);
            }
        }
    }
    return result;
}
