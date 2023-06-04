#include <iostream>
#include "singleListHeader.h"

using namespace std;

void createList(LinkList &list)
{
    list.first = NULL;
}

address createElm(Mahasiswa data)
{
    address mhs = new ElmList;
    mhs->Info=data;
    mhs->next=NULL;
    return mhs;
}

void insertFirst(LinkList &list, address p)
{
    if(list.first == NULL)
    {
        list.first = p;
    }
    else
    {
        p->next=list.first;
        list.first = p;
    }
}

void insertLast(LinkList &list, address p)
{
    if(list.first == NULL)
    {
        list.first = p;
    }
    else
    {
        address temp = list.first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void insertAfter(LinkList &list, address p, string cari)
{
    if(list.first == NULL)
    {
        list.first = p;
    }
    else
    {
        address temp = list.first;
        while(temp->Info.nama != cari)
        {
            temp = temp->next;
        }
        p->next=temp->next;
        temp->next = p;
    }
}

void deleteFirst(LinkList &list)
{
    address temp;
    if(list.first!=NULL)
    {
        temp = list.first;
        if(temp->next == NULL)
        {
            createList(list);
        }
        else
        {
            list.first = temp->next;
            temp->next = NULL;
        }
    }
}

void deleteLast(LinkList &list)
{
    if(list.first != NULL)
    {
        address temp = list.first;
        if(temp->next == NULL)
        {
            createList(list);
        }
        else
        {
            address q;
            while(temp->next != NULL)
            {
                q = temp;
                temp = temp->next;
            }
            q->next = NULL;
        }
    }
}

void deleteAfter(LinkList &list, string cari)
{
    if(list.first != NULL)
    {
        address temp = list.first;
        if(temp->next == NULL)
        {
            createList(list);
        }
        else
        {
            address q;
            while(temp->Info.nama != cari)
            {
                q = temp;
                temp = temp->next;
            }
            if(temp == list.first)
            {
                deleteFirst(list);
            }
            else
            {
                q->next = temp->next;
                temp->next = NULL;
            }
        }
    }
}

void view(LinkList list)
{
    if(list.first == NULL)
    {

        cout << "Kosong" << endl;
    }
    else
    {
        address cur = list.first;
        while(cur != NULL)
        {
            cout << "Nama Mahasiswa : " << cur->Info.nama << endl;
            cout << "NIM Mahasiswa : " << cur->Info.nim << endl;
            cout << "Umur Mahasiswa : " << cur->Info.umur << endl;
            cur = cur->next;
        }
    }
}
