#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "lexer.h"
#include "parser.h"

static Token st_token;
static int st_token_exists;

static void
my_get_token(Token* token) {
	if (st_token_exists) {
		*token = st_token;
		st_token_exists = 0;
	} else {
		get_token(token);
	}
}

static void
unget_token(Token* token) {
	st_token = *token;
	st_token_exists = 1;
}

static double
parser_primary_expression() {
	Token token;
	
	my_get_token(&token);
	if (token.group == NUM_TOKEN) {
		return token.value;
	}
	
	fprintf(stderr, "syntax error.\n");
	exit(1);
	return 0.0;
}

static double
parser_term() {
	double v1;
	double v2;
	Token token;
	
	v1 = parser_primary_expression();
	for (;;) {
		my_get_token(&token);
		if (token.group != MUL_TOKEN
			&& token.group != DIV_TOKEN) {
			unget_token(&token);
			break;
		}
		v2 = parser_primary_expression();
		if (token.group == MUL_TOKEN) {
			v1 = v1 * v2;
		} else if (token.group == DIV_TOKEN) {
			v1 = v1 / v2;
		}
	}
	
	return v1;
}

double
parser_expression() {
	double v1;
	double v2;
	Token token;
	
	v1 = parser_term();
	for (;;) {
		my_get_token(&token);
		if (token.group != ADD_TOKEN
			&& token.group != SUB_TOKEN) {
			unget_token(&token);
			break;
		}
		v2 = parser_term();
		if (token.group == ADD_TOKEN) {
			v1 = v1 + v2;
		} else if (token.group == SUB_TOKEN) {
			v1 = v1 - v2;
		} else {
			unget_token(&token);
		}
	}
	
	return v1;
}

void set_st_token_exists(int value) {
	st_token_exists = value;
}