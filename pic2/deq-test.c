/*
 * deq-test.c
 *
 * tests the implementation of deq.c
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "wrappers.h"
#include "deq.h"

#define MAXLINE 1024


int
main(void)
{
    char line[MAXLINE];
    struct deq *my_deq1;
    struct deq *my_deq2;
    struct deq_elem *my_elem;

    my_deq1 = deq_create();
    my_deq2 = deq_create();

    while (fgets(line, MAXLINE, stdin) != NULL) {
        if (deq_append(my_deq1, line) == NULL) {
            fprintf(stderr, "deq_append error processing '%s'\n", line);
        }
        if (deq_append_left(my_deq2, line) == NULL) {
            fprintf(stderr, "deq_append_left error processing '%s'\n", line);
        }
    }
    fprintf(stderr, "deq1 count is %d (should match number of lines in file)\n", my_deq1->count);
    fprintf(stderr, "deq2 count is %d (should match number of lines in file)\n", my_deq2->count);

    fprintf(stderr, "deq_print of file appended to the right (should match input)\n");
    deq_print(my_deq1);
    fprintf(stderr, "deq_print of file appended to the left (should reverse input)\n");
    deq_print(my_deq2);

    fprintf(stderr, "deq_pop_left print of file appended to the right (should match input)\n");
    while (my_deq1->count > 0) {
        my_elem = deq_pop_left(my_deq1);
        printf("%s", my_elem->str);
        free(my_elem->str);
        free(my_elem);
    }

    fprintf(stderr, "deq_pop print of file appended to the left (should match input)\n");
    while (my_deq2->count > 0) {
        my_elem = deq_pop(my_deq2);
        printf("%s", my_elem->str);
        free(my_elem->str);
        free(my_elem);
    }

    exit(EXIT_SUCCESS);
}
