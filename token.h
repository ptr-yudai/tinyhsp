#pragma once

typedef enum {
    BAD_TOKEN,
    NUM_TOKEN,
    ADD_TOKEN,
    SUB_TOKEN,
    MUL_TOKEN,
    DIV_TOKEN,
    EOF_TOKEN
} TokenGroup;

#define MAX_TOKEN_SIZE (1024)

typedef struct {
    TokenGroup group;
    double value;
    char string[MAX_TOKEN_SIZE];
} Token;