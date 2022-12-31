/*
 * linked_list.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "linked_list.h"

struct SStudent* gpFirstStudent = NULL;

// linked list API


void AddSudent()
{
    struct SStudent* pNewStudent;
    struct SStudent* pLastStudent;
    char temp_text[40];

    // check if the list is empty
    if( gpFirstStudent == NULL ) {
        // create new record
        pNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
        // assign it to gpFirst
        gpFirstStudent = pNewStudent;
    }else{
        // navigate until reach to the end node
        pLastStudent = gpFirstStudent;
        while(pLastStudent->PNextStudent)
            pLastStudent = pLastStudent->PNextStudent;
        // create new record
        pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
        pLastStudent->PNextStudent = pNewStudent;
    }

    // fill new record
    DPRINTF ("\n Enter the ID: ");
    gets(temp_text);
    pNewStudent->student.ID = atoi(temp_text);

    
    DPRINTF ("\n Enter student full name: ");
    gets(pNewStudent->student.name);
    
    DPRINTF ("\n Enter the height: ");
    gets(temp_text);
    pNewStudent->student.height = atoi(temp_text);

    // set the next pointer (new student) to null
    pNewStudent->PNextStudent = NULL;
}

int DeleteStudent()
{
    //Get student ID
    char temp_text[40];
    unsigned int id;
    DPRINTF ("\n Enter the ID: ");
    gets(temp_text);
    id = atoi(temp_text);
    
    if(gpFirstStudent) // list is not empty
    {
        struct SStudent* pSelectedStudent = gpFirstStudent;
        struct SStudent* pPreviousStudent = NULL;
        
        // loop on all records
        while(pSelectedStudent)
        {
            if(pSelectedStudent->student.ID == id)
            {
                if(pPreviousStudent) // the first is not the selected one
                {
                    pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;

                }else{
                    // 1st student == ID
                    gpFirstStudent = pSelectedStudent->PNextStudent;
                }
                free(pSelectedStudent);
                return 1;
            }

            pPreviousStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->PNextStudent;
        }
    }

    DPRINTF ("\n cannot find the student ID.");
    return 0;
}

void view_students()
{
    struct SStudent* pSelectedStudent = gpFirstStudent;
    int count = 0;

    if(gpFirstStudent)
    {
        while(pSelectedStudent)
        {
            DPRINTF ("\n recored number %d: ", count+1);
            DPRINTF ("\n Student Name %s: ", pSelectedStudent->student.name );
            DPRINTF ("\n Student ID %d: ", pSelectedStudent->student.ID );
            DPRINTF ("\n Student height %f: ", pSelectedStudent->student.height );

            pSelectedStudent = pSelectedStudent->PNextStudent;
            count++;
        }
    }else{
        DPRINTF ("List is empty\n");
    }
}

void delete_all()
{
    struct SStudent* pSelectedStudent = gpFirstStudent;
    
    if(gpFirstStudent)
    {
        while(pSelectedStudent)
        {
            struct SStudent* pTempStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->PNextStudent;

            free(pTempStudent);
        }
        gpFirstStudent = NULL;
    }else{
        DPRINTF ("List is empty\n");
    }
}

void GetNthStudent()
{
    // get student number 
    char temp_text[40];
    unsigned int studentNth;
    DPRINTF("\n Enter student number: ");
    gets(temp_text);
    studentNth = atoi(temp_text);

    struct SStudent* pCurrStudent = gpFirstStudent;
    int count = 1;
    while (pCurrStudent)
    {
        if(count == studentNth){
            DPRINTF("Student %d data:\n", studentNth);
            DPRINTF ("\n Student Name %s: ", pCurrStudent->student.name );
            DPRINTF ("\n Student ID %d: ", pCurrStudent->student.ID );
            DPRINTF ("\n Student height %f: ", pCurrStudent->student.height );
            
            return;
        }
        count++;
        pCurrStudent = pCurrStudent->PNextStudent;
    }
    
}

void GetLength()
{
    struct SStudent* currStudent = gpFirstStudent;
    int len = 0;
    while (currStudent)
    {
        len++;
        currStudent = currStudent->PNextStudent;
    }
    DPRINTF("The number of student is: %d", len);
}


void ReverstList()
{
    struct SStudent* current = gpFirstStudent;
    struct SStudent* prev = NULL;
    struct SStudent* next = gpFirstStudent;

    while(current)
    {
        next = current->PNextStudent;
        current->PNextStudent = prev;
        prev = current;
        current = next;
    }

    gpFirstStudent = prev;

    printf("\nRevere the list is done");
}