#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
using namespace std;
#include "list_email.h"
#include "list_tags.h"

#define email(p) p->email
#define tag(p) p->tag
#define next(p) p->next
#define first(L) L.first

typedef struct elmListRelasi *adrRelasi;

struct elmListRelasi {
    adrEmail email;
    adrTag tag;
    adrRelasi next;
};

struct listRelasi {
    adrRelasi first;
};

void createList(listRelasi &Lr);
adrRelasi allocateRelation(adrEmail email, adrTag tag);
void insertLast(listRelasi &L, adrRelasi P);
void deleteFirst(listRelasi &L, adrRelasi &P);
void deleteLast(listRelasi &L, adrRelasi &P);
void insertTagOfEmail(listRelasi &Lr, adrEmail email, adrTag tag); // 5. insert child of parent X
void deleteTagOfEmail(listRelasi &Lr, adrEmail email, adrTag tag, adrRelasi &P); // 6. delete child of parent X
void showTagOfEmail(listRelasi &Lr, adrRelasi P); // 7. show child of parent X
void findTagOfEmail();
void addRelation(listRelasi &Lr, listEmail Le, listTag Lt);
void deleteRelation(listRelasi &Lr, listEmail Le, listTag Lt, adrRelasi &P);
void showEmailsOfTag(listRelasi Lr); // 11a. show emails by tag X
void countEmailsOfSender(listRelasi Lr); // 11b. count emails from sender X with tag X
void showAllRelation(listRelasi Lr);
void showRelationOfEmail(listRelasi Lr, listEmail Le, int emailID);


#endif // LIST_RELASI_H_INCLUDED
