#include "CircularHeader.h"
#include <iostream>

using namespace std;

void createList(LinkList &list)
{
    list.first = NULL;
}

address createElm(Info isi)
{
    address p = new ElmList;
    p->info = isi;
    p->next = NULL;
    return p;
}

void view(LinkList list)
{
    if (list.first == NULL)
    {
        cout << "kosong" << endl;
    }
    else
    {
        address temp = list.first;
        while (temp->next != list.first)
        {
            cout << temp->info.noKelompok << ". " << setw(9) << left << temp->info.namaKelompok << " { " << temp->info.poinKelompok << " }" << endl;
            temp = temp->next;
        }
        cout << temp->info.noKelompok << ". " << setw(9) << left << temp->info.namaKelompok << " { " << temp->info.poinKelompok << " }" << endl;
    }
}

void insertLast(LinkList &list, address p)
{
    if (list.first == NULL)
    {
        list.first = p;
        p->next = list.first;
    }
    else
    {
        address q = list.first;
        while (q->next != list.first)
        {
            q = q->next;
        }
        p->next = list.first;
        q->next = p;
    }
}

void antriList(LinkList &list)
{
    if (list.first != NULL && list.first->next != list.first)
    {
        address p;
        p = list.first;
        list.first = p->next;
    }
}

void nilaiPoint(LinkList list, Info isi)
{
    address p = list.first;
    for(int i = 0; i < 9; i++)
    {
        if(p->info.namaKelompok == isi.namaKelompok)
        {
            p->info.poinKelompok += isi.poinKelompok;
        }
        p = p->next;
    }
}

void descending(Info data_of_array[])
{
    Info Temp[9];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9-i-1; j++)
        {
            if(data_of_array[j].poinKelompok < data_of_array[j+1].poinKelompok)
            {
                Temp[j] = data_of_array[j];
                data_of_array[j] = data_of_array[j+1];
                data_of_array[j+1] = Temp[j];
            }
        }
    }
}

void sorting(LinkList &list){
    ElmInfo newList;
    address curr = list.first;
    address temp;
   for(int i = 0; i < 9; i++){
        temp = curr->next;
        for(int j = 0; j < 9-i-1; j++){
            if(curr->info.poinKelompok <= temp->info.poinKelompok){
                newList = curr->info;
                curr->info = temp->info;
                temp->info = newList;
            }
            temp = temp->next;
        }

        curr = curr->next;
   }
   view(list);
}
