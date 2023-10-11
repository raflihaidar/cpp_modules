#ifndef CIRCULARHEADER_H_INCLUDED
#define CIRCULARHEADER_H_INCLUDED
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

typedef struct ElmList *address;

typedef struct ElmInfo
{
    int noKelompok;
    string namaKelompok;
    int poinKelompok;
} Info;

struct ElmList
{
    Info info;
    address next;
};

struct LinkList
{
    address first;
};

void createList(LinkList &list);
address createElm(Info isi);
void insertLast(LinkList &list,address p);

void view(LinkList list);
void antriList(LinkList &list);
void nilaiPoint(LinkList list, Info isi);
void descending(Info data_of_array[]);
void sorting(LinkList &list);

#endif // CIRCULARHEADER_H_INCLUDED
