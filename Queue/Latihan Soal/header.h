#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

const int MAX_VALUE = 10;

struct Data {
    int arr[MAX_VALUE];
    int head, tail;
};

void createEmpty(Data &Integer);
void enQueue(Data &Integer, int n);
void deQueue(Data &Integer);
void viewQueue(Data Integer);
void latestQueue(Data Integer);
int jumlahQueue(Data Integer);
bool isEmpty(Data Integer);
bool isFull(Data Integer);

#endif // HEADER_H_INCLUDED
