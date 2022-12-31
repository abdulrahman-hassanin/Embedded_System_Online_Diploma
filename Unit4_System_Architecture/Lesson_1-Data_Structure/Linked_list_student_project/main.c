/*
 * main.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "linked_list.h"

void main()
{
    char temp_text[40];

    while (1)
    {
        DPRINTF ("\n ===========================");
        DPRINTF ("\n\t Choose one of the following options");
        DPRINTF ("\n 1: AddStudent");
        DPRINTF ("\n 2: DeleteStudent");
        DPRINTF ("\n 3: ViewStudent");
        DPRINTF ("\n 4: DeleteAll");
        DPRINTF ("\n 5: Get nth student");
        DPRINTF ("\n 6: Get the number of students");
        DPRINTF ("\n 7: reverse the list");
        DPRINTF ("\n Enter Option Number: ");
    
        gets(temp_text);
        DPRINTF ("\n ===========================");
        switch(atoi(temp_text))
        {
            case 1:
                AddSudent();
                break;
            case 2:
                DeleteStudent();
                break;
            case 3:
                view_students();
                break;
            case 4:
                delete_all();
                break;
            case 5:
                GetNthStudent();
                break;
            case 6:
                GetLength();
                break;
            case 7:
                ReverstList();
                break;
            default:
                DPRINTF ("\n Wrong option");
                break;

        }
    }   
}