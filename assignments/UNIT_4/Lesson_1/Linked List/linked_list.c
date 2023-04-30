/*
 * linked_list.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */

#include "linked_list.h"

static void Fill_Student_data (Sstudent *pNewStudent) ;

static void view_Student_data (Sstudent *pSelectedStudent) ;


Sstudent *gpFirstStudent = NULL ;

void AddStudent ()
{
	Sstudent *pNewStudent ;
	Sstudent *pLastStudent ;

	if (gpFirstStudent == NULL)
	{
		pNewStudent = (Sstudent*) malloc(sizeof (Sstudent)) ;
		gpFirstStudent = pNewStudent ;
		pNewStudent ->pnextstudent = NULL ;
	}
	else
	{
		pLastStudent = gpFirstStudent ;
		while (pLastStudent->pnextstudent)
		{
			pLastStudent = pLastStudent->pnextstudent ;
		}
		pNewStudent = (Sstudent*) malloc(sizeof (Sstudent)) ;
		pNewStudent->pnextstudent = NULL ;
		pLastStudent->pnextstudent = pNewStudent ;
	}

	// Add the New student student
	Fill_Student_data (pNewStudent) ;
}

void DeleteStudent ()
{
	char temp_text [10] ;
	uint32 SelectedID ;
	Sstudent *pSelcetedStudent = gpFirstStudent ;
	Sstudent *pPreviousStudent =NULL;
	DRINTF ("Enter Student ID to be deleted : ") ;
	gets (temp_text) ;
	SelectedID = atoi (temp_text) ;
	if (gpFirstStudent == NULL)
	{
		DRINTF ("List is empty \n") ;
	}
	else
	{
		while (pSelcetedStudent)
		{
			if (SelectedID == pSelcetedStudent->student.id)
			{
				if (!pPreviousStudent)
				{
					gpFirstStudent = pSelcetedStudent->pnextstudent ;
					free (pSelcetedStudent) ;
					break;
				}
				else
				{
					pPreviousStudent->pnextstudent= pSelcetedStudent->pnextstudent ;
					free (pSelcetedStudent) ;
					break;
				}
			}
			else
			{
				pPreviousStudent = pSelcetedStudent ;
				pSelcetedStudent = pSelcetedStudent->pnextstudent ;
			}
		}
		if (!pSelcetedStudent)
			DRINTF ("The ID Not found \n") ;
	}
}

void ViewStudent ()
{
	Sstudent *pSelectedStudent = gpFirstStudent ;
	uint32 count = 1 ;
	if (gpFirstStudent == NULL)
	{
		DRINTF ("List is empty \n") ;
	}
	else
	{
		while (pSelectedStudent)
		{
			DRINTF ("Record Number %d\n",count) ;
			view_Student_data (pSelectedStudent) ;
			pSelectedStudent = pSelectedStudent->pnextstudent ;
			count++;
		}

	}
}



void DeleteAll ()
{
	Sstudent *pSelectedStudent = gpFirstStudent ;
	Sstudent *temp ;

	while (pSelectedStudent)
	{
		temp = pSelectedStudent ;
		pSelectedStudent = pSelectedStudent->pnextstudent ;
		free (temp) ;
	}

	gpFirstStudent = NULL ;
}

void find_by_ID ()
{
	char temp_text [10] ;
	uint32 SelectedID ;
	Sstudent *pSelcetedStudent = gpFirstStudent ;
	DRINTF ("Enter Student ID : ") ;
	gets (temp_text) ;
	SelectedID = atoi (temp_text) ;
	if (gpFirstStudent == NULL)
	{
		DRINTF ("List is empty \n") ;
	}
	else
	{
		while (pSelcetedStudent)
		{
			if (SelectedID == pSelcetedStudent->student.id)
			{
				break ;
			}
			pSelcetedStudent = pSelcetedStudent->pnextstudent ;
		}
		if (pSelcetedStudent)
		{
			view_Student_data (pSelcetedStudent) ;
		}
		else
		{
			DRINTF ("The ID Not found \n") ;
		}
	}
}


void NumberOFStudents ()
{
	Sstudent *pSelectedStudent = gpFirstStudent ;
	uint32 count = 0 ;
	if (gpFirstStudent == NULL)
	{
		DRINTF ("List is empty \n") ;
	}
	else
	{
		while (pSelectedStudent)
		{
			count++;
			pSelectedStudent=pSelectedStudent->pnextstudent ;
		}
		DRINTF ("Number of Students is %d",count) ;
	}
}

uint32 NumberOFStudentsRECUR (Sstudent *pSelectedStudent)
{
	if (!pSelectedStudent)
	{
		return 0;
	}
	else
	{
		return 1 + NumberOFStudentsRECUR (pSelectedStudent->pnextstudent) ;
	}
}

void find_from_end ()
{
	uint32 lastindex ;
	Sstudent *ptr1 = gpFirstStudent ;
	Sstudent *ptr2 = gpFirstStudent ;
	uint32 count = 0 ;
	DRINTF ("Enter Student index : ") ;
	scanf ("%d",&lastindex) ;
	if (!gpFirstStudent)
	{
		DRINTF ("list is empty\n");
	}
	else
	{
		while (ptr1->pnextstudent)
		{
			ptr1 = ptr1->pnextstudent ;
			count++ ;
			if (count > lastindex-1)
			{
				ptr2 = ptr2->pnextstudent ;
			}
		}
		if (count >= lastindex-1)
		{
			view_Student_data (ptr2) ;
		}
		else
		{
			DRINTF ("index not valid\n") ;
		}
	}
}

void middle_of_list ()
{
	Sstudent *sptr = gpFirstStudent ;
	Sstudent *fptr = gpFirstStudent ;
	if (!gpFirstStudent)
	{
		DRINTF ("list is empty\n");
	}
	else
	{
		while (fptr && fptr->pnextstudent)
		{
			fptr = fptr->pnextstudent->pnextstudent ;
			sptr = sptr->pnextstudent ;
		}
		view_Student_data (sptr) ;
	}
}


void ReverseList ()
{
	Sstudent *pSelectedStudent = gpFirstStudent ;
	Sstudent *pPreviousStudent = NULL ;
	Sstudent *pNextStudent = NULL ;
	if (!gpFirstStudent)
	{
		DRINTF ("list is empty\n");
	}
	else
	{
		while (pSelectedStudent)
		{
			pNextStudent = pSelectedStudent->pnextstudent ;
			pSelectedStudent->pnextstudent = pPreviousStudent ;
			pPreviousStudent = pSelectedStudent ;
			pSelectedStudent = pNextStudent ;
		}
		gpFirstStudent = pPreviousStudent ;
	}
}




static void view_Student_data (Sstudent *pSelectedStudent)
{
	DRINTF ("ID : %d\n",pSelectedStudent->student.id) ;
	DRINTF ("Name : %s\n",pSelectedStudent->student.name) ;
	DRINTF ("Height : %.2f\n",pSelectedStudent->student.height) ;
}


static void Fill_Student_data (Sstudent *pNewStudent)
{
	char temp_text [40] ;
	DRINTF ("Enter the ID : ");
	gets (temp_text) ;
	pNewStudent->student.id = atoi (temp_text) ;
	DRINTF ("Enter Student Full Name : ");
	gets (temp_text) ;
	strcpy (pNewStudent->student.name,temp_text);
	DRINTF ("Enter height : ");
	gets (temp_text) ;
	pNewStudent->student.height = atof (temp_text) ;
}

