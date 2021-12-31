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
void deleteAfter(listRelasi &L, adrRelasi prec, adrRelasi &P);
void insertTagOfEmail(listRelasi &Lr, adrEmail email, adrTag tag); // 5. insert child of parent X
void deleteTagOfEmail(listRelasi &Lr, adrEmail email, adrTag tag, adrRelasi &P); // 6. delete child of parent X
void showTagOfEmail(listRelasi Lr, listEmail Le, int emailID); // 7. show child of parent X
/**
sudah tercover sama procedure showTagOfEmail
// adrTag findTagOfEmail(listRelasi Lr, listEmail Le, listTag Lt, int emailID); // 8. find child of parent X
*/
void addRelation(listRelasi &Lr, listEmail Le, listTag Lt); // 9. create relation between parent and child
void deleteRelation(listRelasi &Lr, listEmail Le, listTag Lt, adrRelasi &P); // 10. delete relation between parent and child
void showEmailWithMostTag(listRelasi Lr, listEmail Le); // 11a.show email with the most tags and how many tags it has
void deleteEmailsWithTag(listRelasi &Lr, listEmail &Le, listTag Lt, string tag); // 11b. show email with the most tags and how many tags it has
void showAllRelation(listRelasi Lr);
//void showEmailsOfTag(listRelasi Lr, listTag Lt, string tag); // 11a. show emails of tag X
//void countEmailsOfSender(listEmail Le, string email); // 11b. count emails from sender X

#endif // LIST_RELASI_H_INCLUDED
