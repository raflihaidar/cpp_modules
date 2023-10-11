#include "Header.h"
#include <iostream>

using namespace std;

void createStack(Stack &s)
{
    s.top = NULL;
}

address createElm(Mhs data)
{
    address p = new ElmStack;
    p->info = data;
    p->next = NULL;
    return p;
}

bool isEmpty(Stack s)
{
    return s.top == NULL;
}

void push(Stack &s, address p)
{
    if(isEmpty(s))
    {
        s.top = p;
    }
    else
    {
        p->next = s.top;
        s.top = p;
    }
}

void pop(Stack &s)
{
    address temp;
    if (s.top != NULL)
    {
        temp = s.top;
        if(temp->next == NULL)
        {
            createStack(s);
        }
        else
        {
            s.top = temp->next;
            temp->next = NULL;
        };
    }
};

void peek(Stack s)
{
    cout << "Isi Stack : ";
    if (isEmpty(s))
    {
        cout << "Kosong" << endl;
    }
    else
    {
        cout << "[" <<  s.top->info.nama << "/" << s.top->info.nim << "/" << s.top->info.umur << "]" << endl;
    }
}

