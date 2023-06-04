#include <iostream>
#include "header.h"

using namespace std;

void initStack(Stack &s){
    s.top = -1;
}

bool isEmpty(Stack s){
    return s.top == -1;
}

bool isFull(Stack s){
    return s.top == MAX_SIZE - 1;
}

void push(Stack &s, mobil x){
    if(!isFull(s)){
        s.top++;
        s.data[s.top] = x;
    }else{
        cout << "Stack Sudah Penuh" << endl;
    }
}

mobil pop(Stack &s){
    if(!isEmpty(s)){
        s.top--;
    }else{
        cout << "Stack Masih Kosong" << endl;
    }
}

mobil peek(Stack s){
    return s.data[s.top];
}

void showMobil(Stack s){
    if(!isEmpty(s)){
        cout << "Data Mobil yang Terdaftar : " << endl;
        for(int i = 0; i <= s.top; i++){
            cout << "Data ke-" << i + 1 << endl;
            cout << "Merk Mobil : " << s.data[i].merk << endl;
            cout << "Warna Mobil : " << s.data[i].warna << endl;
            cout << "Tahun Mobil : " << s.data[i].tahun << "\n" << endl;
        }
    }else{
        cout << "Stack Masih Kosong, Silahkan Isi Data Terlebih Dahulu" << endl;
    }
}

void searchMobil(Stack s, string merk){
    int n;
    if(!isEmpty(s)){
        for(int i = s.top; i >= 0; i--){
            if(s.data[i].merk == merk){
                cout << "Data Mobil ke-" << i + 1 << endl;
                cout << "Merk Mobil : " << s.data[i].merk << endl;
                cout << "Warna Mobil : " << s.data[i].warna << endl;
                cout << "Tahun Mobil : " << s.data[i].tahun << endl;
                n++;
            }
        }
        if(n == 0){
            cout << "Merk yang Anda Cari Tidak Tersedia" << endl;
        }
    }else{
        cout << "Stack Masih Kosong, Silahkan Isi Data Terlebih Dahulu" << endl;
    }
}
