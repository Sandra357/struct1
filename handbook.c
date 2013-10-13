#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <handbook.h>

struct handbook {
    char fio[20];
    int age;
    struct handbook *next;
};

/*
 *Add new element in a list with sorting. Function take a pointer to pointer to top of the list.
*/
void add (struct handbook** beg)
{
    struct handbook *new_el;
    struct handbook *new_next = NULL;
    struct handbook *cur;

    new_el = malloc(sizeof(struct handbook));

    if(!new_el) {
        printf("Failed malloc\n");
        return;
    }

    new_el->next = NULL;

    printf("Enter FIO: \n");
    scanf("%s", &new_el->fio[0]);
    printf("Enter age: \n");
    scanf("%d", &new_el->age);

    if (*beg == NULL) {
        *beg = new_el;
        (*beg)->next = NULL;
        return;
    }

    if ((*beg)->age > new_el->age) {
        new_el->next = *beg;
        *beg = new_el;

        return;
    }

    cur = *beg;

    while (cur->next != NULL && new_el->age > cur->age)
        cur = cur->next;

    new_next = cur->next;
    cur->next = new_el;
    new_el->next = new_next;
}

/*
 *Display the list of names. Function take a pointer to top of the list.
*/
void display(struct handbook *start)
{
    if (!start) {
        printf("Bad param 'start'\n");

        return;
    }
    while(start) {
        printf("********\n");
        printf("FIO: %s\n", start->fio);
        printf("Age: %d\n", start->age);

        start = start->next;
    }
}

/*
 *Search an element by name. Function take a pointer to pointer to top of the list.
*/
void search_by_name(struct handbook **beg)
{
    struct handbook *s_el = malloc(sizeof(struct handbook));
    struct handbook *now;

    now = *beg;
    printf("Enter a name. \n");
    scanf("%s", s_el->fio);

    while (strcmp(now->fio, s_el->fio))
        now = now->next;

    printf("Age of this user is %d",now->age);
    printf("\n");
}

/*
 *Search an element by age. Function take a pointer to pointer to top of the list.
*/
void search_by_age (struct handbook **beg)
{
    int s_el;
    struct handbook *now;

    now = *beg;
    printf("Enter an age. \n");
    scanf("%d", &s_el);

    while (now->age != s_el)
        now = now->next;

    printf("Name of this user is %s",now->fio);
    printf("\n");
}


