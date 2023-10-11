#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
    list_student S;
    list_education E;
    adr_student p_student; // Deklarasikan di luar blok switch
    adr_education p_education;
    infotype_student data;
    infotype_education data2;
    createListStudent(S);
    createListEducation(E);
    int input;
    string string_student;
    string string_education;

    do {
        cout << "Data Pendidikan" << endl;
        viewStudent(S);
        viewEducation(E);
        cout << "Menu" << endl;
        cout << "1. Masukkan Data Orang" << endl;
        cout << "2. Masukkan Data Pendidikan" << endl;
        cout << "3. Tambahan Relasi Orang dan Pendidikan" << endl;
        cout << "4. Hapus Data Pendidikan" << endl;
        cout << "5. Hapus Relasi" << endl;
        cout << "6. Lihat Data Detail Orang" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >>  input;

        switch(input){
        case 1 :
            cout << "Masukkan Id Siswa : ";
            cin >> data.id_student;
            cout << "Masukkan Nama Siswa : ";
            cin >> data.name_student;
            p_student = createElmStudent(data);
            insertStudent(S, p_student);
            break;
        case 2 :
            cout << "Masukkan Id Pendidikan : ";
            cin >> data2.id_education;
            cout << "Masukkan Nama Pendidikan : ";
            cin >> data2.name_education;
            cout << "Masukkan Lama Pendidikan : ";
            cin >> data2.time;
            p_education = createElmEducation(data2);
            insertEducation(E, p_education);
            break;
        case 3 :
            cout << "Masukkan Id Siswa : ";
            cin >> string_student;
            cout << "Masukkan Id Pendidikan : ";
            cin >> string_education;
            addEducation(S, E,  string_student,  string_education);
            break;
        case 4 :
            cout << "Masukkan Id Pendidikan : ";
            cin >> string_education;
            deleteEducation(S, E, string_education);
            break;
        case 5 :
            cout << "Masukkan Id SIswa : ";
            cin >> string_student;
            cout << "Masukkan Id Pendidikan : ";
            cin >> string_education;
            deleteEducationStudent(S, string_student, string_education);
            break;
        case 6 :
            viewAll(S);
            break;
        }


        system("pause");
        system("cls");
    }while(input != 7);

    return 0;
}
