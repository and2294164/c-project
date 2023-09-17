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

poly_t* combine_like_terms(const poly_t* poly) {

    poly_t* curr = new_polynomial();
    term_t* term = get_term(poly);
    curr->terms = poly->terms;
    curr->order = poly->order;
    int count = 0;
    int max = num_of_terms(poly);
    printf("max: %d", max);

    node_t* curr_start = curr->terms;
    curr->terms = curr->terms->next;
    /*
    do {
        if(match_terms(curr, term)) {
            
            get_term(curr)->coeff += term->coeff; 
        }

        ;
        count++;
    } while(count != max);

    curr->terms = curr_start;*/
    return curr;
}

void delete_polynomial(poly_t** poly) {
    
    free(poly);
}

/* Extra functions created to increase readability / functionality */

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

int num_of_terms(const poly_t* poly) {

    int i = 0;
    poly_t* curr = new_polynomial();
    curr->terms = poly->terms;
    

    while(curr->terms != NULL) {
        
        curr->terms = curr->terms->next;
        i++;
    }
    free(curr);
    return i;
}

bool match_terms(poly_t* poly, term_t* term) {

    bool match = false;

    while(poly->terms != NULL) {

        if(get_term(poly)->exp == term->exp &&
            get_term(poly)->var == term->var) {

            match = true;
        }
        poly->terms = poly->terms->next;
    }
    return match;
}

void remove_term(poly_t* poly, int count) {

}