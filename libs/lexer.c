#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_NUMBER, 
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char* value;
} Token;

const char *keywords[] = {"if", "else", "while", "for", NULL};



int lexer(char *src_ptr) {
    // Lexer implementation goes here
    
}

Token tokenize(const char** src_ptr){
    const char *current_token = *src_ptr;
    Token token;

    while (isspace(*current_token)){
        current_token++;
    }

    if (*current_token == '\0'){
        token.type = TOKEN_EOF;
        token.value = NULL;
    }

    if (isalpha(*current_token) || *current_token == '_'){
        int len = 0;
        const char *start = current_token;
        while (isalnum(*current_token) || *current_token == '_'){
            current_token++;
            len++;
        }
        token.value = (char*)malloc(len+1);
        strncpy(token.value, start, len);
        token.value[len] = '\0';
        
        int iskeyword = 0;

        for (int i = 0; keywords[i] != NULL; i++){
            if (strcmp(token.value, keywords[i]) == 0){
                token.type = TOKEN_KEYWORD;
                iskeyword = 1;
                break;
            } else{
                token.type = TOKEN_IDENTIFIER;
            }
        }
    } else if (isdigit(*current_token)){
        int len = 0;
        const char *start = current_token;
        while (isdigit(*current_token)){
            len++;
        }
        token.value = (char *)malloc(len+1);
        strncpy(token.value, start, len);
        token.value[len] = '\0';
    } else{
        token.type = TOKEN_EOF;
        token.value = NULL;
    }
    *src_ptr = current_token;
    return token;
    
}

void parser() {
    // Parser implementation goes here
}