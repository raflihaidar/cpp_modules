#include <iostream>
#include <string>
#include "double_link.h"

using namespace std;

int main()
{
    Data Mhs;
    LinkList l;
    createList(l);
    address p;
    int pilihan;
    string cari;
    bool status = true;
    do
    {
        cout << "== Program Pendataan Tinggi Badan ==" << endl;
        view(l);
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Insert After"<<endl;
        cout<<"4. Delete First"<<endl;
        cout<<"5. Delete Last"<<endl;
        cout<<"6. Delete After"<<endl;
        cout<<"7. Update Data" << endl;
        cout<<"8. Data Tertinggi"<< endl;
        cout<<"9. Tinggi rata-rata"<<endl;
        cout<<"10. Keluar"<<endl;
        cout<<"Masukkan pilihan anda : ";
        cin>>pilihan;
        if(pilihan == 1){
            cout << "Masukkan Nama Mahasiswa : ";
            cin >> Mhs.nama;
            cout << "Masukkan Tinggi Mahasiswa : ";
            cin >>Mhs.tinggi;
            p = createElm(Mhs);
            insertFirst(l, p);
        }else if(pilihan == 2){
             cout << "Masukkan Nama Mahasiswa : ";
            cin >> Mhs.nama;
            cout << "Masukkan Tinggi Mahasiswa : ";
            cin >>Mhs.tinggi;
            p = createElm(Mhs);
            insertLast(l, p);
        }else if(pilihan == 3){
            cout << "Masukkan Nama Mahasiswa : ";
            cin >> Mhs.nama;
            cout << "Masukkan Tinggi Mahasiswa : ";
            cin >>Mhs.tinggi;
            cout << "Masukkan Setelah nama : ";
            cin >> cari;
            p = createElm(Mhs);
            insertAfter(l, p, cari);
        }else if(pilihan == 4){
            deleteFirst(l, p);
        }else if(pilihan == 5){
            deleteLast(l, p);
        }else if(pilihan == 6){
            cout << "Masukkan nama yang akan dihapus : ";
            cin >> cari;
            deleteAfter(l, p, cari);
        }else if(pilihan == 7){
            cout << "Pilih data yang akan diupdate: ";
            cin >> cari;
            updateData(l, p, Mhs, cari);
        }else if(pilihan == 8){
            viewDataTertinggi(l, p);
        }else if(pilihan == 9){
            mean(l, p);
        }else if(pilihan == 10){
            status = false;
        }else{
            cout << "Inputan tidak valid" << endl;
        }
        system("pause");
        system("cls");
    }
    while(status != false);
}
