#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    Data QueueInt;
    int input, i;
    createEmpty(QueueInt);
    enQueue(QueueInt, 5);
      deQueue(QueueInt);
      viewQueue(QueueInt);
    return 0;
}
