/*
 * main.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "student.h"
#include "stdio.h"

void main()
{
    DPRINTF("Welcome to Student Management System\n");
    STUDENT_init();
    
    int choice;
    int loop_flag=1;

    while (loop_flag)
    {
        DPRINTF("=================================================\n");
        DPRINTF("Choose the task you want to perform\n");   
        DPRINTF("1. Add the student details from text file\n");
        DPRINTF("2. Add the student details manually\n");
        DPRINTF("3. Find the student details by Roll Number\n");
        DPRINTF("4. Find the student details by First Name\n");
        DPRINTF("5. Find the student details by Course Id\n");
        DPRINTF("6. Find the total number of students\n");
        DPRINTF("7. Delete the student details by Roll Number\n");
        DPRINTF("8. Update the student details by Roll Number\n");
        DPRINTF("9. Show All Students\n");
        DPRINTF("10. To Exit\n");
        DPRINTF("Enter you choice to perform the task: ");

        scanf("%d", &choice);
        DPRINTF("=================================================\n");

        switch (choice)
        {
            case 1:
                STUDENT_add_student_file();
                break;

            case 2:
                STUDENT_add_student_manually();
                break;
            
            case 3:
                STUDENT_find_By_rollNum();
                break;
            
            case 4:
                STUDENT_find_By_fName();
                break;
            
            case 5:
                STUDENT_find_Students_Enrolled_In_CourseId();
                break;
            
            case 6:
                STUDENT_total_students();
                break;
            
            case 7:
                STUDENT_del_student();
                break;
            
            case 8:
                STUDENT_update_student();
                break;
            
            case 9:
                STUDENT_show_all_students();
                break;
            
            case 10:
                loop_flag=0;
                break;
            
            default:
                break;
        }
    }
}