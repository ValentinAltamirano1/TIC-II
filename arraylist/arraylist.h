// arraylist.h

struct arrayList {
    unsigned int allocatedQty;      // the quantity of mallocated pointers to elements
    struct element **arrayStart;    // points to first position of the array
    unsigned int usedQty;           // how many elements (pointers) are used
};

struct element {
    char *str;                      // the stored string
    unsigned int len;               // the length of the stored string
};

struct arrayList *
new_arrayList(unsigned int allocatedQty);
    // creates an empty arrayList of allocatedQty pointers

void
grow_arrayList(struct arrayList *list);
    // doubles the size of arrayList

struct element *
new_element(char *string);
    // creates new element object, returns pointer


void
delete_element(struct element *e);
    // deletes e element object

struct element *
insert_string(struct arrayList *list, char *string, unsigned int position);
    // insert string at 'position' of list
    // returns pointer to new element or NULL in case of errors

struct element *
append_string(struct arrayList *list, char *string);
    // appends string at last position of list
    // returns pointer to new element or NULL in case of errors

struct element *
remove_element(struct arrayList *list, unsigned int position);
    // removes element at 'position' of list
    // returns pointer to element removed or NULL

struct element *
search_remove_element(struct arrayList *list, char *search);                   
    // removes first element whose str member is equal to 'search'
    // returns pointer to element removed or NULL if not found

struct element *
pop_element(struct arrayList *list);               
    // pops element at last position of list
    // returns pointer to element popped or NULL

void
print_element(struct element *e);
    // prints element fields - custom function for testing purposes

void
print_arrayList(struct arrayList *list);
    // prints all element in list - custom function for testing purposes
