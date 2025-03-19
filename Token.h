#include<string>
#include<variant>
#include<iostream>

enum TokenType {
    INT,
    PLUS,
    SUB,
    MUL,
    DIV,
    NONE,
    EOL
};

class Token{

    std::variant<int, std::string> value;
    TokenType type;

    public:

        Token (){
            this->value = "";
            this->type = NONE;
        }

        Token(std::variant<int, std::string> value, TokenType type){
            this->value = value;
            this->type = type;
        }

        std::variant<int, std::string> getValue(){
            return this->value;
        }

        TokenType getType(){
            return this->type;
        }

        void setType(TokenType type){
            this->type = type;
        }

        void setValue(std::variant<int, std::string> value){
            this->value = value;
        }


        friend std::ostream& operator<<(std::ostream& os , const Token& token){
            os << "Token(";
            if (std::holds_alternative<int>(token.value)) {
                os << std::get<int>(token.value);
            } else {
                os << "\"" << std::get<std::string>(token.value) << "\"";
            }
            os << ", Type: ";
            switch (token.type) {
                case TokenType::INT:  os << "INTEGER"; break;
                case TokenType::PLUS: os << "PLUS";    break;
                case TokenType::SUB:  os << "MINUS";   break;
                case TokenType::MUL:  os << "MUL";     break;
                case TokenType::DIV:  os << "DIV";     break;
                case TokenType::EOL:  os << "EOL";     break;
                case TokenType::NONE: os << "NONE";    break;
                default: os << "UNKNOWN"; break;
            }
            os << ")";
            return os;
        }


};