#ifndef HANDBOOK_H
#define HANDBOOK_H

struct Record {
    char fio[20];
    int age;
};

struct List;

void record_display(struct Record* record);
struct List *list_create();
void list_add(struct List* list, struct Record* record);
struct Record* list_search_by_name(struct List* list, const char *name);
struct Record* list_search_by_age (struct List* list, int age);
void list_display(struct List* list);



#endif // HANDBOOK_H
