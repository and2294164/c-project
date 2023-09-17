#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "term.h"

char* term_to_string(const term_t* term) {

    int count = 4;      // keeps track of how many chars long the string is.
                        // min is 4 because coeff+var+^+exp.

    if( (term->coeff / 10) >= 1 ) {

        int temp = term->coeff;

        while(temp / 10 >= 1) {
            temp /= 10;
            count++;
        }
    }

    if ( (term->exp / 10) >= 1) {

        int temp = term->exp;

        while(temp / 10 >= 1) {
            temp /= 10;
            count++;
        }
    }

    char* termstr = malloc(count * sizeof(char));
    sprintf(termstr, "%d%c^%d", term->coeff, term->var, term->exp);

    return termstr;
}

// FIXME: make this into its own function?
/*int term_char_length(const term_t* term) {
    
    int count = 4;      // keeps track of how many chars long the string is.
                        // min is 4 because coeff+var+^+exp.

    if( (term->coeff / 10) >= 1 ) {

        int temp = term->coeff;

        while(temp / 10 >= 1) {
            temp /= 10;
            count++;
        }
    }

    if ( (term->exp / 10) >= 1) {

        int temp = term->exp;

        while(temp / 10 >= 1) {
            temp /= 10;
            count++;
        }
    }
    return count;
}*/

/*
int main(void) {

    const term_t term1 = {3, 'x', 2};
    const term_t term2 = {40, 'c', 7};
    const term_t term3 = {4, 'x', 70};

    printf("Terms:\n");
    printf("term1: %s, length: %ld\n", term_to_string(&term1), 
                        strlen(term_to_string(&term1)) );
    printf("term1: %s, length: %ld\n", term_to_string(&term2), 
                        strlen(term_to_string(&term2)) );
    printf("term1: %s, length: %ld\n", term_to_string(&term3), 
                        strlen(term_to_string(&term3)) );


}*/

