#ifndef HANDBOOK_H
#define HANDBOOK_H

struct handbook;
void add (struct handbook**);
void display(struct handbook*);
void search_by_name(struct handbook**);
void search_by_age (struct handbook**);

#endif // HANDBOOK_H
