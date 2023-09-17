#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"term.h"
#include"polynomial.h"
#include"basiclist.h"

#define BUFFERLEN 100

/* Parses a string into a term data structure */
term_t * string_to_term(char * buff) {
    term_t * ret = malloc(sizeof(term_t));
    ret->coeff=atoi(strtok(buff, " "));
    ret->var=*strtok(NULL, " ");
    ret->exp=atoi(strtok(NULL, " "));
    return ret;
}

/* Reads a text file and addds terms to a basiclist */
void read_terms_from_file(node_t ** term_list) {

    FILE *fp;
    char buffer[BUFFERLEN];

    if ( (fp = fopen("terms.txt", "r")) == NULL) {
        fprintf(stderr, "\nERROR: Missing terms.txt\n\n");
        exit(-1);
    }

    while (fgets(buffer, BUFFERLEN,fp)) {
        /* The following case ensures we aren't reading an empty line */
        if (buffer[0] < '0' || buffer[0] > '9') {
            continue;
        }

        term_t * this_term;
        this_term =  string_to_term(buffer);
        list_add(term_list, this_term);
    }
    fclose(fp);
}

int main(void) {
    const term_t testterm1 = {1, 'x', 0};
    const term_t testterm2 = {2, 'x', 1};
    const term_t testterm3 = {3, 'x', 2};

    poly_t * poly1 = new_polynomial();
    poly_t * poly2 = new_polynomial();
    node_t * curr;

    /* Read terms into term_list */
    node_t * term_list = NULL;
    read_terms_from_file(&term_list);

    /* Test term code */
    printf("NAME: Andrew Bohata\n");
    printf("Testing term.c/h:\n");
    printf("testterm1: %s\n", term_to_string(&testterm1));
    printf("testterm2: %s\n", term_to_string(&testterm2));
    printf("testterm3: %s\n", term_to_string(&testterm3));

    printf("Initial list:\n");

    /* adding terms to the polynomials*/
    curr = term_list;
    while (curr!=NULL) {
        
        add_to_polynomial(poly1, (term_t*) curr->data);
        curr = curr->next;
    }
    /*
    add_to_polynomial(poly2, &testterm1);
    add_to_polynomial(poly2, &testterm2);
    add_to_polynomial(poly2, &testterm3);
    */

    /* Polynomial test code */
    printf("\nTesting polynomial.c/h : \n");
    printf("poly1: ");
    print_polynomial(poly1);
    //printf("poly2: ");
    //print_polynomial(poly2);
    

    
    poly2 = combine_like_terms(poly1);
    printf("\nCombined: : ");
    print_polynomial(poly2);
    printf("\nNAME: Andrew Bohata\n");
    

    return 0;
}
