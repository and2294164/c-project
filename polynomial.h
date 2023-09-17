#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdbool.h>
#include "term.h"
#include "basiclist.h"

typedef struct poly {
    
    int order;              // stores the largest exponent
    node_t* terms;          // pointer to a basiclist that stores term_t objects
} poly_t;




poly_t * new_polynomial();
void print_polynomial(const poly_t* poly);
void add_to_polynomial(poly_t* poly, const term_t* term);
void combine_like_terms(const poly_t* poly);
void delete_polynomial(poly_t** poly);
/* extra functions added to increase readability*/

term_t* get_term(const poly_t*);
bool is_last_term(poly_t*);
void update_order(poly_t*, const term_t*);
void print_poly_terms(poly_t* curr);


#endif