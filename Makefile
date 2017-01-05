# Makefile

tinyhsp: tinyhsp.o utility.o lexer.o
	clang -Wall -O2 -o tinyhsp tinyhsp.o utility.o lexer.o -framework OpenGL -lglfw

tinyhsp.o: tinyhsp.c
	clang -c tinyhsp.c

utility.o: utility.c
	clang -c utility.c

lexer.o: lexer.c
	clang -c lexer.c

clean:
 	rm -f tinyhsp tinyhsp.o utility.o lexer.o