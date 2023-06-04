#include <iostream>
#include "singleListHeader.h"
#include <string>

using namespace std;

int main()
{
    LinkList listMhs;
    Mahasiswa data;
    address temp;
    createList(listMhs);
    int menu;
    string cari;
    do
    {
        view(listMhs);
        cout << "--------------------"<<endl;
        cout << "Menu Utama:" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Delete First" << endl;
        cout << "5. Delete Last" << endl;
        cout << "6. Delete After" << endl;
        cout << "7. View Mahasiswa" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        if (menu == 1)
        {
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore();
            getline(cin, data.nama);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> data.nim;
            cout << "Masukkan Umur Mahasiswa: ";
            cin >> data.umur;

            temp = createElm(data);
            insertFirst(listMhs, temp);
        }
        else if (menu == 2)
        {
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore();
            getline(cin, data.nama);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> data.nim;
            cout << "Masukkan Umur Mahasiswa: ";
            cin >> data.umur;

            temp = createElm(data);
            insertLast(listMhs, temp);
        }
        else if (menu == 3)
        {
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore();
            getline(cin, data.nama);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> data.nim;
            cout << "Masukkan Umur Mahasiswa: ";
            cin >> data.umur;

             temp = createElm(data);

            cout << "Input setelah nama? ";
            cin.ignore();
            getline(cin, cari);

            insertAfter(listMhs, temp, cari);
        }
        else if (menu == 4)
        {
            deleteFirst(listMhs);
        }
        else if (menu == 5)
        {
            deleteLast(listMhs);
        }
        else if (menu == 6)
        {
            cout << "Hapus nama siapa? ";
            cin.ignore();
            getline(cin, cari);

            deleteAfter(listMhs, cari);
        }
        else if (menu == 7)
        {
            view(listMhs);
        }
        else if (menu == 8)
        {
            cout << "Program telah berakhir" << endl;
        }
        else
        {
            cout << "Input Salah" << endl;
        }
        system ("pause");
        system ("cls");
    }
    while (menu != 8);

    return 0;
}
