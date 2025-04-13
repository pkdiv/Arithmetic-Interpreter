# Arithmetic Interpreter

Arithmetic Interpreter is a syntax-directed interpreter to interpret basic Math expressions. 

Syntax Directed Interpreters are interpreters that evaluate an expression while preforming the syntax analysis using context free grammer (CFG) rules. They directly parse the source code and execute them , without generation any intermediate code. 


Arthin uses three grammer rules to parse any arithmetic expression. 
- expr &rarr; term ((PLUS | MINUS) term) *
- term &rarr; factor ((MUL | DIV) factor) *
- factor &rarr; INTEGER | (LPAREN expr RPAREN) *
