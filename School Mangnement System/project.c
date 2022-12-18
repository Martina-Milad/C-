/*
 ============================================================================
 Name        : school mangment system
 Author      : martina milad
 Description : School Impelemantation Source File.
 ============================================================================
 */
 
#include <stdio.h>
#include <stdlib.h>

#include "project.h"
#include "STD_Types.h"

int i;  //counter of the students
int choice;

void Main_Menu()  //to dispaly the menu
{
	printf("=====================================================\n");
	printf("===================  WELCOME SIR  ===================\n");
	printf("=====================================================\n");
	
	printf("\n\t\t**************************************\n");
	printf("\t\t*****  School Management System  *****\n");
	printf("\t\t*****       Martina Milad       *****\n");
	printf("\t\t**************************************\n");
	
	printf("\n\t\t---------------------------------------------\n");
	printf("\t\tchoose one of the following options:\n");
	printf("\t\tTo add a New Student            Enter '1'\n");
	printf("\t\tTo view all Students            Enter '2'\n");
	printf("\t\tTo Delete a  Student            Enter '3'\n");
	printf("\t\tTo Update Student               Enter '4'\n");
	printf("\t\tTo Rank Student                 Enter '5'\n");
	printf("\t\tTo Student Score                Enter '6'\n");
	printf("\t\tTo Exist the School App         Enter '7'\n");
	printf("\t\t ---------------------------------------------\n");
	
	printf("---> Your choice is :\n");
	scanf("%d", &choice);
	fflush(stdin);
}

void Empty_Database() //call it to disolay that the system is empty
{
	
	printf("============================================================\n");
	printf("The List is empty. No Data to view !\n");
	printf("============================================================\n");

}

void  New_Student(student *Data)  //to add a new student in the system
{
    // store information of a student 							
		printf("Enter ID_Student:\n");
        scanf("%d", &Data->ID);
		fflush(stdin);
		
        printf("Enter Phone_Student:\n");
        scanf("%d", &Data->phone_number);
		fflush(stdin);
		
        printf("Enter Name_Student:\n");
        scanf("%[^\n]s", &Data->name);
		fflush(stdin);
		
		printf("Enter Address_Student:\n");
        scanf("%[^\n]s", &Data->address);
		fflush(stdin);
		
		printf("Enter STUDENT_SCORE_Student:\n");
        scanf("%d", &Data->Score);
		fflush(stdin);
		
		printf("Enter the birth-data (day month year):\n");
        scanf("%d %d %d", &Data->day, &Data->month , &Data->year);
		fflush(stdin);
		
		printf("The Student has been added succefully :)\n");

		i = i + 1;  //add counter by one
		
		
}

void printList()     // to print the whole system of the students 
{
	if(i!=0)
	{
		printf("-------------------- The List Of Students --------------------\n");
		printf("============================================================\n");
		for (int k = 0; k < i; k++) 
		{
			if(Stu[k].ID!=0)  /* to avoid printing the empty student (deleted structure)*/
			{
			printf("============================================================\n");
			printf("Student NO. is: %d\n" , Stu[k].ID);
			printf("The Student Name     :%s\n" , Stu[k].name);
			printf("The Student Date     :%d/%d/%d\n", Stu[k].day , Stu[k].month , Stu[k].year);
			printf("The Student ID       :%d\n", Stu[k].ID);
			printf("The Student Address  :%s\n", Stu[k].address);
			printf("The Student Phone    :%d\n", Stu[k].phone_number);
			printf("The Student computer_science score    :%d\n", Stu[k].Score);
			}
		}
	}
	
	else if (i==0){
		Empty_Database();
	}
}

void Delete_Student()  //to delete a student from the system 
{
	int flag = 0 ; 
	int a; //a stores the id of the student to be deleted 
	printf("Enter The ID of Student that you want to delete :\n");
	scanf("%d" , &a);
	fflush(stdin);
	
	for (int k = 0; k <= NumberOfStudents; k++) 
	{
        if (a == Stu[k].ID)  //check if the id exists in the struct 
		{
			Stu[k].ID = 0;
			Stu[k].Score = 0;
			Stu[k].phone_number = 0;
			Stu[k].name[0] = '\0';
			Stu[k].address[0] = '\0';
			Stu[k].day = 0;
			Stu[k].month = 0;
			Stu[k].year = 0;
			flag++;
			break;
        }
    }
	if(flag!=0){
		printf("=============================================\n");
		printf("The Student has been deleted succefully :)\n");
	}
	else if (flag ==0){
		printf("==========================================\n");
		printf("This Student NO. is unavailable !!!\n");
		printf("==========================================\n");
	
	}

}

void Student_Edit()  //to edit or update a student 
{
	int flag = 0;
	int updateID;
	printf("Enter The ID of Student that you want to Update :\n");
	scanf("%d" , &updateID);
	fflush(stdin);
	
	for (int j = 0; j <= NumberOfStudents; j++) 
	{
		if(updateID == Stu[j].ID) //check if the ID exists in the struct 
		{
				New_Student(&Stu[j]);
				flag++;
		}
	}
	if(flag!=0)
		{
			printf("\t\t=================================\n");
			printf("\t\tUpdation Successful!!!\n");
			printf("\t\t=================================\n");
		}
		
		else if (flag ==0){
		printf("==========================================\n");
		printf("Student with id=> %d is not found !!!\n" , updateID );
		printf("==========================================\n");
		}
		
}

void Student_Score(student *Data)  //to edit/enter the score of all the students
{	
	if(i!=0)
	{
		printf("-------------------- The List Of Students --------------------\n");
		for (int k = 0; k < i; k++) 
		{
			printf("The Student ID %d :\n" , Stu[k].ID);
			printf("Computer_science =    :" );
			scanf("%d" , &Stu[k].Score);
			printf("\n=================================================\n");
			printf("The computer_science has been Changed succefully :)\n");
			printf("=================================================\n");			
		}
	}
	else if (i==0){
		Empty_Database();  //the system is empty
	}
	
}

void Rank_Student()  //rank students by thier score , using bubble sort algorithm
{
    student Compare = {0,
						0,	
						0,
						0,
                     0,
                     0,
                     0,
                     0,
                     0};
    if (i == 0)
    {
        printf("the list is empty there is no student to rank\n\n");
    }
    else
    {
        for (int k = 0; k <= i; k++)
        {
            for (int j = k; j < i; j++)
            {
                if (((Stu[k].Score) < (Stu[j].Score)))
                {
                    Compare = Stu[k];
                    Stu[k] = Stu[j];
                    Stu[j] = Compare;
                }
            }
        }
        printf("Ranking is complete,now listing will list all the students ranked.\n");
    }
}
