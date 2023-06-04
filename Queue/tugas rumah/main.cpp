#include <iostream>
#include <iomanip>
#include <string>
#include "queue_header.h"

using namespace std;

int main()
{
    QueueofInt Q;
    int pil, idInteger;
    string id;
    int jmlhDigit;
    bool status = true;

    createEmpty(Q);

    do {
        cout << "============================================" << endl;
        cout << "SELAMAT DATANG DI PENGANTRIAN TIKET COLDPLAY" << endl;
        cout << "============================================" << endl;
        cout << "1. Daftar Pengantrian Tiket" << endl;
        cout << "2. Batalkan Pengantrian Tiket" << endl;
        cout << "3. Lihat Antrian Paling Depan" << endl;
        cout << "4. Lihat Semua Antrian" << endl;
        cout << "5. Jumlah Pembeli yang sedang Antri" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pil;
        switch(pil){
        case 1 :
            cout << "Masukkan 3 digit terakhir nomer identitas anda : ";
            cin >> id;
            jmlhDigit = id.length(); //untuk mendapatkan jumlah panjang string id
            idInteger = stoi(id); //konversi string ke int
            if(jmlhDigit == 3){
                enQueue(Q, idInteger);
            } else {
                cout << "Masukkan 3 digit saja" << endl;
            }
            break;
        case 2 :
            deQueue(Q);
            break;
        case 3 :
            foremostBuyer(Q);
            break;
        case 4 :
            viewQueue(Q);
            break;
        case 5 :
            cout << "Jumlah Pembeli yang sedang Antri : ";
            amount(Q);
            break;
        case 6 :
            status = false;
            break;
        default :
            cout << "Opsi Tidak Tersedia, Mohon Coba Kembali" << endl;
            break;
        }
        system("pause");
        system("cls");
    }while(status);
    cout << "TERIMA KASIH TELAH MENGGUNAKAN LAYANAN KAMI" << endl;
    return 0;
}
