#pragma once

typedef enum {
    INITIAL_STATUS,
    INT_STATUS,
    DOT_STATUS,
    FRAC_STATUS,
    STRING_STATUS
} LexerStatus;

void get_token(Token* token);
void set_line(char* line);