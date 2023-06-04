#ifndef QUEUE_HEADER_H_INCLUDED
#define QUEUE_HEADER_H_INCLUDED
const int maxQueue = 10;

struct QueueofInt {
    int ar[maxQueue];
    int head, tail;
};

void createEmpty(QueueofInt &q);
void enQueue(QueueofInt &q, int elm);
void deQueue(QueueofInt &q);
void viewQueue(QueueofInt q);
void foremostBuyer(QueueofInt q);
void amount(QueueofInt q);
bool isEmpty(QueueofInt q);
bool isFull(QueueofInt q);


#endif // QUEUE_HEADER_H_INCLUDED
