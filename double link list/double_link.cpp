#include <stdio.h>
#include <iostream>
#include "double_link.h"

using namespace std;

void createList(LinkList &l)
{
    l.first = NULL;
    l.last = NULL;
}

address createElm(Data Mahasiswa)
{
    address p = new Elemen;
    p->info.nama = Mahasiswa.nama;
    p->info.tinggi = Mahasiswa.tinggi;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertFirst(LinkList &l, address p)
{
    if((l.first == NULL) && (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

void insertLast(LinkList &l, address p)
{
    if((l.first == NULL) && (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        l.last->next = p;
        p->prev = l.last;
        l.last = p;
    }
}

void insertAfter(LinkList &l, address p, string cari)
{
    if (l.first == NULL)
    {
        // Jika linked list kosong
        l.first = p;
        l.last = p;
    }
    else
    {
        address temp = l.first;
        while (temp != NULL && temp->info.nama != cari)
        {
            temp = temp->next;
        }
        if ((temp != NULL) && (temp->info.nama == cari))
        {
            // Jika ditemukan elemen dengan info nama yang sesuai
            p->prev = temp;
            p->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = p;
            }
            else
            {
                l.last = p; // Perbarui l.last jika elemen baru disisipkan setelah elemen terakhir
            }
            temp->next = p;
        }
        else
        {
            cout << "Data yang anda cari tidak ditemukan" << endl;
        }
    }
}

void deleteFirst(LinkList &l, address &p)
{
    if((l.first != NULL) && (l.last != NULL))
    {
        address p = l.first;
        if(l.first == l.last)
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            l.first = l.first->next;
            l.first->prev = NULL;
            p->next = NULL;
        }
    }
}

void deleteLast(LinkList &l, address &p)
{
    if((l.first != NULL) && (l.last != NULL))
    {
        address p = l.last;
        if(l.first == l.last)
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            l.last = l.last->prev;
            p->prev = NULL;
            l.last->next = NULL;
        }
    }
}

void deleteAfter(LinkList &l, address &p, string cari)
{
    if((l.first != NULL) && (l.last != NULL))
    {
        if(l.first->info.nama == cari)
        {
            deleteFirst(l, p);
        }
        else if(l.last->info.nama == cari)
        {
            deleteLast(l, p);
        }
        else
        {
            address temp, p = l.first;
            while((p->next != NULL) && (p->info.nama != cari))
            {
                temp = p;
                p = p->next;
            }
            if((p->info.nama == cari) && (p != NULL))
            {
                temp->next = p->next;
                p->next->prev = temp;
                p->next = NULL;
                p->prev = NULL;
            }
        }
    }
}

void updateData(LinkList &l, address p, Data Mahasiswa, string cari)
{
    if((l.first != NULL) && (l.last != NULL))
    {
        address p = l.first;
        int pil;
        while((p->next != NULL) && (p->info.nama != cari))
        {
            p = p->next;
        }
        if(p->info.nama == cari)
        {
            cout << "Menu Update : " << endl;
            cout << "1. Update Nama" << endl;
            cout << "2. Update Tinggi" << endl;
            cout << "3. Update Keduanya" << endl;
            cout << "Masukkan pilihan : ";
            cin >> pil;
            switch(pil)
            {
            case 1 :
                cout << "Update nama mahasiswa : ";
                cin >> Mahasiswa.nama;
                p->info.nama = Mahasiswa.nama;
                break;
            case 2 :
                cout << "Update tinggi mahasiswa : ";
                cin >> Mahasiswa.tinggi;
                p->info.tinggi = Mahasiswa.tinggi;
                break;
            case 3 :
                cout << "Update nama mahasiswa : ";
                cin >> Mahasiswa.nama;
                cout << "Update tinggi mahasiswa : ";
                cin >> Mahasiswa.tinggi;
                p->info.nama = Mahasiswa.nama;
                p->info.tinggi = Mahasiswa.tinggi;
                break;
            }
        }
        else
        {
            cout << "Data Tidak Ditemukan" << endl;
        }
    }
}

void viewDataTertinggi(LinkList &l, address p) {
    if (l.first != NULL) {
        address temp = l.first;
        while (p != NULL) {
            if (p->info.tinggi > temp->info.tinggi) {
                temp = p;
            }
            p = p->next;
        }
        cout << "Data tertinggi : " << temp->info.nama << " (" << temp->info.tinggi << ")" << endl;
    } else {
        cout << "Data kosong" << endl;
    }
}

void mean(LinkList &l, address p) {
    if (l.first != NULL) {
        int total = 0;
        int count = 0;
        address temp = l.first;
        while (temp != NULL) {
            total += temp->info.tinggi;
            count++;
            temp = temp->next;
        }
        float rata = total / count;
        cout << "Tinggi Rata-Rata : " << rata << endl;
    }else{
        cout << "Data Kosong" << endl;
    }
}



void view(LinkList l)
{
    if((l.first == NULL) && (l.last == NULL))
    {
        cout << "Data Kosong" << endl;
    }
    else
    {
        address p = l.first;
        while(p != NULL)
        {
            cout << "[" << p->info.nama << "(" << p->info.tinggi << ")"  << "]" << " ";
            p = p->next;
        }
        cout << endl;
    }
}
