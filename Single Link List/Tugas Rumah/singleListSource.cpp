#include <iostream>
#include <string>
#include "singleListHeader.h"

using namespace std;

void createList(LinkList &list)
{
    list.first = NULL;
}

address createElm(Mahasiswa data)
{
    address p = new ElmList;
    p->info = data;
    p->next = NULL;
    return p;
}

void insertLast(LinkList &list, address p)
{
    address temp = list.first;
    if(list.first == NULL)
    {
        list.first = p;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void deleteAfter(LinkList &list, int cari)
{
    address temp, q;
    if(list.first != NULL)
    {
        temp = list.first;
        if(temp->next == NULL)
        {
            createList(list);
        }
        else
        {
            while(temp->info.nim != cari)
            {
                q = temp;
                temp = temp->next;
            }
            if(temp == list.first)
            {
                list.first = temp->next;
                temp->next = NULL;
            }
            else if(temp->info.nim == cari)
            {
                q->next = temp->next;
                temp->next = NULL;
            }
        }
    }
    else
    {
        cout << "Data Masih Kosong" << endl;
    }
}

void searchByeNIM(LinkList &list, int cari)
{
    address temp = list.first;
    while(temp->info.nim != cari)
    {
        temp = temp->next;
    }
    if(temp->info.nim == cari)
    {
        cout << "* data yang dicari : " << endl;
        cout << "*-----------------------------------------------------------------------*" << endl;
        cout << "| Nama\t\t\t| NIM\t\t\t| Umur\t\t\t|" << endl;
        cout << "*-----------------------------------------------------------------------*" << endl;
        cout << "| " << temp->info.nama << "\t\t\t| " << temp->info.nim << "\t\t| " << temp->info.umur << "\t\t\t|" << endl;
        cout << "*-----------------------------------------------------------------------*" << endl;
    }
    else
    {
        cout << "Data Tidak Dapat Ditemukan" << endl;
    }
}

void updateByeNIM(LinkList &list, int cari)
{
    address temp = list.first;
    searchByeNIM(list, cari);
    cout << "Ganti Nama : ";
    cin >> temp->info.nama;
    cout << "Ganti NIM : ";
    cin >> temp->info.nim;
    cout << "Ganti Umur : ";
    cin >> temp->info.umur;
}

void view(LinkList list)
{
    if(list.first == NULL)
    {
        cout << "Kosong" << endl;
    }
    else
    {
        cout << "*-----------------------------------------------------------------------*" << endl;
        cout << "| Nama\t\t\t| NIM\t\t\t| Umur\t\t\t|" << endl;
        cout << "*-----------------------------------------------------------------------*" << endl;
        address temp = list.first;
        while(temp != NULL)
        {
            cout << "| " << temp->info.nama << "\t\t\t| " << temp->info.nim << "\t\t| " << temp->info.umur << "\t\t\t|" << endl;
            temp = temp->next;
        }
        cout << "*-----------------------------------------------------------------------*" << endl;
    }
}
