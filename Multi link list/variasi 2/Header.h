#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

struct infotype_student
{
    string id_student;
    string name_student;
};

struct infotype_education
{
    string id_education;
    string name_education;
    int time;
};

typedef struct elm_student *adr_student;
typedef struct elm_education *adr_education;
typedef struct elm_relation *adr_relation;

struct list_student
{
    adr_student first_student;
};

struct list_education
{
    adr_education first_education;
};

struct list_relation
{
    adr_relation first_relation;
};

struct elm_student
{
    infotype_student info_student;
    adr_student next_student;
    list_relation education;
};

struct elm_education
{
    infotype_education info_education;
    adr_education next_education;
};

struct elm_relation
{
    adr_education next_education;
    adr_relation next_relation;
};

//prosedur dan fungsi untuk setiap inisialisasi list
void createListStudent(list_student &s);
adr_student createElmStudent(infotype_student data);
void createListEducation(list_education &e);
adr_education createElmEducation(infotype_education data);
adr_relation createElmRelation();

//prosedur insert
void insertStudent(list_student &s, adr_student p);
void insertEducation(list_education &e, adr_education q);
void addEducation(list_student &s, list_education &e, string id_student, string id_education);

//prosedur delete
void deleteEducationStudent(list_student &s, string id_student, string id_education);
void deleteStudent(list_student &s, string id_student);
void deleteEducation(list_student &s, list_education &e, string id_education);

//prosedur searching
adr_student searchStudent(list_student s, string id);
adr_education searchEducation(list_education e, string id_education);
adr_relation searchRelation(list_relation r, adr_education p);

void searchCourseFromStudent(list_student s, string id_student);
void searchStudentFromCourse(list_student s, list_education e, string id_education);

//prosedur menampilkan semua student dan relasinya
void viewAll(list_student s);
void viewStudent(list_student s);
void viewEducation(list_education e);


#endif // HEADER_H_INCLUDED
