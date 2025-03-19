#include<string>
#include<variant>

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


};