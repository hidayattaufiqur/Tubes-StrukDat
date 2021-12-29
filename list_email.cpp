#include "list_email.h"

void createList(listEmail &L) {
    first(L) = NULL;
    last(L) = NULL;
}

int countEmail(listEmail L) {
    adrEmail p = first(L);
    int cnt = 1;

    while (p != NULL) {
        cnt++;
        p = next(p);
    }

    return cnt;
}

adrEmail allocateEmail(string pengirim, string penerima, string subjek, string isi) {
    adrEmail P = new elmListEmail;

    info(P).emailID = NULL;
    info(P).pengirim = pengirim;
    info(P).penerima = penerima;
    info(P).subjek = subjek;
    info(P).isi = isi;
    next(P) = NULL;

    return P;
}

void inputAndAllocate(adrEmail &P) {
    string pengirim, penerima, subjek, isi;

    // input data email
    cout << "---------Input Email---------:" << endl;
    cout << "Pengirim : ";
    cin >> pengirim;

    cout << "Penerima : ";
    cin >> penerima;

    cin.get(); // clear '\n'

    cout << "Subjek   : ";
    getline(cin, subjek);

    cout << "Isi      : " << endl << "-> ";
    getline(cin, isi);
    cout << "------------------------------" << endl << endl;

    // alokasi alamat data email
    P = allocateEmail(pengirim, penerima, subjek, isi);
}

void insertLast(listEmail &L, adrEmail P) // 1. insert parent
{
    int ID = countEmail(L);
    info(P).emailID = ID;

    adrEmail Q = first(L);

    if (Q == NULL) {
        first(L) = P;
        last(L) = P;
        next(first(L)) = NULL;
    } else if (first(L) == last(L)) {
        Q = last(L);
        next(Q) = P;
        last(L) = P;
        next(next(Q)) = NULL;
    }
    else {
        Q = last(L);
        next(Q) = P;
        last(L) = P;
    }
}

void deleteEmailByID(listEmail &L, int emailID, adrEmail &P) {
    P = first(L);
    if (P == NULL) {
        cout << "List email kosong." << endl;
    } else {
        P = findEmail(L, emailID);

        if (P == NULL) {
            cout << "ID email tidak ditemukan." << endl;
        } else if (P == first(L)) {
            deleteFirst(L, P);
        } else if (P == last(L)) {
            deleteLast(L, P);
        } else {
            adrEmail Q = first(L);
            while (info(next(Q)).emailID != emailID) {
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
}

void deleteFirst(listEmail &L, adrEmail &P) // 2. delete parent
{
    P = first(L);
    if (P == NULL) {
        cout << "List email kosong." << endl;
    } else if (P == last(L)) {
        first(L) = NULL;
        last(L) = NULL;
    } else {
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(listEmail &L, adrEmail &P) // 2. delete parent
{
    P = last(L);
    if (P == NULL) {
        cout << "List email kosong." << endl;
    } else if (P == first(L)) {
        first(L) = NULL;
        last(L) = NULL;
    } else {
        adrEmail Q = first(L);
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
        last(L) = Q;
        next(Q) = NULL;
    }
}

void deleteAfter(listEmail &L, adrEmail prec, adrEmail &P) {
    P = next(prec);
    next(prec) = next(P);
    next(P) = NULL;
}

void showEmail(listEmail L)  // 3. show parent
{
    adrEmail P = first(L);
    cout << "----------All Emails-----------" << endl;

    while (P != NULL) {
        cout << "ID: " <<info(P).emailID << endl;
        cout << "Pengirim Email : " << info(P).pengirim << endl;
        cout << "Penerima Email : " << info(P).penerima << endl;
        cout << "Subjek Email   : " << info(P).subjek << endl;
        cout << "Isi Email      : " << endl << "-> " << info(P).isi << endl << endl;
        P = next(P);
    }
    cout << "-------------------------------" << endl << endl;
}

adrEmail findEmail(listEmail L, int emailID) // 4. find parent
{
    adrEmail p = first(L);
    while (p != NULL && info(p).emailID != emailID) {
        p = next(p);
    }

    if (p != NULL) {
        return p;
    }

    return NULL;
}
