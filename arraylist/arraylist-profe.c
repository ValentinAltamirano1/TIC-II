#include <stdio.h>
#include <string.h>
#include "arraylist.h"
#include "wrappers.h"

struct arrayList *
new_arrayList(unsigned int allocatedQty) {
    // creates an empty arrayList of allocatedQty pointers

    struct arrayList *list;

    list = (struct arrayList *) malloc_or_exit(sizeof(struct arrayList));
    list->allocatedQty = allocatedQty;
    list->arrayStart = (struct element **) malloc_or_exit(allocatedQty * sizeof(struct element *));
    list->usedQty = 0;
    return list;
}

void
grow_arrayList(struct arrayList *list) {
    // doubles the size of arrayList

    if (list == NULL) return;

    list->allocatedQty *= 2;
    list->arrayStart = (struct element **) realloc_or_exit(list->arrayStart, 
                            list->allocatedQty * sizeof(struct element *));
}


struct element *
append_string(struct arrayList *list, char *string) {
    // appends string at last position of list
    // returns pointer to new element or NULL in case of errors

    if (list == NULL || string == NULL) {
        return NULL;
    }
    return insert_string(list, string, list->usedQty);
}

void
print_element(struct element *e) {
    // prints element fields - custom function for testing purposes
    if (e == NULL) {
        printf("NULL element!!!\n");
        return;
    }
    printf("%5d '%s'\n", e->len, e->str);
}

void
print_arrayList(struct arrayList *list) {
    // prints all element in list - custom function for testing purposes

    if (list == NULL) {
        return;
    }
    
    for (unsigned int i=0; i < list->usedQty; i++) {
        printf("%5d: ", i+1);
        print_element(list->arrayStart[i]);
    }
}
