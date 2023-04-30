/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */

#include"linked_list.h"

void main ()
{
	char text [10] ;
	uint32 length = 0 ;
	while (1)
	{
		DRINTF ("\n	============================\n") ;
		DRINTF ("\tChoose on the following options\n\n") ;
		DRINTF ("1 : Add Student \n") ;
		DRINTF ("2 : Delete Student \n") ;
		DRINTF ("3 : view all Student \n") ;
		DRINTF ("4 : Delete all \n") ;
		DRINTF ("5 : Find by ID \n") ;
		DRINTF ("6 : NumberOFStudents \n") ;
		DRINTF ("7 : NumberOFStudentsRECUR \n") ;
		DRINTF ("8 : find_from_end \n") ;
		DRINTF ("9 : middle_of_list \n") ;
		DRINTF ("10 : ReverseList \n") ;
		DRINTF ("Enter your Choice : ") ;
		gets (text) ;
		DRINTF ("\n	============================\n") ;
		switch (atoi(text))
		{
			case 1:
				AddStudent() ;
				break;
			case 2:
				DeleteStudent() ;
				break;
			case 3:
				ViewStudent() ;
				break ;
			case 4:
				DeleteAll() ;
				break ;
			case 5:
				find_by_ID() ;
				break ;
			case 6:
				NumberOFStudents() ;
				break ;
			case 7:
				length =NumberOFStudentsRECUR(gpFirstStudent) ;
				DRINTF ("Number of Students is %d",length) ;
				break ;
			case 8:
				find_from_end() ;
				break ;
			case 9:
				middle_of_list() ;
				break ;
			case 10:
				ReverseList() ;
				break ;
			default :
				DRINTF ("wrong choice\n") ;
		}
	}
}
