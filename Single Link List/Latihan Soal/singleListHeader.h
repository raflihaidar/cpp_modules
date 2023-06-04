#ifndef SINGLELISTHEADER_H_INCLUDED
#define SINGLELISTHEADER_H_INCLUDED

#include <iostream>
#include <string>

typedef struct ElmList *address;

struct Mahasiswa {
    std::string nama;
    int nim, umur;
};

struct ElmList {
    Mahasiswa Info;
    address next;
};

struct LinkList {
    address first;
};

void createList(LinkList &list);
address createElm(Mahasiswa data);
void insertFirst(LinkList &list, address p);
void insertLast(LinkList &list, address p);
void insertAfter(LinkList &list, address p, std::string cari);
void deleteFirst(LinkList &list);
void deleteLast(LinkList &list);
void deleteAfter(LinkList &list, std::string cari);
void view(LinkList list);

#endif // SINGLELISTHEADER_H_INCLUDED
