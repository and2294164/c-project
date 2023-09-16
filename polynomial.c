#include "polynomial.h"
#include "term.h"

poly_t * new_polynomial() {

    poly_t* poly = malloc(sizeof(poly_t));
    return poly;
}

void print_polynomial(const poly_t* poly) {
    // print the polynomial
}

void add_to_polynomial(poly_t* poly, const term_t* term) {
    // add a term to the polynomial
}

void combine_like_terms(const poly_t* poly) {
    // returns a new polynomial which is the result of combining
    // the like terms in the parameter poly
}

void delete_polynomial(poly_t** poly) {
    // frees memory allocated for a polynomial
}