# include <iostream>
# include <string>
# include "Interpreter.h"

int main(){

    std::string input;

    std::cout << "calc>" ;
    std::getline(std::cin >> std::ws, input);

    while(input != "exit"){
        Lexer lexer(input);
        Interpreter interpreter(lexer);
        std::cout << interpreter.eval() << std::endl;
        std::cout << "calc>" ;
        std::getline(std::cin >> std::ws, input);
    };

    return 0;

}