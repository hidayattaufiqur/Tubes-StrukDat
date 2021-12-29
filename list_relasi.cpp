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
    } else {
        while (next(Q) != NULL) {
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
        email(next(P)) = NULL;
        tag(next(P)) = NULL;
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
    adrRelasi Q = first(Lr);
    if (Q != NULL) {
        if (next(Q) == NULL) {
            if (email(Q) == email && tag(Q) == tag) {
                deleteFirst(Lr, Q);
            } else {
                cout << "Email dengan tag 1'" << info(tag) << "' tidak ditemukan." << endl;
            }
        } else if (next(next(Q)) == NULL) {
            if (email(Q) == email && tag(Q) == tag) {
                deleteFirst(Lr, Q);
            } else if (email(next(Q)) == email && tag(next(Q)) == tag) {
                deleteLast(Lr, Q);
            } else {
                cout << "Email dengan tag 2'" << info(tag) << "' tidak ditemukan." << endl;
            }
        } else {
            while(next(Q) != NULL && email(next(Q)) != email && tag(next(Q)) != tag) {
                Q = next(Q);
            }
            if (email(next(Q)) == email && tag(next(Q)) == tag) {
                next(Q) = next(next(Q));
                email(next(Q)) = NULL; // logic error?
                tag(next(Q)) = NULL; // logic error?
                next(next(Q)) = NULL;
                P = next(Q);
            } else {
                cout << "Email dengan tag 3'" << info(tag) << "' tidak ditemukan." << endl;
            }
        }
    } else {
        cout << "List relasi kosong." << endl;
    }
}

void showTagOfEmail(listRelasi Lr, listEmail Le, int emailID) // 7. show child of parent X
{
    adrRelasi R = first(Lr);
    adrEmail E = findEmail(Le, emailID);
    if (E == NULL) {
        cout << "Email dengan ID yang dimasukkan tidak ditemukan." << endl;
    } else {
        cout << "------All Tags of Email X------" << endl;
        cout << "ID: " << info(E).emailID << endl;
        cout << "Pengirim Email : " << info(E).pengirim << endl;
        cout << "Penerima Email : " << info(E).penerima << endl;
        cout << "Subjek Email   : " << info(E).subjek << endl;
        cout << "Isi Email      : " << endl << "-> " << info(E).isi << endl;
        cout << "Tag Email      : ";
        while (R != NULL) {
            if (email(R) == E) {
                cout << info(tag(R)) << ", ";
            }
            R = next(R);
        }
        cout << "\n-------------------------------" << endl << endl;
    }
};

//void findTagOfEmail(listRelasi Lr, listEmail Le, listTag Lt, int emailID); // 8. find child of parent X
//{
//    adrEmail E = findEmail(Le);
//    adrTag T = findTag(Lt);
//
//    adrRelasi R = first(Lr);
//    if (R != NULL) {
//        while )
//    }
//}

void addRelation(listRelasi &Lr, listEmail Le, listTag Lt) {
    int ID;
    string tag;

    showEmail(Le); // <- print
    showTag(Lt); // <- print
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

    showEmail(Le); // <- print
    showTag(Lt); // <- print
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

void showEmailWithMostTag(listRelasi Lr, listEmail Le) // 11a.show email with the most tags and how many tags it has
{
    int n = countEmail(Le);
    int cnt;
    int maks = 0;
    int idMax;
    adrRelasi R = first(Lr);

    if (R == NULL) {
        cout << "List relasi kosong." << endl;
    } else if (next(R) == NULL) {
        idMax = info(email(R)).emailID;
        showTagOfEmail(Lr, Le, idMax);
    } else {
        for (int ID = 1; ID <= n; ID++) {
            cnt = 0;
            while (R != NULL) {
                if (info(email(R)).emailID == ID) {
                    cnt++;
                }
                R = next(R);
            }
            if (cnt >= maks) {
                maks = cnt;
                idMax = ID;
            }
        }
        showTagOfEmail(Lr, Le, idMax);
    }
}

void deleteEmailsWithTag(listRelasi &Lr, listEmail &Le, listTag Lt, string tag) // 11b. show email with the most tags and how many tags it has
{
    adrTag T = findTag(Lt, tag);
    adrRelasi Q, R = first(Lr);
    adrEmail P, E = first(Le);

    if (R == NULL) {
        cout << "List email kosong." << endl;
    } else {
//        showAllRelation(Lr);
        while (R != NULL) {
            if (tag(R) == T) {
                deleteTagOfEmail(Lr, email(R), T, Q);

                if (email(R) == first(Le)) {
                    deleteFirst(Le, P);
                } else if (email(R) == last(Le)) {
                    deleteLast(Le, P);
                } else {
                    E = first(Le);
                    while (next(E) != NULL) {
                        if (next(E) == email(R)) {
                            cout << "hi?" << endl;
                            deleteAfter(Le, E, P);
                        }
                        E = next(E);
                    }
                }
            }
            R = next(R);
        }
    }
}

void showAllRelation(listRelasi Lr) {
    adrRelasi R = first(Lr);
    if (R != NULL) {
        cout << "---------All Relations---------" << endl;
        while (R != NULL) {
            cout << "ID: " << info(email(R)).emailID << endl;
            cout << "Pengirim Email : " << info(email(R)).pengirim << endl;
            cout << "Penerima Email : " << info(email(R)).penerima << endl;
            cout << "Subjek Email   : " << info(email(R)).subjek << endl;
            cout << "Isi Email      : " << endl << "-> " << info(email(R)).isi << endl;
            cout << "Tag Email      : " << info(tag(R)) << endl << endl;

            R = next(R);
        }
        cout << "-------------------------------" << endl << endl;
    } else {
        cout << "List relasi kosong." << endl;
    }
}

