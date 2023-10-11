#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>

using namespace std;

typedef struct ElmStack *address;

struct Mhs
{
    string nama;
    int nim, umur;
};

struct ElmStack
{
    Mhs info;
    address next;
};

struct Stack
{
    address top;
};

void createStack(Stack &s);
address createElm(Mhs data);
bool isEmpty(Stack s);
void push(Stack &s, address p);
void pop(Stack &s);
void peek(Stack s);

#endif // HEADER_H_INCLUDED
