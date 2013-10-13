#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <handbook.h>

int main()
{
    int num;
    int exit = 0;
    struct handbook *beg = NULL;

    do {
        printf("Hello! Enter 1 if you want to watch a handbook,"
               "2 - if you want to add an element, "
               "3 - if you want to search an element by name, "
               "4 - if you want to search an element by age, "
               "5-if you want to exit\n");
        scanf ("%d", &num);

        switch (num) {
        case 1:
            display (beg);
            break;

        case 2:
            add (&beg);
            break;

        case 3:
            search_by_name(&beg);
            break;

        case 4:
            search_by_age(&beg);
            break;


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







