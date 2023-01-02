/*
 * student.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdint.h>
#include <stdio.h>

#define DPRINTF(...)    {fflush(stdin);\
                        fflush(stdout);\
                        printf(__VA_ARGS__);\
                        fflush(stdin);\
                        fflush(stdout);}

#define name_length 50
#define course_no 5
#define students_no 50

// student data type
typedef struct{
    char fName[name_length];     // student first name
    char lName[name_length];     // student last name
    uint8_t roll;                    // student roll number (unique number)
    float GPA;                   // GPA
    uint8_t cId[course_no];          // course ID 
}Student_Data_t;

typedef enum{
    Student_no_error,
    Student_null
}Student_status;

extern Student_Data_t students[students_no];

// Student supportive functions
void STUDENT_init();

// Student APIs
void STUDENT_add_student_file();
void STUDENT_add_student_manually();
void STUDENT_find_By_rollNum();
void STUDENT_find_By_fName();
void STUDENT_find_Students_Enrolled_In_CourseId();
void STUDENT_total_students();
void STUDENT_del_student();
void STUDENT_update_student();
void STUDENT_show_all_students();

#endif /* STUDENT_H_ */