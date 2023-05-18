#include <stdio.h>
#include <string.h>
#include "arraylist.h"
#include "wrappers.h"

#define INITIAL_QTY 5              // initial allocation of arrayList

int
main(void) {
    struct arrayList *list;
    struct element *e;

    char *input_strings[] = {
        "uno",
        "dos",
        "tres",
        "cuatro",
        "cinco",
        "seis",
        NULL
    };

    list = new_arrayList(INITIAL_QTY);

    printf("Test 1 - print empty list\n");
    printf("Empty list\n");
    print_arrayList(list);


    printf("Test 2 - populate and print a list\n");
    for (int i =0; input_strings[i] != NULL; i++) {
        e = append_string(list, input_strings[i]);
        printf("Appended element.\n");
        print_element(e);
    }
    printf("Non empty list\n");
    print_arrayList(list);


    printf("Test 3 - pop element\n");
    e = pop_element(list);
    printf("Popped element --> ");
    print_element(e);
    delete_element(e);
    printf("After popping from list\n");
    print_arrayList(list);

    printf("Test 4 - remove first element\n");
    e = remove_element(list, 0);
    printf("Removed element 0 --> ");
    print_element(e);
    delete_element(e);
    printf("After removing first from list\n");
    print_arrayList(list);

    printf("Test 5 - remove second element\n");
    e = remove_element(list, 1);
    printf("Removed second element --> ");
    print_element(e);
    delete_element(e);
    printf("After removing second from list\n");
    print_arrayList(list);


    printf("Test 6 - remove element that does not exist\n");
    e = remove_element(list, 5);
    printf("Removed element 5 --> ");
    print_element(e);
    delete_element(e);
    printf("After removing from list\n");
    print_arrayList(list);

    printf("Test 7 - remove element by search key (existent)\n");
    e = search_remove_element(list, "cuatro");
    printf("Removed element 'cuatro' --> ");
    print_element(e);
    delete_element(e);
    printf("After removing from list\n");
    print_arrayList(list);

    printf("Test 8 - remove element by search key (nonexistent)\n");
    e = search_remove_element(list, "ocho");
    printf("Removed element 'ocho' --> ");
    print_element(e);
    delete_element(e);
    printf("After removing from list\n");
    print_arrayList(list);

    printf("Test 9 - insert new first element\n");
    e = insert_string(list, "new first element", 0);
    printf("After inserting first\n");
    print_arrayList(list);

    printf("BYE BYE\n");

    exit(EXIT_SUCCESS);

}
