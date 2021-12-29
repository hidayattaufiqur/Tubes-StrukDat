#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

#include <iostream>
using namespace std;

#define info(p) p->info
#define next(p) p->next
#define first(L) L.first
#define last(L) L.last

typedef struct elmListEmail *adrEmail;

struct email {
    int emailID;
    string pengirim;
    string penerima;
    string subjek;
    string isi;
};

struct elmListEmail {
    email info;
    adrEmail next;
};

struct listEmail {
    adrEmail first;
    adrEmail last;
};

void createList(listEmail &L);
int countEmail(listEmail L);
adrEmail allocateEmail(string pengirim, string penerima, string subjek, string isi);
void inputAndAllocate(adrEmail &P);
void insertLast(listEmail &L, adrEmail P); // 1. insert parent
void deleteEmailByID(listEmail &L, int emailID, adrEmail &P);
void deleteFirst(listEmail &L, adrEmail &P); // 2. delete parent
void deleteLast(listEmail &L, adrEmail &P); // 2. delete parent
void deleteAfter(listEmail &L, adrEmail prec, adrEmail &P);
void showEmail(listEmail L); // 3. show parent
adrEmail findEmail(listEmail L, int emailID); // 4. find parent

#endif // EMAIL_H_INCLUDED
