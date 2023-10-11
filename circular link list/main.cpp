#include "CircularHeader.h"
#include <iostream>

using namespace std;

int main()
{
    LinkList list;
    address temp;
    createList(list);
    int sesi = 8, menu = 1, pointTertinggi = 0;
    string tim;
    Info Temp[9];
    Info dataKelompok[]
    {
        {1, "Windows", 0},
        {2, "MacOs", 0},
        {3, "Linux", 0},
        {4, "Android", 0},
        {5, "IOS", 0},
        {6, "FreeBSD", 0},
        {7, "ChromeOS", 0},
        {8, "Solaris", 0},
        {9, "Ubuntu", 0},
    };

    for (int i = 0; i < 9; i++)
    {
        temp = createElm(dataKelompok[i]);
        insertLast(list, temp);
    }

    do
    {
        cout << "GAMES ITERATION\n";
        cout << "sesi : " << sesi << endl;
        view(list);
        cout << "Ketik 1 untuk mengganti sesi : ";
        cin >> menu;

        if (menu == 1)
        {
            if(sesi <= 8)
            {
                sesi++;
                for(int i = 0; i < 9; i++)
                {
                    cout << dataKelompok[i].namaKelompok << " : ";
                    cin >> dataKelompok[i].poinKelompok;
                    nilaiPoint(list, dataKelompok[i]);
                }
                antriList(list);
            }
            else if(sesi == 9)
            {
                system("cls");
                for(int i = 0; i < 9; i++)
                {
                    if(pointTertinggi < dataKelompok[i].poinKelompok)
                    {

                        pointTertinggi = dataKelompok[i].poinKelompok;
                        tim = dataKelompok[i].namaKelompok;
                    }
                }
                cout << "PEMENANG : " << tim << endl;
                cout << "Point : " << pointTertinggi << endl;
                sorting(list);
            }
        }
        system("pause");
        system("cls");
    }
    while (menu == 1);

    return 0;
}
