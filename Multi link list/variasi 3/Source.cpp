#include "Header.h"

void createListStudent(list_student &s){
	s.first_student = NULL;									//inisialisasi first dengan NULL
}

adr_student createElmStudent(infotype_student data){
	adr_student p = new elm_student;						//alokasi memory
	p->info_student = data;
	p->next_student = NULL;									//next(student) di assignment dengan NULL
	p->education.first_relation=NULL;							// list relasi juga masih NULL
	return p;												// mengembalikan alamat dari elament yang dibuat
}

void createListEducation(list_education &e){
	e.first_education = NULL;
}

adr_education createElmEducation(infotype_education data){
	adr_education p = new elm_education;
	p->info_education = data;
	p->next_education = NULL;
	return p;
}

adr_relation createElmRelation(){
	adr_relation r = new elm_relation;						//alokasi memory
	r->next_education=NULL;									//pointer yang menunjuk elemen course masih NULL
	r->next_relation = NULL;								//pointer yang menunjuk next elemen juga masih NULL
	return r;												//kembalikan alamat eleman relasi yang dibuat
}

void insertStudent(list_student &s, adr_student p){
	//insertLast
	if(s.first_student == NULL){
		s.first_student = p;
	}else{
		adr_student q = s.first_student;					//pointer yang menunjuk elemen terakhir
		while(q->next_student != NULL){
			q = q->next_student;
		}
		q->next_student = p;
	}
}

void insertEducation(list_education &e, adr_education q){
	//insertFirst
	if(e.first_education == NULL){
		e.first_education = q;
	}else{
		q->next_education = e.first_education;
		e.first_education = q;
	}
}

adr_student searchStudent(list_student s, string id){
	adr_student p = s.first_student;											//pointer untuk traversal
	while ((p->info_student.id_student!=id) && (p->next_student!=NULL)){		//akan berhanti jika menemukan id yang sama atau pointer menunjuk elemen terakhir
		p = p->next_student;
	}
	if(p->info_student.id_student==id){											//cek elemen apakah menemukan id yang sama atau di elemen terakhir yang tidak sempat dicek dikondisi perulanagan dicek disini
		return p;																//jika benar keluarkan alamat p
	}else{
		return NULL;															//jika tidak ada bahkan sampai elemen terakhir dicek tetao tidak ada makan id yang dicari tidak ada
	}
}

adr_education searchEducation(list_education e, string id_education){						//penjelasan sama dengan student diatas
	adr_education q = e.first_education;
	while((q->info_education.id_education != id_education) && (q->next_education!=NULL)){
		q = q->next_education;
	}
	if(q->info_education.id_education==id_education){
		return q;
	}else{
		return NULL;
	}
}

adr_relation searchRelation(list_relation r, adr_education p){
    adr_relation q = r.first_relation;
    while((q->next_relation != NULL)&&(q->next_education != p)){
        q = q->next_relation;
    }
    if(q->next_education == p){
        return q;
    }else{
        return NULL;
    }
}

void addEducation(list_student &s, list_education &e, string id_student, string id_education){
	adr_student p = searchStudent(s,id_student);              //cari address id_student
	adr_education q = searchEducation(e,id_education);                 //cari address id_course
	if((p!=NULL)&&(q!=NULL)){                                 // kalau ada id_student dan id_course
		adr_relation r = createElmRelation();                 // buat elemen relasi r
		r->next_education = q;                                   // sambungkan elemen r dengan q (address id_course)
		if(p->education.first_relation==NULL){                   // kalau list relasi masih kosong, sambungkan langsung dengan element r
			p->education.first_relation = r;
		}else{                                                // kalau sudah ada isinya, insert last elemen r
			adr_relation t = p->education.first_relation;
			while(t->next_relation!=NULL){
				t=t->next_relation;
			}
			t->next_relation = r;
		}
	}
}

void deleteEducationStudent(list_student &s,string id_student, string id_education){						//menghapus course tertentu pada student yang sesuai
	adr_student p = searchStudent(s,id_student);													//searching id student yang ingin dihapus
	if(p!=NULL){																					//jika menemukan
		if(p->education.first_relation!=NULL){															//cek apakah list relasi ada
			adr_relation q = p->education.first_relation;												//buat dua pointer, 1 untuk menunjuk id yang sesuai dengan id_couse dan 1 menunjuk sebelum di_course
			adr_relation r = p->education.first_relation;
			while((q->next_education->info_education.id_education!=id_education)&&(q->next_relation!=NULL)){
				r = q;																				//pointer r menunjuk sebelum id_course
				q = q->next_relation;																//pointer q menunjuk id_course
			}
			if(q->next_education->info_education.id_education==id_education){									//jika terdapat id_course yang sesuai
				if(q == p->education.first_relation){													//jika elemen yand dihapus di first
					p->education.first_relation = r->next_relation;
					q->next_relation = NULL;
				}else if(q->next_relation==NULL){													//elemen yang dihapus di elemen terakhir
					r->next_relation = NULL;
				}else{																				//element di tengah-tengah
					r->next_relation = q->next_relation;
					q->next_relation = NULL;
				}
				q->next_education = NULL;
			}
		}
	}
}

void deleteStudent(list_student &s, string id_student){												//delete student harus menghapus list relasi pada id_student yang sesuai
	adr_student p = searchStudent(s,id_student);													//mencari alamat student yang sesuai dengan id_student
	if(p!=NULL){																					//jika ada student yang sesuai
		p->education.first_relation = NULL;															//menghapus list relasi dengan assign NULL
		if(p == s.first_student){																	//elemen yang akan didelete di awal/first
			s.first_student=p->next_student;
			p->next_student=NULL;
		}else{																						//elemen yang didelete selain di awal / first
			adr_student q = s.first_student;
			while(q->next_student != p){
				q = q->next_student;
			}
			q->next_student=p->next_student;
			p->next_student = NULL;
		}
	}
}

void deleteEducation(list_student &s, list_education &e, string id_education){						//untuk delete course harus didelete relasi yang terhubung ke course tersebut
	adr_education p = searchEducation(e,id_education);												//searching course yang sesuai id_course
	if (p!=NULL){
		adr_student q = s.first_student;													//pointer untuk mengunjungi semua student
		while(q->next_student!=NULL){
			deleteEducationStudent(s,q->info_student.id_student,id_education);					//menghapus relasi dan elemen course sesuai id_course pada id_student yang sesuai pada list relasi, sehingga tidak ada lagi relasi ke course tersebut
			q = q->next_student;
		}
		deleteEducationStudent(s,q->info_student.id_student,id_education);						//delete relasi dan elemen course sesuai id_course dan id_student pada list relasi di elemen trakhir list student
		if(p==e.first_education){																//hapus element course yang akan di hapus
			e.first_education = p->next_education;
			p->next_education = NULL;
		}else{
			adr_education r = e.first_education;
			while(r->next_education!=p){
				r = r->next_education;
			}
			r->next_education = p->next_education;
			p->next_education = NULL;
		}
	}
}

void searchEducationFromStudent(list_student s, string id_student){
    adr_student p = searchStudent(s,id_student);
    if (p != NULL){
        if (p->education.first_relation != NULL){
            adr_relation r = p->education.first_relation;
            while(r->next_relation != NULL){
                cout<< "ID Course \t: "<<r->next_education->info_education.id_education<<endl;
                cout<< "Nama Course \t: "<<r->next_education->info_education.name_education<<endl;
                cout<< "Credit \t\t: "<<r->next_education->info_education.time<<endl;
                cout<<""<<endl;
                r = r->next_relation;
            }
            cout<< "ID Course \t: "<<r->next_education->info_education.id_education<<endl;
            cout<< "Nama Course \t: "<<r->next_education->info_education.name_education<<endl;
            cout<< "Credit \t\t: "<<r->next_education->info_education.time<<endl;
            cout<<""<<endl;
        }
    }
}

/*void searchStudentFromEducation(list_student s, list_course c, string id_course){
    adr_course q = searchCourse(c,id_course);
    if (q!= NULL){
        adr_student p = s.first_student;
        while (p->next_student != NULL){
            if (p->course.first_relation != NULL){
                adr_relation r = searchRelation(p->course,q);
                if (r!= NULL){
                    cout<< "ID Student \t: " << p->info_student.id_student<<endl;
                    cout<< "Nama Student \t: " <<p->info_student.name_student<<endl;
                    cout<<""<<endl;
                }
            }
            p=p->next_student;
        }
        if (p->course.first_relation != NULL){
            adr_relation r = searchRelation(p->course,q);
            if (r!= NULL){
                cout<< "ID Student \t: " << p->info_student.id_student<<endl;
                cout<< "Nama Student \t: " <<p->info_student.name_student<<endl;
                cout<<""<<endl;
            }
        }
    }
}*/

void viewStudent(list_student s){
    adr_student p = s.first_student;
    cout << "Daftar Nama : ";
    if(p != NULL){
        while(p->next_student != NULL){
            cout<<p->info_student.name_student << "," << " ";
            p = p->next_student;
        }
        cout<<p->info_student.name_student << "," << " " << endl;
    }else{
        cout << "Kosong" << endl;
    }
}

void viewEducation(list_education e){
    adr_education p = e.first_education;

    cout << "Daftar Pendidikan : ";
    if(p != NULL){
        while(p->next_education != NULL){
            cout<<p->info_education.name_education << "[" << p->info_education.time << "]" << "," << " ";
            p = p->next_education;
        }
        cout<<p->info_education.name_education << "[" << p->info_education.time << "]" << "," << " " << endl;
    }else{
        cout << "Kosong" << endl;
    }
}

void viewAll(list_student s){
	adr_student p = s.first_student;
	if (p!=NULL){
		while(p!=NULL){
			cout<<"==========================="<<endl;
			cout<<"Nama : "<<p->info_student.name_student<<endl;
			if(p->education.first_relation!=NULL){
				adr_relation q = p->education.first_relation;
				while(q != NULL){
					cout<<"Pendidikan \t: "<<q->next_education->info_education.name_education<<endl;
					cout<<"Lama \t\t: "<<q->next_education->info_education.time<<endl;
					cout<<""<<endl;
					q = q->next_relation;
				}
				cout<<""<<endl;
			}
			p=p->next_student;
		}
	}else {
	    cout << "Data Kosong" << endl;
	}
}
