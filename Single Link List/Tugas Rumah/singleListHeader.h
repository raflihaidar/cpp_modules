#ifndef SINGLELISTHEADER_H_INCLUDED
#define SINGLELISTHEADER_H_INCLUDED
#include <iostream>
#include <string>


typedef struct ElmList *address;

struct Mahasiswa {
    std::string nama;
    int nim;
    int umur;
};

struct ElmList {
    Mahasiswa info;
    address next;
};

struct LinkList{
    address first;
};

void createList(LinkList &list);
address createElm(Mahasiswa data);
void insertLast(LinkList &list, address p);
void deleteFirst(LinkList &list);
void deleteLast(LinkList &list);
void deleteAfter(LinkList &list, int cari);
void searchByeNIM(LinkList &list, int cari);
void updateByeNIM(LinkList&list, int cari);
void view(LinkList list);

#endif // SINGLELISTHEADER_H_INCLUDED
