#include "calc.h"
#include <iostream>
#include <stdexcept>

int main() {
    std::string ans = "";
    std::string temp = "";
    char tr = 'y';
    std::cout <<  "Hello and welcome to the calculator!" << std::endl;
    while ((tr | 32) != 'n') {
        std::cout << "Write any expression using \"+\", \"-\", \"/\" or \"*\" with positive"
        " integers: ";
        std::getline(std::cin, ans);
        Expression e = Expression(ans);
        bool zero = false;
        int finalAns = 0;
        try {
            finalAns = e.calculate();
        }
        catch(const std::runtime_error & ex) {
            zero = true;
        }
        while (!e.allRight() || zero) {
            zero = false;
            std::cout << "That's wrong expression! Please, write it again: ";
            std::getline(std::cin, ans);
            e = Expression(ans);
            try {
                finalAns = e.calculate();
            }
            catch(const std::runtime_error & ex) {
                zero = true;
            }
        }
        std::cout << finalAns << std::endl << "That's your answer! Do you want to try"
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
