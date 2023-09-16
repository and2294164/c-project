#ifndef TERM_H
#define TERM_H

typedef struct term {
    int coeff;
    char var;
    int exp;
} term_t;


char* term_to_string(const term_t* term);
//int term_char_length(term_t* term);

#endif
