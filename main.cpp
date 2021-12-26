#include "list_email.h"
#include "list_tags.h"
#include "list_relasi.h"

int main()
{
    listEmail Le;
    createList(Le);

    adrEmail P;
    inputAndAllocate(P);
    insertLast(Le, P);


    inputAndAllocate(P);
    insertLast(Le, P);

//    deleteEmailByID(L, 2, P);


    listTag Lt;
    createList(Lt);

    adrTag T;
    inputAndAllocate(T);
    insertLast(Lt, T);


    T = allocateTag("starred");
    insertLast(Lt, T);

    listRelasi Lr;
    createList(Lr);

    adrRelasi R;
    addRelation(Lr, Le, Lt);

    addRelation(Lr, Le, Lt);

    showAllRelation(Lr);
    deleteRelation(Lr, Le, Lt, R);
    showAllRelation(Lr);

    cout << "Hello world!" << endl;
    return 0;
}
