#include <stdio.h>
#include <string.h>

#include "arraylist.h"
#include "wrappers.h"

struct element *new_element(char *string) 
{
    // creates new element object, returns pointer
    struct element *new_element = (struct element*) malloc_or_exit(sizeof(struct element));
    new_element->str = strdup_or_exit(string);
    new_element->len = strlen(string);

    return new_element;
}

void delete_element(struct element *e) 
{
    // deletes an element object and free's all mallocated space
    if (e == NULL) return;

    free(e->str); //str_dup has a malloc, so first free malloc of str
    free(e); //free malloc of element
}

struct element *insert_string(struct arrayList *list, char *string, unsigned int position) 
{
    // insert string at 'position' of list
    // returns pointer to new element or NULL in case of errors
    if (list == NULL || string == NULL){
        return NULL;
    }

    if(list->usedQty >= list->allocatedQty){
        grow_arrayList(list);
    }

    /*if(list->usedQty >= list->allocatedQty){
        return NULL; //grow_arrayList failed
    }

    if (list->usedQty <= position) {
        return NULL;
    }*/

    for (unsigned int i = list->usedQty; i > position; i--) {
        list->arrayStart[i+1] = list->arrayStart[i];
        /*if (i == position) {
            list->arrayStart[i] = new_element(string);
            list->usedQty++;
            return list->arrayStart[i];
        }*/
    }
    
    list->arrayStart[position] = new_element(string);
    list->usedQty++;
    return list->arrayStart[position];
}


struct element *remove_element(struct arrayList *list, unsigned int position) 
{                   
    // removes element at position of list
    // returns pointer to element removed or NULL
    if (list == NULL){
        return NULL;
    }

    if (list->usedQty <= position) {
        return NULL;
    }

    if (list->usedQty == 0) {
        return NULL;
    }

    //delete_element(list->arrayStart[position]);
    for (unsigned int i = position; i < list->usedQty-1; i++) {
        list->arrayStart[i] = list->arrayStart[i+1];
    }

    list->arrayStart[list->usedQty -1] = NULL;
    list->usedQty--;
    return list->arrayStart[position];
}

struct element *search_remove_element(struct arrayList *list, char *search) 
{                   
    // removes first element whose str member is equal to 'search'
    // returns pointer to element removed or NULL if not found
    if (list == NULL || search == NULL){
        return NULL;
    }

    for (unsigned int i = 0; i < list->usedQty; i++) {
        if(strcmp(list->arrayStart[i]->str,search) == 0){
            return remove_element(list, i);
        }
    }

    return NULL;    // not found
}

struct element *pop_element(struct arrayList *list) 
{                   
    // pops element at last position of list
    // returns pointer to element popped or NULL
    if (list == NULL){
        return NULL;
    }

    if (list->usedQty == 0) {
        return NULL;
    }

    return remove_element(list, list->usedQty-1);
}
