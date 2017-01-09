# Makefile

tinyhsp: tinyhsp.o utility.o lexer.o parser.o
	clang -Wall -O2 -o tinyhsp tinyhsp.o utility.o lexer.o parser.o -framework OpenGL -lglfw
	rm -f tinyhsp.o utility.o lexer.o parser.o

tinyhsp.o: tinyhsp.c
	clang -c tinyhsp.c

utility.o: utility.c
	clang -c utility.c

lexer.o: lexer.c
	clang -c lexer.c

parser.o: parser.c
	clang -c parser.c

clean:
	rm -f tinyhsp tinyhsp.o utility.o lexer.o parser.o