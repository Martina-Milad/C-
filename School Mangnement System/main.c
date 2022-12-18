#include <stdio.h>
#include<stdlib.h>

#include "project.h"
#include "STD_Types.h"

int quit=0; //to escape while 1
int i;
int choice;

void main()
{
	while(!quit)
	{
		Main_Menu();
		switch(choice)
		{
		case(1):
			 New_Student(&Stu[i]);
			break;
		
		case(2):
			printList(&Stu[i]);
			break;
		
		case(3):
			Delete_Student();
			break;
		
		case(4):
			Student_Edit();
			break;
		
		case(5):
			Rank_Student();  
			break;
		
		case(6):
			Student_Score(&Stu[i]);  
			break;
		
		case(7):  /* close the system*/
			quit =1;
			break;
		
		default:
			printf("Invalid choice. Enter a number from 1 to 7\n");
			break;
		}
	}
	

}

