#include <iostream>
#include "File_Header.h"

using namespace std;

int main()
{
    int input;
    Queue Mhs;
    address p;
    Mahasiswa Data;

    createQueue(Mhs);

    do{
        cout << "=========Program==========" << endl;
        view(Mhs);
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
            cin >> Data.NIM;
            cout << "Masukkan Umur : ";
            cin >> Data.umur;
            p = createElmQueue(Data);
            add(Mhs, p);
            break;
        case 2 :
            del(Mhs, p);
            break;
        }

        system("pause");
        system("cls");
    }while(input != 3);
    cout << "Terima Kasih Telah Menggunakan Program Kami";


    return 0;
}
