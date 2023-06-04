#include <iostream>
#include <iomanip>
#include "queue_header.h"

using namespace std;

void createEmpty(QueueofInt &q){ //untuk inialisasi queue / antrian
    q.head = -1;
    q.tail = -1;
}

void enQueue(QueueofInt &q, int elm){ //untuk menambahkan elemen ke antrian
    int j, total, i = q.head;
    if(isFull(q)){
        cout << "Antrian sudah penuh" << endl;
    }else{
        if(isEmpty(q)){
            q.head = 0;
            q.tail = 0;
        }else if (q.tail == maxQueue - 1 && q.head != 0){
            while(i <= q.tail){
                q.ar[j] = q.ar[i];
                i++;
                j++;
            }
            q.head = 0;
            q.tail = j;
        }else {
            q.tail++;
        }
        q.ar[q.tail] = elm;
        cout << "Berhasil ditambahkan ke antrian!!!" << endl;
        total = q.tail - q.head;
        cout << "Sisa Slot Antrian : " << ( maxQueue - 1 ) - total << endl;
    }
}

void deQueue(QueueofInt &q){ //untuk menghapus elemen dari antrian
    if(isEmpty(q)){
        cout << "Antrian masih kosong" << endl;
    }else{
        if(q.head == q.tail){
            createEmpty(q);
        }else{
           q.head++;
        }
        cout << "Berhasil Menghapus Pembeli dari Antrian" << endl;
    }
}

void amount(QueueofInt q){
    int sum = 0;
    if(isEmpty(q)){
        sum = 0;
    }else{
         sum = q.tail - q.head + 1;
    }
    cout << sum << " Orang" << endl;
}

void viewQueue(QueueofInt q){ //untuk melihat elemen - elemen

    if(isEmpty(q)){
        cout << "Antrian masih kosong" << endl;
    }else{
        cout << "Nomor Antrian : ";
        for(int i = q.head; i <= q.tail; i++){
            cout << setw(3) << setfill('0') <<  q.ar[i] << " ";
        }
        cout << "\n";
    }
}

void foremostBuyer(QueueofInt q){ //untuk melihat elemen - elemen
    if(isEmpty(q)){
        cout << "Antrian masih kosong" << endl;
    }else{
        cout << "Nomor Antrian Paling Depan : ";
        for(int i = q.head; i <= q.head; i++){
            cout << setw(3) << setfill('0') << q.ar[i] << endl;
        }
    }
}

bool isEmpty(QueueofInt q){ //untuk mengecek antrian kosong atau tidak
    return ((q.head == -1) && (q.tail == -1));
}

bool isFull(QueueofInt q){ //untuk mengecek antrian full atau tidak
    return ((q.head == 0) && (q.tail == maxQueue - 1));
}
