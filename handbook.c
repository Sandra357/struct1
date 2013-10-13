#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "handbook.h"

struct Node {
    struct Record record;
    struct Node *next;
};

struct List {
    struct Node *root;
};

struct List *list_create()
{
    struct List *list;

    list = malloc(sizeof(struct List));
    list->root = NULL;

    return list;
}

/*
 *Add new element in a list with sorting. Function take a pointer to pointer to top of the list.
*/
void list_add (struct List *list, struct Record *record)
{
    struct Node *new_el;
    struct Node *new_next = NULL;
    struct Node *cur;

    new_el = malloc(sizeof(struct Node));

    assert(new_el && "Memory failure");

    new_el->next = NULL;

    new_el->record = *record;

    if (list->root == NULL) {
        list->root = new_el;
        return;
    }

    if (list->root->record.age > new_el->record.age) {
        new_el->next = list->root;
        list->root = new_el;
        return;
    }

    cur = list->root;

    while (cur->next != NULL && new_el->record.age > cur->record.age)
        cur = cur->next;

    new_next = cur->next;
    cur->next = new_el;
    new_el->next = new_next;
}


/*
 *Search an element by name. Function take a pointer to pointer to top of the list.
*/
struct Record *list_search_by_name(struct List *list, const char *name)
{
    assert(list && "list should not be null");
    struct Node *now;
    now = list->root;
    while (now && strcmp(now->record.fio, name))
        now = now->next;
    return now ? &now->record : NULL;
}

/*
 *Search an element by age. Function take a pointer to pointer to top of the list.
*/
struct Record *list_search_by_age(struct List *list, int age)
{
    assert(list && "list should not be null");
    struct Node *now;
    now = list->root;
    while (now && now->record.age != age)
        now = now->next;
    return now ? &now->record : NULL;
}

/*
 *Display the list of names. Function take a pointer to top of the list.
*/
void list_display(struct List *list)
{
    assert(list && "list should not be null");
    struct Node *now;

    now = list->root;
    if (!now) {
        printf("This list is empty\n");
        return;
    }
    while(now) {
        record_display(&now->record);
        now = now->next;
    }
}


void record_display(struct Record *record)
{
    assert(record && "null record!");
    printf("********\n");
    printf("FIO: %s\n", record->fio);
    printf("Age: %d\n", record->age);
}
