/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */

#include "student.h"
#define Num_Of_Students 50

student Student_List[Num_Of_Students];
FIFO_Buf_t student_Buf ;

int main ()
{
	Student_Data_Base_Init (&student_Buf, Student_List,(int) Num_Of_Students);
	char text [3] ;
	while (1)
	{
		DRINTF ("\n	============================\n") ;
		DRINTF ("\tChoose on the following options\n\n") ;
		DRINTF ("1 : Add Students From File \n") ;
		DRINTF ("2 : Add Student Manually \n") ;
		DRINTF ("3 : Find by ID \n") ;
		DRINTF ("4 : Find by First Name \n") ;
		DRINTF ("5 : Find by CourseID \n") ;
		DRINTF ("6 : Number OF Students \n") ;
		DRINTF ("7 : Delete Student \n") ;
		DRINTF ("8 : Update Student \n") ;
		DRINTF ("9 : Show All Students \n") ;
		DRINTF ("10 : Exit  \n") ;
		DRINTF ("Enter your Choice : ") ;
		gets (text) ;
		DRINTF ("\n	============================\n") ;
		switch (atoi(text))
		{
		case 1:
			Add_Student_From_File(&student_Buf);
			break;
		case 2:
			Add_Student_Manually(&student_Buf);
			break;
		case 3:
			search_by_ID(&student_Buf);
			break ;
		case 4:
			search_by_First_Name(&student_Buf);
			break ;
		case 5:
			search_by_CourseID(&student_Buf);
			break ;
		case 6:
			Count_Of_Students(&student_Buf);
			break ;
		case 7:
			Delete_Student(&student_Buf);
			break ;
		case 8:
			Update_Student(&student_Buf);
			break ;
		case 9:
			Print_All_Students(&student_Buf);
			break ;
		case 10:
			return 0;
			break ;
		default :
			DRINTF ("wrong choice\n") ;
		}
	}
	return 0;
}
