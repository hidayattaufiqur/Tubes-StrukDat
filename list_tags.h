#ifndef LIST_TAGS_H_INCLUDED
#define LIST_TAGS_H_INCLUDED

#include <iostream>
using namespace std;

#define info(p) p->info
#define next(p) p->next
#define first(L) L.first

typedef string infotype;
typedef struct elmListTag *adrTag;

struct elmListTag {
    infotype info;
    adrTag next;
};

struct listTag {
    adrTag first;
};

void createList(listTag &L);
adrTag allocateTag(infotype tag);
void inputAndAllocate(adrTag &P);
void insertLast(listTag &L, adrTag P);
void deleteByTag(listTag &L, infotype tag, adrTag &P);
void deleteFirst(listTag &L, adrTag &P);
void deleteLast(listTag &L, adrTag &P);
void showTag(listTag L);
adrTag findTag(listTag L, string tag);


#endif // LIST_TAGS_H_INCLUDED
