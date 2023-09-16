#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"

typedef struct poly {
    
    term_t* terms;
    struct poly* next;
} poly_t;




poly_t * new_polynomial();
void print_polynomial(const poly_t* poly);
void add_to_polynomial(poly_t* poly, const term_t* term);
void combine_like_terms(const poly_t* poly);
void delete_polynomial(poly_t** poly);


#endif