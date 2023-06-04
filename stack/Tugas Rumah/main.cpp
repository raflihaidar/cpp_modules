#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int option;
    char pil;
    bool loop = true;
    string merk;

    Stack db;
    initStack(db);
    mobil mobil1;
    do{
        system("cls");
        cout << "======================================================" << endl;
        cout << "SELAMAT DATANG DI PENDATAAN MOBIL MAHASISWA ALSTRUKDAT" << endl;
        cout << "======================================================" << endl;
        cout << "1. Pendataan Mobil" << endl;
        cout << "2. Searching Data" << endl;
        cout << "3. View All Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> option;
        if(option == 1){
            cout << "MASUKKAN DATA MOBIL : " << endl;
            pendataan:
            cout << "Masukkan Merk Mobil : ";
            cin >> mobil1.merk;
            cout << "Masukkan Warna Mobil : ";
            cin >> mobil1.warna;
            cout << "Masukkan Tahun Mobil : ";
            cin >> mobil1.tahun;
            push(db, mobil1);
            cout << "Ingin Menambahkan Data lagi ? [y/n] : ";
            cin >> pil;
            if(pil == 'y'){
                goto pendataan;
            }
        }else if(option == 2){
            cout << "Search Data Berdasarkan Merk Mobil : ";
            cin >> merk;
            searchMobil(db, merk); //Mencari mobil berdasarkan merk mobil
            system("pause");
        }else if(option == 3){
           showMobil(db); //Melihat semua data mobil
           system("pause");
        }else if(option == 4){
            system("cls");
            cout << "TERIMA KASIH TELAH MENGGUNAKAN LAYANAN KAMI" << endl;
            loop = false;
        }else{
            cout << "PILIHAN YANG ANDA MASUKKAN SALAH" << endl;
            system("pause");
        }
    }while(loop);
    return 0;
}
