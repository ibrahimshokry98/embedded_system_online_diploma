/*
 * Student.c
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */


#include "student.h"

static void Print_Student(student* PselectedStudent);
static ID_Status ID_Check (FIFO_Buf_t *fifo_buf,int ID);

FIFO_status Student_Data_Base_Init (FIFO_Buf_t *fifo_buf,student *buf , int length )
{
	if ( !fifo_buf || !buf )
	{
		printf ("initialization Failed ----> NULL Pointer Passed\n");
		return FIFO_NULL ;
	}


	fifo_buf->base = buf ;
	fifo_buf->head = buf ;
	fifo_buf->tail = buf ;
	fifo_buf->count = 0 ;
	fifo_buf->length = length ;
	return FIFO_no_error;
}

FIFO_status Add_Student_Manually (FIFO_Buf_t *fifo_buf)
{
	if (!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DRINTF ("ERROR !!!!, NULL is passed\n");
		return FIFO_NULL;
	}

	// check if Buffer is full ;
	if (fifo_buf->count == fifo_buf->length)
	{
		DRINTF ("The list is full\n");
		return FIFO_is_full ;
	}

	DRINTF ("----------------------------------------------\n");
	DRINTF ("Add student Manually: \n");
	DRINTF ("----------------------------------------------\n");

	int temp_ID;
	// ADD Student Data
	DRINTF ("ENTER Student's ID : ");
	scanf ("%d",&temp_ID);

	// Check For Duplicated ID
	if (ID_Check(fifo_buf,temp_ID)==ID_Found)
	{
		DRINTF ("This ID already Exists\n");
		return FIFO_error;
	}

	// Continue ADDing data
	fifo_buf->head->ID =temp_ID ;
	DRINTF ("Enter your First Name : ");
	gets (fifo_buf->head->FirstName);

	DRINTF ("Enter your Last Name : ");
	gets (fifo_buf->head->LastName);

	DRINTF ("Enter your GPA : ");
	scanf ("%f",&fifo_buf->head->GPA);

	for (int i=0;i<Courses_Count;i++)
	{
		DRINTF ("ENTER %d Course ID : ",i+1);
		scanf("%d",&fifo_buf->head->coursesIDs[i]);
	}

	fifo_buf->count++;
	if (fifo_buf->head == (fifo_buf->base + fifo_buf->length - 1))
	{
		fifo_buf->head = fifo_buf->base;
	}
	else
	{
		fifo_buf->head++;
	}

	DRINTF ("----------------------------------------------\n");
	DRINTF ("Student Details Added successfully\n");
	DRINTF ("----------------------------------------------\n");
	Count_Of_Students(fifo_buf);
	return FIFO_no_error;
}

FIFO_status Add_Student_From_File (FIFO_Buf_t *fifo_buf)
{
	if (!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DRINTF ("ERROR !!!!, NULL is passed\n");
		return FIFO_NULL;
	}

	// check if Buffer is full ;
	if (fifo_buf->count == fifo_buf->length)
	{
		DRINTF ("The list is full\n");
		return FIFO_is_full ;
	}
	FILE *Student_Data_File;
	student NewStudent ;
	int count =0;

	Student_Data_File = fopen("StudentData.txt","r");

	if (!Student_Data_File)
	{
		DRINTF ("StudentData File Can't be Open\n");
		return FIFO_error;
	}
	while (!feof(Student_Data_File))
	{

		if (fifo_buf->count==fifo_buf->length)
		{
			DRINTF ("The list is full\n");
			return FIFO_is_full ;
		}
		fscanf(Student_Data_File,"%d",&NewStudent.ID);
		// Check For Duplicated ID
		if (ID_Check(fifo_buf,NewStudent.ID)==ID_Found)
		{
			DRINTF ("This ID %d already Exists\n",NewStudent.ID);
			fscanf(Student_Data_File, "%*[^\n]");
			continue;
		}
		fscanf(Student_Data_File,"%s",NewStudent.FirstName);
		fscanf(Student_Data_File,"%s",NewStudent.LastName);
		fscanf(Student_Data_File,"%f",&NewStudent.GPA);
		for (int i=0;i<Courses_Count;i++)
		{
			fscanf(Student_Data_File,"%d",&NewStudent.coursesIDs[i]);
		}
		//Add the New Student to the list
		*(fifo_buf->head) = NewStudent ;
		if (fifo_buf->head == (fifo_buf->base + fifo_buf->length - 1))
		{
			fifo_buf->head = fifo_buf->base;
		}
		else
		{
			fifo_buf->head++;
		}
		fifo_buf->count++;

		DRINTF ("Student with ID is %d Added Successfully\n",NewStudent.ID);
		count++;
	}
	fclose(Student_Data_File);
	DRINTF ("---------------------------------\n");
	DRINTF ("%d Students Added Successfully\n",count);
	return FIFO_no_error;
}

FIFO_status search_by_ID (FIFO_Buf_t *fifo_buf)
{
	if (!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DRINTF ("ERROR !!!!, NULL is passed\n");
		return FIFO_NULL;
	}
	// check if Buffer is empty ;
	if (fifo_buf->count == 0)
	{
		DRINTF ("The list is empty\n");
		return FIFO_is_empty ;
	}
	DRINTF ("----------------------------------------------\n");
	DRINTF ("Search by ID: \n");
	DRINTF ("----------------------------------------------\n");
	int ID;
	student *temp = fifo_buf->tail ;
	DRINTF ("ENTER student's ID : ");
	scanf ("%d",&ID);
	for (int i=0;i<fifo_buf->count;i++)
	{
		if (temp->ID == ID)
		{
			break ;
		}
		if (temp == (fifo_buf->base + fifo_buf->length - 1))
		{
			temp = fifo_buf->base;
		}
		else
		{
			temp++;
		}

	}
	if (temp->ID == ID)
	{
		Print_Student (temp);
	}
	else
	{
		DRINTF ("This ID NOT Found\n");
	}
	return FIFO_no_error;
}
FIFO_status search_by_First_Name(FIFO_Buf_t *fifo_buf)
{
	if (!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DRINTF ("ERROR !!!!, NULL is passed\n");
		return FIFO_NULL;
	}
	// check if Buffer is empty ;
	if (fifo_buf->count == 0)
	{
		DRINTF ("The list is empty\n");
		return FIFO_is_empty ;
	}
	DRINTF ("----------------------------------------------\n");
	DRINTF ("Search by First Name: \n");
	DRINTF ("----------------------------------------------\n");
	char Name[20];
	student *temp = fifo_buf->tail ;
	DRINTF ("ENTER student's ID : ");
	gets (Name);
	int flag = 0;
	for (int i=0;i<fifo_buf->count;i++)
	{
		if (strcmp(Name,temp->FirstName)==0)
		{
			flag++;
			Print_Student (temp);
		}
		if (temp == (fifo_buf->base + fifo_buf->length - 1))
		{
			temp = fifo_buf->base;
		}
		else
		{
			temp++;
		}

	}
	if (flag == 0)
	{
		DRINTF ("THE NAME YOU ENTERED NOT FOUND\n");
	}

	return FIFO_no_error;
}
FIFO_status search_by_CourseID (FIFO_Buf_t *fifo_buf)
{
	if (!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DRINTF ("ERROR !!!!, NULL is passed\n");
		return FIFO_NULL;
	}
	// check if Buffer is empty ;
	if (fifo_buf->count == 0)
	{
		DRINTF ("The list is empty\n");
		return FIFO_is_empty ;
	}
	DRINTF ("----------------------------------------------\n");
	DRINTF ("Search by course ID: \n");
	DRINTF ("----------------------------------------------\n");
	int CourseID ;
	int flag=0;
	DRINTF ("ENTER Course ID: ");
	scanf ("%d",&CourseID);
	student* temp = fifo_buf->tail ;
	for (int i=0;i<fifo_buf->count;i++)
	{
		for (int i=0;i<Courses_Count;i++)
		{
			if (temp->coursesIDs[i]==CourseID)
			{
				DRINTF ("First Name : %s\n",temp->FirstName);
				DRINTF ("Last Name : %s\n",temp->LastName);
				DRINTF ("Student ID : %d\n",temp->ID);
				DRINTF ("Student GPA : %.1f\n",temp->GPA);
				flag++;
				break;
			}
		}
		if (temp == (fifo_buf->base + fifo_buf->length - 1))
		{
			temp = fifo_buf->base;
		}
		else
		{
			temp++;
		}

	}
	if (flag==0)
	{
		DRINTF ("NO student registered for this Course.\n");
	}
	else
	{
		DRINTF ("%d student registered for this Course.\n",flag);
	}
	return FIFO_no_error ;
}

void Count_Of_Students(FIFO_Buf_t *fifo_buf)
{
	DRINTF ("[INFO] The total number of students is %d\n",fifo_buf->count);
	DRINTF ("[INFO] You can add up to %d students\n",fifo_buf->length);
	DRINTF ("[INFO] You can add %d more students\n",fifo_buf->length-fifo_buf->count);
}

FIFO_status Delete_Student (FIFO_Buf_t *fifo_buf)
{
	if (!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DRINTF ("ERROR !!!!, NULL is passed\n");
		return FIFO_NULL;
	}
	// check if Buffer is empty ;
	if (fifo_buf->count == 0)
	{
		DRINTF ("The list is empty\n");
		return FIFO_is_empty ;
	}
	DRINTF ("----------------------------------------------\n");
	DRINTF ("Delete Student: \n");
	DRINTF ("----------------------------------------------\n");
	int ID;
	student* current = fifo_buf->tail ;
	student* next = fifo_buf->tail + 1;
	DRINTF ("ENTER student's ID : ");
	scanf ("%d",&ID);
	int flag = 0;
	for (int i=0;i<fifo_buf->count;i++)
	{
		if (current->ID == ID)
		{
			flag = 1;
		}
		if (flag == 1)
		{
			*current = *next ;
		}
		if (current == (fifo_buf->base + fifo_buf->length - 1))
		{
			current = fifo_buf->base;
		}
		else
		{
			current++;
		}
		if (next == (fifo_buf->base + fifo_buf->length - 1))
		{
			next = fifo_buf->base;
		}
		else
		{
			next++;
		}
	}
	if (flag == 1)
	{
		DRINTF ("Student Deleted Successfully\n");
		fifo_buf->head--;
		fifo_buf->count--;
	}
	else
	{
		DRINTF ("student ID NOT Found\n");
	}
	return FIFO_no_error;
}

FIFO_status Update_Student (FIFO_Buf_t *fifo_buf)
{
	if (!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DRINTF ("ERROR !!!!, NULL is passed\n");
		return FIFO_NULL;
	}
	// check if Buffer is empty ;
	if (fifo_buf->count == 0)
	{
		DRINTF ("The list is empty\n");
		return FIFO_is_empty ;
	}
	DRINTF ("----------------------------------------------\n");
	DRINTF ("Update Student: \n");
	DRINTF ("----------------------------------------------\n");
	int ID;
	student* temp = fifo_buf->tail ;
	DRINTF("Enter student's ID you want to Update: ");
	scanf ("%d",&ID);
	int flag =0;
	for (int i=0;i<fifo_buf->count;i++)
	{
		if (temp->ID == ID)
		{
			flag=1;
			break;
		}
		if (temp == (fifo_buf->base + fifo_buf->length - 1))
		{
			temp = fifo_buf->base;
		}
		else
		{
			temp++;
		}
	}
	if (flag==0)
	{
		DRINTF ("Student ID NOT Found\n");
		return FIFO_no_error;
	}
	else
	{
		DRINTF ("1- First Name\n");
		DRINTF ("2- Last Name\n");
		DRINTF ("3- ID\n");
		DRINTF ("4- GPA\n");
		DRINTF ("5- Courses\n");

		int choice=0;
		int NewID;
		DRINTF ("Enter your Choice: ");
		scanf ("%d",&choice);
		switch (choice)
		{
		case 1:
			DRINTF ("Enter the New First Name : ");
			gets (temp->FirstName);
			break;
		case 2:
			DRINTF ("Enter the New Last Name : ");
			gets (temp->LastName);
			break;
		case 3:
			DRINTF ("Enter the New ID : ");
			scanf ("%d",&NewID);
			if (ID_Check(fifo_buf,NewID)==ID_Found)
			{
				printf ("The New ID already exists\n");
				return FIFO_error;
			}
			temp->ID = NewID;
			break;
		case 4:
			DRINTF ("Enter the New GPA : ");
			scanf ("%f",&temp->GPA);
			break;
		case 5:
			for (int i=0;i<Courses_Count;i++)
			{
				DRINTF ("Enter %d courseID : ",i+1);
				scanf ("%d",&temp->coursesIDs[5]);
			}
			break;
		}
	}
	DRINTF("-------------UPDATE DONE SUCCESSFULLY-------------\n");
	return FIFO_no_error;
}

static ID_Status ID_Check (FIFO_Buf_t *fifo_buf,int ID)
{
	student *temp = fifo_buf->tail ;
	for (int i=0;i<fifo_buf->count;i++)
	{
		if (temp->ID == ID)
		{
			return ID_Found ;
		}
		if (temp == (fifo_buf->base + fifo_buf->length - 1))
		{
			temp = fifo_buf->base;
		}
		else
		{
			temp++;
		}
	}

	return ID_NOT_Found ;
}

FIFO_status Print_All_Students (FIFO_Buf_t *fifo_buf)
{
	if (!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DRINTF ("ERROR !!!!, NULL is passed\n");
		return FIFO_NULL;
	}
	// check if Buffer is empty ;
	if (fifo_buf->count == 0)
	{
		DRINTF ("The list is empty\n");
		return FIFO_is_empty ;
	}
	student *temp = fifo_buf->tail ;
	for (int i=0;i<fifo_buf->count;i++)
	{
		Print_Student(temp);
		DRINTF ("-------------------------------------------\n");
		if (temp == (fifo_buf->base + fifo_buf->length - 1))
		{
			temp = fifo_buf->base;
		}
		else
		{
			temp++;
		}
	}
	return FIFO_no_error;
}

static void Print_Student(student* PselectedStudent)
{
	DRINTF ("\t\tStudent Details Are : \n");
	DRINTF ("First Name : %s\n",PselectedStudent->FirstName);
	DRINTF ("Last Name : %s\n",PselectedStudent->LastName);
	DRINTF ("Student ID : %d\n",PselectedStudent->ID);
	DRINTF ("Student GPA : %.1f\n",PselectedStudent->GPA);
	for (int i=0;i<Courses_Count;i++)
	{
		DRINTF ("Course %d ID : %d\n",i+1,PselectedStudent->coursesIDs[i]);
	}

}

