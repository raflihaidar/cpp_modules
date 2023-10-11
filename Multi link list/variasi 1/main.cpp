#include <iostream>
#include "Header.h"

using namespace std;

int main()
{

    ListChild listChild;
    ListParent listParent;

    InfoChild infoChild;
    InfoParent infoParent;

    createListChild(listChild);
    createListParent(listParent);

    adr_child c;
    adr_parent p;

    int input, idChild, idParent;

    do{
        viewChild(listChild);
        viewParent(listParent);
        viewParentChild(listParent, listChild);
        cout << "Keluarga bencana" << endl;
        cout << "1. Tambah anak" << endl;
        cout << "2. Tambah orang tua" << endl;
        cout << "3. Pilih orang tua u/ menambah anak" << endl;
        cout << "4. Hapus anak" << endl;
        cout << "5. Hapus orang tua" << endl;
        cout << "pilih : ";
        cin >> input;

        switch(input){
        case 1 :
            cout << "Masukkan id : ";
            cin >> infoChild.idChild;
            cout << "Masukkan nama : ";
            cin >> infoChild.NamaChild;
            c = createElmChild(infoChild);
            insertChild(listChild, c);
            break;
        case 2 :
            cout << "Masukkan id : ";
            cin >> infoParent.idParent;
            cout << "Masukkan nama :";
            cin >> infoParent.NamaParent;
            p = createElmParent(infoParent);
            insertParent(listParent, p);
            break;
        case 3 :
            cout << "Masukkan id orang tua : ";
            cin >> idParent;
            cout << "Masukkan id anak : ";
            cin >> idChild;
            addParent(listChild, listParent, idChild, idParent);
            break;
        case 4 :
            cout << "Masukkan id anak : ";
            cin >> idChild;
            deleteAfterChild(listChild, idChild);
            break;
        case 5 :
            cout << "Masukkan id orang tua : ";
            cin >> idParent;
            deleteParent(listParent, listChild, idParent);
            break;
        default :
            cout << "Yang anda inputkan salah" << endl;
        }
        system("pause");
        system("cls");
    }while(input != 6);

    return 0;
}
