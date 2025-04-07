#include "Lexer.h"

class Interpreter{

        std::string text;
        Lexer& lexer;
        Token token;

        void error(){
            throw std::runtime_error("Error parsing");
            exit(0);
        }

        void eat(TokenType type){

            if(token.getType() != type){
                error();
            }

            return;
        }

        int expr(){
            int result = this->term();
            
            while (token.getType() != EOL && token.getType() != RPAREN)
            {
                if(token.getType() == PLUS){
                    this->eat(PLUS);
                    result += this->term();
                }else if (token.getType() == SUB){
                    this->eat(SUB);
                    result -= this->term();
                }else{
                    //Else block is not required.
                }
            };

            return result;

        }

        int term(){
            int result = this->factor();
            token = lexer.getNextToken();

            while (token.getType() == MUL || token.getType() == DIV)
            {

                if(token.getType() == MUL){
                    this->eat(MUL);
                    result *= this->factor();
                }else if (token.getType() == DIV){
                    this->eat(DIV);
                    result /= this->factor();
                }else{
                    //Else block is not required
                }

                token = lexer.getNextToken();

            } ;

            return result;
        }

        int factor(){
            
            int result;

            token = lexer.getNextToken();

            if(token.getType() == INT){
                result = std::get<int>(token.getValue());
                this->eat(INT);
            }else if(token.getType() == LPAREN){
                this->eat(LPAREN);
                result = this->expr();
                this->eat(RPAREN);
            }else{
                //Else block is not required
            }

            return result;
        }   

        public:

            Interpreter(Lexer& lexer): lexer(lexer) { };

            std::string eval(){
                int result = this->expr();
                return std::to_string(result);
            }

};