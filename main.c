#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <handbook.h>

#include "minunit.h"

// tests add 2 records and search by name and by age
static char *simple_test_1()
{
    struct List *list;
    struct Record record;
    struct Record *result_record;

    list = list_create();

    strcpy(record.fio, "Ivan");
    record.age = 33;
    list_add(list, &record);

    strcpy(record.fio, "Vasya");
    record.age = 42;
    list_add(list, &record);

    result_record = list_search_by_age(list, 192);
    mu_assert("error, found unknown record", result_record == NULL);

    result_record = list_search_by_age(list, 33);
    mu_assert("error, record_not_found", result_record != NULL);
    mu_assert("error, wrong fio", !strcmp(result_record->fio, "Ivan"));

    result_record = list_search_by_name(list, "Vasya");
    mu_assert("error, record_not_found", result_record != NULL);
    mu_assert("error, wrong age", result_record->age == 42);

    return 0;
}

// todo: write few more tests
// check sort order
// add few elements with same name but different age
// on search by name you'll get record with smallest age

static char * all_tests() {
    mu_run_test(simple_test_1);
    return 0;
}

void unit_test()
{
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
}


int main(int arg_c, char **arg_v)
{
    if (arg_c == 2 && !strcmp(arg_v[1], "-ut"))
    {
        unit_test();
        return 0;
    }

    int num;
    int exit = 0;
    struct List *list = NULL;

    list = list_create();

    do {
        printf("\nMenu:\n"
               "1 - if you want to watch a handbook,\n"
               "2 - if you want to add an element, \n"
               "3 - if you want to search an element by name, \n"
               "4 - if you want to search an element by age, \n"
               "5 - if you want to exit\n"
               "select > ");
        scanf ("%d", &num);

        switch (num) {
        case 1:
            list_display(list);
            break;

        case 2: {
            struct Record record;
            printf("Enter a name > ");
            scanf("%s", record.fio);
            printf("Enter an age > ");
            scanf("%d", &record.age);
            list_add(list, &record);
            break;
        }

        case 3: {
            char name[20];
            struct Record *record;
            printf("Enter a name > ");
            scanf("%s", name);
            record = list_search_by_name(list, name);
            if (!record) {
                printf("Nothing found!\n");
            } else {
                record_display(record);
            }
            break;
        }

        case 4: {
            int age;
            struct Record *record;
            printf("Enter an age > ");
            scanf("%d", &age);
            record =  list_search_by_age(list, age);
            if (!record) {
                printf("Nothing found!\n");
            } else {
                record_display(record);
            }
            break;
        }

        case 5:
            exit = 1;
            break;

        default:
            printf("%d - this is not a number \n", num);
            break;
        }
    }
    while (!exit);

    return 1;
}







