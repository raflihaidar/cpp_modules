#include "File_Header.h"
#include <iostream>

using namespace std;

void createQueue(Queue &q)
{
    q.head = NULL;
    q.tail = NULL;
};

address createElmQueue(Mahasiswa Data)
{
    address p = new ElmQueue;
    p->Info = Data;
    p->next = NULL;
    p->prev = NULL;

    return p;
};

void add(Queue &q,address p)
{
    if((q.head==NULL)&&(q.tail==NULL))
    {
        q.head = p;
        q.tail = p;
    }
    else
    {
        p->prev=q.tail;
        q.tail->next = p;
        q.tail = p;
    };
};

void del(Queue &q,address p)
{
    p = q.head;
    if((q.head!=NULL)&&(q.tail!=NULL))
    {
        if(q.head==q.tail)
        {
            q.head=NULL;
            q.tail=NULL;
        }
        else
        {
            q.head = p->next;
            p->next = NULL;
            q.head->prev = NULL;
        };
    }
};

void view(Queue q)
{
    cout<<"Isi Queue : ";
    if ((q.head == NULL)&&(q.tail == NULL))
    {
        cout<<"[ ]";
    }
    else
    {
        address current = q.head;
        while(current->next!= NULL)
        {
            cout<<"["<<current->Info.nama<< "/" << current->Info.NIM << "/" << current->Info.umur << "]";
            current=current->next;
        }
        cout<<"["<<current->Info.nama<< "/" << current->Info.NIM << "/" << current->Info.umur << "]";
    }
    cout<<endl;
};
