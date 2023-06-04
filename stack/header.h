#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<iostream>
#include<string.h>

using namespace std;
#define MAX_SIZE 50

struct mobil{
    string merk;
    string warna;
    int tahun;
};

struct Stack{
    mobil data[MAX_SIZE];
    int top;
};

void initStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void push(Stack &s, mobil x);
mobil pop(Stack &s);
mobil peek(Stack s);
void showMobil(Stack s);
void searchMobil(Stack s,string merk);


#endif // HEADER_H_INCLUDED
