#include "list_email.h"
#include "list_tags.h"
#include "list_relasi.h"

int selectMenu(){
    cout << "===== MENU =====" << endl;
    cout << "1. Add email" << endl;
    cout << "2. Show all email" << endl;
    cout << "3. Find email by ID" << endl;
    cout << "4. Delete email by ID" << endl;
    cout << "5. Add tag" << endl;
    cout << "6. Show all tag" << endl;
    cout << "7. Add relation" << endl;
    cout << "8. Show all relation" << endl;
    cout << "9. Delete relation" << endl;
    cout << "10. Show tag of email" << endl;
    cout << "11. Show email with most tag" << endl;
    cout << "12. Delete all email with tag" << endl;
    cout << "0. Selesai " << endl;
    cout << "Masukkan menu: ";

    int input = 0;
    cin >> input;

    return input;

};

int main()
{
    /*
        TODO:
        1. fix bug delete relasi tag pertama dalam list tag
    */

    listEmail Le;
    createList(Le);

    adrEmail E;

    listTag Lt;
    createList(Lt);

    adrTag T;

    listRelasi Lr;
    createList(Lr);

    adrRelasi R;

//    inputAndAllocate(T);
//    insertLast(Lt, T);

//    inputAndAllocate(T);
//    insertLast(Lt, T);

    T = allocateTag("starred");
    insertLast(Lt, T);

//    T = allocateTag("trash");
//    insertLast(Lt, T);
    E = allocateEmail("ondo", "dyat", "apadi ", "apakabs");
    insertLast(Le, E);
    insertTagOfEmail(Lr, E, T);

    E = allocateEmail("slkdnf", "sdnflksdaf", "apadi ", "apakabs");
    insertLast(Le, E);
    insertTagOfEmail(Lr, E, T);

    E = allocateEmail("dayt", "ondo", "askdasdl", "oandkasj");
    insertLast(Le, E);
    insertTagOfEmail(Lr, E, T);

    E = allocateEmail("aafdf", "asdfsadfsda", "askdasdl", "oandkasj");
    insertLast(Le, E);
    // insertTagOfEmail(Lr, E, T);
//    addRelation(Lr, Le, Lt);
//
//    addRelation(Lr, Le, Lt);
//
//    addRelation(Lr, Le, Lt);


//    showAllRelation(Lr); // <- print
//    showTagOfEmail(Lr, Le, 1); // <- print
//    showEmailsOfTag(Lr, Lt, "spam");
//    deleteRelation(Lr, Le, Lt, R);
//    showTagOfEmail(Lr, Le, 1); // <- print
//    showAllRelation(Lr); // <- print

//    showEmailWithMostTag(Lr, Le);
//    deleteEmailsWithTag(Lr, Le, Lt, "spam");

//    showEmail(Le);
//    showAllRelation(Lr);
//    showEmail(Le);
    int input = 0; char option; string tag;
    int ID;

    input = selectMenu();
    while (input != 0){
        switch(input){
        case 1:
            cout << "Add email" << endl;
            inputAndAllocate(E);
            insertLast(Le, E);
            break;
        case 2:
            cout << "Show all email" << endl;
            showEmail(Le);
            break;
        case 3:
            cout << "Find email by ID: ";
            cin >> ID;
            E = findEmail(Le, ID);
            if (E != NULL) {
                cout << "\nID: " << info(E).emailID << endl;
                cout << "Pengirim Email : " << info(E).pengirim << endl;
                cout << "Penerima Email : " << info(E).penerima << endl;
                cout << "Subjek Email   : " << info(E).subjek << endl;
                cout << "Isi Email      : " << endl << "-> " << info(E).isi << endl << endl;
            } else {
                cout << "ID email tidak ditemukan." << endl;
            }
            break;
        case 4:
            cout << "Delete email by ID: ";
            cin >> ID;
            deleteEmailByID(Le, ID, E);
            break;
        case 5:
            cout << "Add tag" << endl;
            inputAndAllocate(T);
            insertLast(Lt, T);
            break;
        case 6:
            cout << "Show all tag" << endl;
            showTag(Lt);
            break;
        case 7:
            cout << "Add relation" << endl;
            addRelation(Lr, Le, Lt);
            break;
        case 8:
            cout << "Show all relation" << endl;
            showAllRelation(Lr);
            break;
        case 9:
            cout << "Delete relation" << endl;
            deleteRelation(Lr, Le, Lt, R);
            break;
        case 10:
            cout << "Show tag of email with ID: ";
            cin >> ID;
            showTagOfEmail(Lr, Le, ID);
            break;
        case 11:
            cout << "Show email with most tag" << endl;
            showEmailWithMostTag(Lr, Le);
            break;
        case 12:
            cout << "Delete all email with tag: ";
            cin >> tag;
            deleteEmailsWithTag(Lr, Le, Lt, tag);
//            cout << first(Lr);
            break;
        }
         cout << "Return to main menu? (Y/N) : ";
            cin >> option;
            cout << endl;
            if (option == 'Y' || option == 'y') {
                input = selectMenu();
            } else {
                break;
            }
    }


    cout << "PROGRAM EXITED." << endl;
    return 0;
}




