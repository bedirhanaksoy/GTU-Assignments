flex: gpp_lexer.l gpp_interpreter.y
	flex gpp_lexer.l
	yacc -d gpp_interpreter.y
	gcc y.tab.c lex.yy.c -o gppinterpreter
	./gppinterpreter