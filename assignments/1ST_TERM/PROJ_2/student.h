/*
 * student.h
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DRINTF(...) { fflush(stdout); \
					  fflush(stdin); \
					  printf (__VA_ARGS__); \
					  fflush(stdout); \
					  fflush(stdin); }

#define Courses_Count 5
// type definition
typedef struct {
	char FirstName[20];
	char LastName[20];
	int ID ;
	float GPA;
	int coursesIDs[Courses_Count] ;
}student;
typedef struct {
	student *base ;
	student *head ;
	student *tail ;
	int count ;
	int length ;
}FIFO_Buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_is_full,
	FIFO_is_empty,
	FIFO_Not_Embty,
	FIFO_error,
	FIFO_NULL
}FIFO_status;

typedef enum
{
	ID_Found,
	ID_NOT_Found
}ID_Status;

//APIs
FIFO_status Student_Data_Base_Init (FIFO_Buf_t *fifo_buf,student *buf , int length );
FIFO_status Add_Student_Manually (FIFO_Buf_t *fifo_buf);
FIFO_status Add_Student_From_File (FIFO_Buf_t *fifo_buf);
FIFO_status search_by_ID (FIFO_Buf_t *fifo_buf);
FIFO_status search_by_First_Name(FIFO_Buf_t *fifo_buf);
FIFO_status search_by_CourseID (FIFO_Buf_t *fifo_buf);
void Count_Of_Students(FIFO_Buf_t *fifo_buf);
FIFO_status Delete_Student (FIFO_Buf_t *fifo_buf);
FIFO_status Update_Student (FIFO_Buf_t *fifo_buf);
FIFO_status Print_All_Students (FIFO_Buf_t *fifo_buf);

#endif /* STUDENT_H_ */
