#ifndef FILE_HEADER_H_INCLUDED
#define FILE_HEADER_H_INCLUDED
#include <string>

using namespace std;

typedef struct ElmQueue *address;

struct Mahasiswa {
    string nama;
    int NIM;
    int umur;
};

struct ElmQueue
{
    Mahasiswa Info;
    address next;
    address prev;
};

struct Queue
{
    address head;
    address tail;
};

void createQueue(Queue &q);
address createElmQueue(Mahasiswa Data);
void add(Queue &q,address p);
void del(Queue &q,address p);
void view(Queue q);


#endif // FILE_HEADER_H_INCLUDED
