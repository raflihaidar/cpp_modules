#include <iostream>
#include "header.h"

using namespace std;

void createEmpty(Data &Integer){
    Integer.head = -1;
    Integer.tail = -1;
}

bool isFull(Data Integer){
    return Integer.tail == MAX_VALUE - 1;
}

bool isEmpty(Data Integer){
    return Integer.tail == -1;
}

void enQueue(Data &Integer, int n){
    if(isFull(Integer)){
        cout << "Antrian Sedang Penuh" << endl;
    }else{
        if(isEmpty(Integer)){
            Integer.head = 0;
            Integer.tail = 0;
        }else{
            Integer.tail++;
        }
        Integer.arr[Integer.tail] = n;
    }
}

void deQueue(Data &Integer){
    if(isEmpty(Integer)){
        cout << "Antrian Masih Kosong" << endl;
    }else{
        if(Integer.head == Integer.tail){
                createEmpty(Integer);
            }
        Integer.tail--;
    }
}

void viewQueue(Data Integer){
    if(isEmpty(Integer)){
        cout << "Antrian Masih Kosong" << endl;
    }else{
        cout << "Data : ";
        for(int i = Integer.head; i <= Integer.tail; i++){
            cout << Integer.arr[i] << "";
        }
        cout << "\n";
    }
}
