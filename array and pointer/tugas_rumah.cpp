#include <iostream>

using namespace std;

//array list menu dan harga
const string menuMakanan[3] = {"Nasi Goreng", "Mie Goreng", "Ayam Goreng"};
const int hargaMakanan[] = {15000, 12000, 20000};

void calculateTotal(int menu, int order) {
    cout << "Anda memesan " << order << " porsi " << menuMakanan[menu-1] << endl; //menampilkan jumlah pesanan user
    double total = hargaMakanan[menu-1] * order;
    cout << "Total harga : Rp." << total << endl; //menampilkan harga yang harus dibayarkan user
}

int main(){
        //deklarasi variable dan pointer
        int menu, order, *menuPtr, *orderPtr;
        menuPtr = &menu;
        orderPtr = &order;

        //Daftar Harga
        cout << "=======================" << endl;
        cout << "       DAFTAR MENU     " << endl;
        cout << "=======================" << endl;
        for(int i = 0; i < 3; i++){
            cout << i+1 << ". " << menuMakanan[i] << "\t" << "Rp" << hargaMakanan[i] << endl;
        }

        //User input
        cout << "Masukkan nomor menu : ";
        cin >> *menuPtr;

        //check kondisi input dari user
        if(*menuPtr <= 3){ //jika inputan user tersedia
            cout << "Masukkan jumlah pesanan : ";
            cin >> *orderPtr;
            calculateTotal(*menuPtr, *orderPtr);
        }else{ //jika inputan user tidak tersedia
            cout << "Maaf menu tidak tersedia" << endl;
        }
    return 0;
}
