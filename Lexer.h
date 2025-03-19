#include "Token.h"


class Lexer{

    Token currentToken;
    std::string text;
    int pos, textLength;

    std::string intLexeme(){
            
        std::string lexeme = "";

        while(isdigit(this->text[this->pos])){
            lexeme += this->text[this->pos];
            pos++;
        }

        return lexeme;
    }

    public:

        Lexer(std::string text){
            this->text = text;
            this->pos = 0;
            this->textLength = text.length();
        }

        Token getNextToken(){

            Token token;

            if (this->pos >  textLength){
                token.setType(EOL);
                token.setValue("");
                currentToken = token;
                return currentToken;
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

            currentToken = token;
            return currentToken;
        }

};
