#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include "token.h"
#include "lexer.h"

static char* st_line;
static int st_line_pos;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    } else {
        return false;
    }
}

void get_token(Token* token) {
    int out_pos = 0;
    char current_char = ' ';
    LexerStatus lex_status = INITIAL_STATUS;
    token->group = BAD_TOKEN;
    
    while (st_line[st_line_pos] != '\0') {
        current_char = st_line[st_line_pos];
        
        if ((lex_status == INT_STATUS || lex_status == FRAC_STATUS)
            && !isdigit(current_char)
            && current_char != '.') {
            token->group = NUM_TOKEN;
            sscanf(token->string, "%lf", &token->value);
            return;
        }
        
        if (current_char == '\n') {
            token->group = EOF_TOKEN;
            return;
        }
        
        if (isspace(current_char)) {
            st_line_pos += 1;
            continue;
        }
        
        if (out_pos >= MAX_TOKEN_SIZE - 1) {
            fprintf(stderr, "トークンが長すぎます\n");
            exit(1);
        }
        
        token->string[out_pos] = st_line[st_line_pos];
        st_line_pos += 1;
        out_pos += 1;
        token->string[out_pos] = '\0';
        
        if (isOperator(current_char)) { //[\+\-\*\/]
            if (current_char == '+') {
                token->group = ADD_TOKEN;
            } else if (current_char == '-') {
                token->group = SUB_TOKEN;
            } else if (current_char == '*') {
                token->group = MUL_TOKEN;
            } else if (current_char == '/') {
                token->group = DIV_TOKEN;
            } else {}
            return;
        }

        if (isdigit(current_char)) { //[0-9]
            if (lex_status == INITIAL_STATUS) {
                lex_status = INT_STATUS;
            } else if (lex_status == DOT_STATUS) {
                lex_status = FRAC_STATUS;
            } else {}
            continue;
        }
        
        if (current_char == '.') {
            if (lex_status == INT_STATUS) {
                lex_status = DOT_STATUS;
                continue;
            } else {
                fprintf(stderr, "シンタックスエラー\n");
                exit(1);
            }
        }
        
        if (current_char == '"') {
            if (lex_status == STRING_STATUS) {
                token->group = STRING_TOKEN;
                return;
            } else {
                lex_status = STRING_STATUS;
                continue;
            }
        }
        
        if (lex_status == STRING_STATUS) {
            continue;
        }
        
        fprintf(stderr, "不正な文字です:%c\n", current_char);
        exit(1);
    }
}

void set_line(char* line) {
    st_line = line;
    st_line_pos = 0;
}