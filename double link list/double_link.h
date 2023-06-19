#ifndef DOUBLE_LINK_H_INCLUDED
#define DOUBLE_LINK_H_INCLUDED

#include <string>

typedef struct Elemen *address;

struct Data {
    std::string nama;
    int tinggi;
};

struct Elemen {
    Data info;
    address next;
    address prev;
};

struct LinkList {
    address first;
    address last;
};

void createList(LinkList &l);
address createElm(Data Mahasiswa);
void insertFirst(LinkList &l, address p);
void insertLast(LinkList &l, address p);
void insertAfter(LinkList &l, address p, std::string cari);
void deleteFirst(LinkList &l, address &p);
void deleteLast(LinkList &l, address &p);
void deleteAfter(LinkList &l, address &p, std::string cari);
void view(LinkList l);
void updateData(LinkList &l, address p, Data Mahasiswa,  std::string cari);
void viewDataTertinggi(LinkList &l, address p);
void mean(LinkList &l, address p);


#endif // DOUBLE_LINK_H_INCLUDED
