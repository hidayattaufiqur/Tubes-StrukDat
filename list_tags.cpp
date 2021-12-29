#include "list_tags.h"

void createList(listTag &L) {
    first(L) = NULL;
}

adrTag allocateTag(infotype tag) {
    adrTag P = new elmListTag;
    info(P) = tag;
    next(P) = NULL;

    return P;
}

void inputAndAllocate(adrTag &P) {
    string tag;

    // input tag
    cout << "-----------Input Tag-----------" << endl;
    cout << "Nama Tag : ";
    cin >> tag;
    cout << "-------------------------------" << endl << endl;

    // alokasi alamat data tag
    P = allocateTag(tag);
}

void insertLast(listTag &L, adrTag P) {
    adrTag Q = first(L);

    if (Q == NULL) {
        first(L) = P;
        next(first(L)) = NULL;
    } else if (next(first(L)) == NULL) {
        next(Q) = P;
        next(next(Q)) = NULL;
    }
    else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteByTag(listTag &L, infotype tag, adrTag &P) {
    P = first(L);
    if (P == NULL) {
        cout << "List tag kosong." << endl;
    } else {
        P = findTag(L, tag);

        if (P == NULL) {
            cout << "Tag tidak ditemukan." << endl;
        } else if (P == first(L)) {
            deleteFirst(L, P);
        } else {
            adrTag Q = first(L);
            while (info(next(Q))!= tag) {
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
}

void deleteFirst(listTag &L, adrTag &P) {
    P = first(L);
    if (P == NULL) {
        cout << "List tag kosong." << endl;
    } else if (next(P) == NULL) {
        first(L) = NULL;
    } else {
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(listTag &L, adrTag &P) {
    P = first(L);
    if (P == NULL) {
        cout << "List tag kosong." << endl;
    } else if (next(P) == NULL) {
        first(L) = NULL;
    } else {
        while (next(next(P)) != NULL) {
            P = next(P);
        }
        next(P) = NULL;
    }
}

void showTag(listTag L) {
    adrTag P = first(L);
    cout << "-----------All Tags------------" << endl;

    while (P != NULL) {
        cout << "Tag : " << info(P) << endl;
        P = next(P);
    }
    cout << "-------------------------------" << endl << endl;
}

adrTag findTag(listTag L, string tag) {
    adrTag p = first(L);
    while (p != NULL && info(p)!= tag) {
        p = next(p);
    }

    if (p != NULL) {
        return p;
    }

    return NULL;
}
