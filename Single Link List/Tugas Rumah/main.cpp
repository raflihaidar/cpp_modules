#include <iostream>
#include "singleListHeader.h"
#include <string>

using namespace std;

int main()
{
    LinkList listMhs;
    Mahasiswa data;
    address temp;
    int menu;
    int cari;
    createList(listMhs);

    do
    {
        view(listMhs);
        cout << "* setting *" << endl;
        cout << "1. Masukkan Data" << endl;
        cout << "2. Hapus Data Tertentu" << endl;
        cout << "3. Cari Data" << endl;
        cout << "4. Update Data" << endl;
        cout << "Pilih Menu : ";
        cin >> menu;

        if(menu == 1)
        {
            cout << "Masukkan Nama Mahasiswa : ";
            cin >> data.nama;
            cout << "Masukkan NIM Mahasiswa : ";
            cin >> data.nim;
            cout << "Masukkan Umur Mahasiswa : ";
            cin >> data.umur;
            temp = createElm(data);
            insertLast(listMhs, temp);
        }
        else if(menu == 2)
        {
            cout << "Masukkan NIM yang ingin dihapus : ";
            cin >> cari;
            deleteAfter(listMhs, cari);
        }else if(menu == 3){
            cout << "Input NIM yang Dicari : ";
            cin >> cari;
            searchByeNIM(listMhs, cari);
        }else if(menu == 4){
            cout << "Input NIM yang Akan Diupdate : ";
            cin >> cari;
            updateByeNIM(listMhs, cari);

        }
        system("pause");
        system("cls");
    }
    while(menu != 8);
}
