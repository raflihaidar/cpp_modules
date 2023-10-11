#include "Header.h"
#include <iostream>

using namespace std;

// untuk membuat list kosong pada child dan parent
void createListChild(ListChild &LC)
{
    LC.first_Child = NULL;  // first dari list akan di init dengan nilai null
}

void createListParent(ListParent &LP)
{
    LP.first_Parent = NULL;
}

// untuk melakukan create elm pada child dan parent
adr_child createElmChild(InfoChild info)
{
    adr_child c = new ElmChild; // alokasikan memori ke dalam variable
    c->info = info; // masukan info dari parameter kedalam pointer
    c->next_child = NULL;
    c->parent = NULL;
    return c;   // kembalikan pointer
}

adr_parent createElmParent(InfoParent info)
{
    adr_parent p = new ElmParent;   // sama seperti child
    p->info = info;
    p->next_parent = NULL;
    return p;
}

// untuk melakukan insert pada child dan parent (menggunakan insert last)
void insertChild(ListChild &LC, adr_child c)
{
    if (LC.first_Child == NULL) // jika list kosong maka masukan elm ke first list
    {
        LC.first_Child = c;
    }
    else
    {   // jika tidak masukan elm ke list terakhir dengan perulangan sampai ujung elm
        adr_child p = LC.first_Child;
        while (p->next_child != NULL)
        {
            p = p->next_child;
        }
        p->next_child = c;
    }
}

void insertParent(ListParent &LP, adr_parent p)
{   // sama seperti insert child
    if (LP.first_Parent == NULL)
    {
        LP.first_Parent = p;
    }
    else
    {
        adr_parent q = LP.first_Parent;
        while (q->next_parent != NULL)
        {
            q = q->next_parent;
        }
        q->next_parent = p;
    }
}

// untuk mencari apakah suatu id terdapat pada list?
adr_child searchChild(ListChild LC, int idChild)
{
    if (LC.first_Child == NULL)
    {   // jika list kosong maka kembalikan nilai null
        return NULL;
    }
    else
    {   // jika tidak kosong maka lakukan perulangan sampai ujung list atau sampai elm ditemukan
        adr_child c = LC.first_Child;
        while ((c->next_child != NULL) && (c->info.idChild != idChild))
        {
            c = c->next_child;
        }
        if (c->info.idChild == idChild) // setelah berakhir lakukan pengecekan kembali
        {
            return c;
        }
        else
        {
            return NULL;
        }
    }
}

adr_parent searchParent(ListParent LP, int idParent)
{   // sama seperti search child
    if (LP.first_Parent == NULL)
    {
        return NULL;
    }
    else
    {
        adr_parent p = LP.first_Parent;
        while ((p->next_parent != NULL) && (p->info.idParent != idParent))
        {
            p = p->next_parent;
        }
        if (p->info.idParent == idParent)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
}

// untuk melakukan relasi orang tua dan anak
void addParent(ListChild &LC, ListParent &LP, int idChild, int idParent)
{
    adr_child c;
    adr_parent p;
    c = searchChild(LC, idChild);   // buat variable child dan parent, kemudian assigmen menggunakan fungsi search
    p = searchParent(LP, idParent);
    if ((c != NULL) && (p != NULL)) // jika variable pointer tidak bernilai null maka sambungkan keduanya
    {
        c->parent = p;
    }
}

// untuk melihat semua orang tua
void viewParent(ListParent &LP)
{
    if (LP.first_Parent == NULL)
    {
        cout << "List Parent Kosong";  // jika list kosong maka outputkan ini
    }
    else
    {
        adr_parent p = LP.first_Parent; // jika tidak maka lakukan perulangan sampai list habis
        while (p->next_parent != NULL)
        {
            cout << "[" << p->info.idParent << "," << p->info.NamaParent << "] ";
            p = p->next_parent;
        }
        cout << "[" << p->info.idParent << "," << p->info.NamaParent << "]";
    }
    cout << endl;
}

// untuk melihat semua anak
void viewChild(ListChild &LC)
{   // sama seperti view parent
    if (LC.first_Child == NULL)
    {
        cout << "List Child Kosong";
    }
    else
    {
        adr_child c = LC.first_Child;
        while (c->next_child != NULL)
        {
            cout << "[" << c->info.idChild << "," << c->info.NamaChild << "] ";
            c = c->next_child;
        }
        cout << "[" << c->info.idChild << "," << c->info.NamaChild << "]";
    }
    cout << endl;
}

// untuk melihat anak yang ter-relasi dengan orang tua
void viewAllChildLinkParent(ListChild &LC, adr_parent p)
{   // lakukan output jika address parent pada child sama dengan address parent yang ada di parameter
    if (LC.first_Child != NULL)
    {
        adr_child c = LC.first_Child;
        while (c->next_child != NULL)
        {
            if (c->parent == p)
                cout << "[" << c->info.idChild << "," << c->info.NamaChild << "] ";
            c = c->next_child;
        }
        if (c->parent == p)
            cout << "[" << c->info.idChild << "," << c->info.NamaChild << "] ";
    }
}

// untuk melihat orang tua dan anak yang ber relasi
void viewParentChild(ListParent &LP, ListChild &LC)
{
    if (LP.first_Parent == NULL)
    {
        cout << "Relasi Kosong";
    }
    else
    {
        adr_parent p = LP.first_Parent;
        while (p->next_parent != NULL)
        {   // lakukan output parent seperti biasa
            cout << "[" << p->info.idParent << "," << p->info.NamaParent << " ( ";
            viewAllChildLinkParent(LC, p);  // namun panggil fungsi viewAllChildLinkParent untuk melihat anak dari si parent
            cout << " )] ";
            p = p->next_parent;
        }
        cout << "[" << p->info.idParent << "," << p->info.NamaParent << " ( ";
        viewAllChildLinkParent(LC, p);
        cout << " )] ";
    }
    cout << endl;
}

// untuk melakukan delete after pada parent, menggunakan id parent
void deleteAfterParent(ListParent &LP, int idParent)
{
    if (LP.first_Parent != NULL)
    {
        adr_parent temp = LP.first_Parent;
        if (temp->next_parent == NULL)
        {
            createListParent(LP);
        }
        else
        {
            adr_parent p;
            while ((temp->next_parent != NULL) && (temp->info.idParent != idParent))
            {
                p = temp;
                temp = temp->next_parent;
            }
            if (temp->info.idParent == idParent)
            {
                if (temp == LP.first_Parent)
                {
                    LP.first_Parent = temp->next_parent;
                    temp->next_parent = NULL;
                }
                else
                {
                    p->next_parent = temp->next_parent;
                    temp->next_parent = NULL;
                }
            }
        }
    }
}

// untuk melakukan delete pada parent (delete dengan menghapus seluruh relasi yang ada)
void deleteParent(ListParent &LP, ListChild &LC, int idParent)
{
    adr_parent p = searchParent(LP, idParent);
    if (p != NULL)
    {
        adr_child c = LC.first_Child;
        if (c != NULL)
        {
            while (c->next_child != NULL)
            {
                if (c->parent == p)
                    c->parent == NULL;
                c = c->next_child;
            }
            if (c->parent == p)
                c->parent == NULL;
        }
        deleteAfterParent(LP, idParent);
    }
}

// untuk melakukan delete after pada child dengan id child
void deleteAfterChild(ListChild &LC, int idChild)
{
    if (LC.first_Child != NULL)
    {
        adr_child temp = LC.first_Child;
        if (temp->next_child == NULL)
        {
            createListChild(LC);
        }
        else
        {
            adr_child c;
            while ((temp->next_child != NULL) && (temp->info.idChild != idChild))
            {
                c = temp;
                temp = temp->next_child;
            }
            if (temp->info.idChild == idChild)
            {
                if (temp == LC.first_Child)
                {
                    LC.first_Child = temp->next_child;
                    temp->next_child = NULL;
                }
                else
                {
                    c->next_child = temp->next_child;
                    temp->next_child = NULL;
                }
            }
        }
    }
}


