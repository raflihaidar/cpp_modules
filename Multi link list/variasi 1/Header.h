#include <iostream>
#include <string.h>
using namespace std;

typedef struct ElmChild *adr_child;   // pointer to elmStudent
typedef struct ElmParent *adr_parent; // pointer to elmClass

// tipe data bentukan untuk info child dan info parent
struct InfoChild
{
    int idChild;    // untuk menampung id child
    string NamaChild;   // untuk menampung nama child
};
struct InfoParent
{   // sama seperti child diatas, bedanya ini untuk parent
    int idParent;
    string NamaParent;
};

// tipe list untuk child dan parent yang mana berisi pointer
struct ListChild
{
    adr_child first_Child;
};
struct ListParent
{
    adr_parent first_Parent;
};

// tipe bentukan untuk setiap elm pada list
struct ElmChild
{
    InfoChild info;
    adr_child next_child;
    adr_parent parent;
};
struct ElmParent
{
    InfoParent info;
    adr_parent next_parent;
};

void createListChild(ListChild &LC);
void createListParent(ListParent &LP);
adr_child createElmChild(InfoChild info);
adr_parent createElmParent(InfoParent info);
void insertChild(ListChild &LC, adr_child c);
void insertParent(ListParent &LP, adr_parent p);
adr_child searchChild(ListChild LC, int idChild);
adr_parent searchParent(ListParent LP, int idParent);
void addParent(ListChild &LC, ListParent &LP, int idChild, int idParent);
void viewParent(ListParent &LP);
void viewChild(ListChild &LC);
void viewAllChildLinkParent(ListChild &LC, adr_parent p);
void viewParentChild(ListParent &LP, ListChild &LC);
void deleteAfterParent(ListParent &LP, int idParent);
void deleteParent(ListParent &LP, ListChild &LC, int idParent);
void deleteAfterChild(ListChild &LC, int idChild);
