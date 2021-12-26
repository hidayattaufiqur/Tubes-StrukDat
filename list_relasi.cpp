#include "list_relasi.h"

void createList(listRelasi &Lr) {
    first(Lr) = NULL;
}

adrRelasi allocateRelation(adrEmail email, adrTag tag) {
    adrRelasi R = new elmListRelasi;

    email(R) = email;
    tag(R) = tag;
    next(R) = NULL;

    return R;
}

void insertLast(listRelasi &L, adrRelasi P) {
    adrRelasi Q = first(L);

    if (Q == NULL) {
        first(L) = P;
        next(first(L)) = NULL;
    } else if (next(first(L)) == NULL) {
        next(Q) = P;
        next(next(Q)) = NULL;
    }
    else {
        while (Q != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirst(listRelasi &L, adrRelasi &P) {
    P = first(L);
    if (P == NULL) {
        cout << "List relasi kosong." << endl;
    } else if (next(P) == NULL) {
        first(L) = NULL;
        email(P) = NULL;
        tag(P) = NULL;
    } else {
        first(L) = next(P);
        email(P) = NULL;
        tag(P) = NULL;
        next(P) = NULL;
    }
}

void deleteLast(listRelasi &L, adrRelasi &P) {
    P = first(L);
    if (P == NULL) {
        cout << "List relasi kosong." << endl;
    } else if (next(P) == NULL) {
        first(L) = NULL;
        email(P) = NULL;
        tag(P) = NULL;
    } else {
        while (next(next(P)) != NULL) {
            P = next(P);
        }
        email(P) = NULL;
        tag(P) = NULL;
        next(P) = NULL;
    }
}

void insertTagOfEmail(listRelasi &Lr, adrEmail email, adrTag tag) // 5. insert child of parent X
{
    adrRelasi R;

    R = allocateRelation(email, tag);
    insertLast(Lr, R);
}

void deleteTagOfEmail(listRelasi &Lr, adrEmail email, adrTag tag, adrRelasi &P) // 6. delete child of parent X
{
    P = first(Lr);

    if (P != NULL) {
        if (next(P) == NULL) {
            deleteFirst(Lr, P);
        } else {
            while(email(next(P)) != email && tag(next(P)) != tag && next(P) != NULL) {
                P = next(P);
            }
            email(next(P)) = NULL;
            tag(next(P)) = NULL;
            next(next(P)) = NULL;
            next(P) = next(next(P));
        }
    } else {
        cout << "List relasi kosong." << endl;
    }
}

void showTagOfEmail(listRelasi &Lr, adrRelasi P); // 7. show child of parent X

void addRelation(listRelasi &Lr, listEmail Le, listTag Lt) {
    int ID;
    string tag;

    showEmail(Le);
    showTag(Lt);
    cout << "Buat relasi untuk email ID: ";
    cin >> ID;

    cout << "Dengan Tag: ";
    cin >> tag;

    adrEmail E = findEmail(Le, ID);
    adrTag T = findTag(Lt, tag);

    if (E == NULL) {
        cout << "ID email tidak ditemukan." << endl;
    }
    if (T == NULL) {
        cout << "Tag tidak ditemukan." << endl;
    }
    if (E != NULL && T != NULL) {
        insertTagOfEmail(Lr, E, T);
    }

}

void deleteRelation(listRelasi &Lr, listEmail Le, listTag Lt, adrRelasi &P) {
    int ID;
    string tag;

    showEmail(Le);
    showTag(Lt);
    cout << "Hapus relasi untuk email ID: ";
    cin >> ID;

    cout << "Dengan Tag: ";
    cin >> tag;

    adrEmail E = findEmail(Le, ID);
    adrTag T = findTag(Lt, tag);

    if (E == NULL) {
        cout << "ID email tidak ditemukan." << endl;
    }
    if (T == NULL) {
        cout << "Tag tidak ditemukan." << endl;
    }
    if (E != NULL && T != NULL) {
        deleteTagOfEmail(Lr, E, T, P);
    }
}

void showEmailsOfTag(listRelasi Lr); // 11a. show emails by tag X
void countEmailsOfSender(listRelasi Lr); // 11b. count emails from sender X with tag X

void showAllRelation(listRelasi Lr) {
    adrRelasi R = first(Lr);
    while (R != NULL) {
        cout << "ID: " << info(email(R)).emailID << endl;
        cout << "Pengirim Email : " << info(email(R)).emailID << endl;
        cout << "Penerima Email : " << info(email(R)).penerima << endl;
        cout << "Subjek Email   : " << info(email(R)).subjek << endl;
        cout << "Isi Email      : " << endl << "-> " << info(email(R)).isi << endl;
        cout << "Tag Email      : " << info(tag(R)) << endl;

        cout << "------------------------------" << endl;

        R = next(R);
    }
}
