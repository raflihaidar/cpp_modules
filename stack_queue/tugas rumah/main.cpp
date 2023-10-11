#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    int input;
    Stack Mahasiswa;
    address p;
    Mhs Data;

    createStack(Mahasiswa);

    do{
        cout << "=========Program==========" << endl;
        peek(Mahasiswa);
        cout << "1. ADD" << endl;
        cout << "2. DEL" << endl;
        cout << "3. EXIT" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> input;

        switch(input){
        case 1 :
            cout << "Masukkan Nama : ";
            cin >> Data.nama;
            cout << "Masukkan NIM : ";
            cin >> Data.nim;
            cout << "Masukkan Umur : ";
            cin >> Data.umur;
            p = createElm(Data);
            push(Mahasiswa, p);
            break;
        case 2 :
            pop(Mahasiswa);
            break;
        }

        system("pause");
        system("cls");
    }while(input != 3);
    cout << "Terima Kasih Telah Menggunakan Program Kami";


    return 0;
}
