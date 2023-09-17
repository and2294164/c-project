#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "polynomial.h"
#include "term.h"

poly_t * new_polynomial() {

    poly_t* poly = malloc(sizeof(poly_t));
    poly->terms = NULL;
    return poly;
}

void print_polynomial(const poly_t* poly) {

    poly_t* curr = new_polynomial();
    curr->terms = poly->terms;

    if(curr->terms != NULL) {

        while(curr->terms != NULL) {

            print_poly_terms(curr);
            curr->terms = curr->terms->next;
        }
        printf("the polynomial's order is: %d\n", poly->order);
    }
    else {
        printf("polynomial is empty.");
    }
    printf("\n");
    free(curr);
}

void add_to_polynomial(poly_t* poly, const term_t* term) {
    
    if(term->coeff != 0) {
        list_add(&(poly->terms), term);
        update_order(poly, term);
    }
}

void combine_like_terms(const poly_t* poly) {
    // returns a new polynomial which is the result of combining
    // the like terms in the parameter poly

    int count = 0;
    term_t* tempterm = ((term_t*) poly->terms->data);
    poly_t* curr = new_polynomial();
    curr->terms = poly->terms;

    if(curr->terms != NULL) {

        while(curr->terms != NULL) {
            while(curr->terms != NULL) {

                if ( tempterm->var == get_term(poly)->var
                && tempterm->exp == get_term(poly)->exp ) {

                    get_term(poly)->coeff += tempterm->coeff;
                }
                curr->terms = curr->terms->next;
            }
            count++;
            curr->terms = poly->terms;

            for(int i = 0; i < count; i++) {
                tempterm = (term_t*) curr->terms->next;
            }

        }
    }
    else {
        printf("polynomial is empty");
    }
    printf("\n");
    free(curr);
}

void delete_polynomial(poly_t** poly) {
    
    free(poly);
}

/* Extra functions created to increase readability */

bool is_last_term(poly_t* poly) {

    bool last_term = false;

    if(poly->terms->next == NULL) last_term = true;
    return last_term;
}

term_t* get_term(const poly_t* poly) {

    return (term_t*) poly->terms->data;
}

void update_order(poly_t* poly, const term_t* term) {

    if(term->exp > poly->order) poly->order = term->exp;
}

void print_poly_terms(poly_t* curr) {

    if(!is_last_term(curr)) {
        printf("%s + ", term_to_string( (term_t*) (curr->terms->data) ));
    }
    else {
        printf("%s\n", term_to_string( (term_t*) (curr->terms->data) ));
    }
}