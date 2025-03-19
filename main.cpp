# include<iostream>
#include <string>
# include "Interpreter.h"

int main(){

    std::string input;

    std::cout << "calc>" ;
    std::getline(std::cin >> std::ws, input);

    while(input != "exit"){
        Interpreter interpreter(input);
        std::cout << interpreter.eval() << std::endl;
        std::cout << "calc>" ;
        std::getline(std::cin >> std::ws, input);
    };

    return 0;

}