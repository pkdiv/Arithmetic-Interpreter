#include "Token.h"


class Lexer{

    Token currentToken;
    std::string text;
    int pos, textLength;

    int intLexeme(){
            
        std::string lexeme = "";

        while(isdigit(this->text[this->pos])){
            lexeme += this->text[this->pos];
            pos++;
        }

        return std::stoi(lexeme);
    }

    public:

        Lexer(std::string text): text(text), pos(0), textLength(text.length()) {}

        Token getNextToken(){

            Token token;

            if (this->pos >  textLength){
                token.setType(EOL);
                token.setValue("");
                currentToken = token;
                return currentToken;
            }

            while(isspace(this->text[this->pos])){
                this->pos++;
            }

            switch (this->text[this->pos])
            {
            case '+':
                token.setValue("+");
                token.setType(PLUS);
                break;
            case '-':
                token.setValue("-");
                token.setType(SUB);
                break;
            case '*':
                token.setValue("*");
                token.setType(MUL);
                break;
            case '/':
                token.setValue("/");
                token.setType(DIV);
                break;
            default:
                token.setValue(intLexeme());
                token.setType(INT);
                break;
            };

            this->pos++;
            currentToken = token;
            return currentToken;
        }
};
