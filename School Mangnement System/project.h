/*
 ============================================================================
 Name        : school mangment system
 Author      : martina milad
 Description : School Header File.
 ============================================================================
 */
 
#ifndef PROJECT_H           
#define PROJECT_H

#define NumberOfStudents 100 

typedef struct
{
        int ID;
		int Score;
		long int phone_number;
		char name[60];
		char address[60];
		int  day , month , year;
		int Num;
}student;

/*array of struct to contains all student data*/
student Stu[NumberOfStudents];


/*the prototypes of the functions*/

void Main_Menu();
void Empty_Database();    /* use initally when the list is empty*/
void New_Student(student *Data);
void printList();
void Delete_Student();
void Student_Edit();
void Rank_Student(); 
void Student_Score(student *Data);   


#endif