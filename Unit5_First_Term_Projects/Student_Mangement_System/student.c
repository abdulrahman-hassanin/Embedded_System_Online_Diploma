/*
 * student.c
 *
 * Author: Abdulrahman Hassanin
 */

#include "student.h"
#include "fifo.h"
#include "string.h"
#include "stdlib.h"

Student_Data_t students[students_no];
FIFO_Buf_t fifo_buf;

// student supportive functions
void STUDENT_init()
{
    FIFO_init(&fifo_buf, students, students_no);
}

void Enter_Student_Data(Student_Data_t* student_temp)
{
    DPRINTF("Enter the student first name: ");
    gets(student_temp->fName);   
    DPRINTF("Enter the student last name: ");
    gets(student_temp->lName);   
    DPRINTF("Enter the student rolling number: ");
    scanf("%d", &student_temp->roll);
    DPRINTF("Enter the student GPA: ");
    scanf("%f", &student_temp->GPA);  

    for(uint8_t i=0; i<course_no; i++){
        DPRINTF("Enter the student course %d ID: ", i+1);
        scanf("%d", &student_temp->cId[i]);
    }
}

void show_student(Student_Data_t* student)
{
    DPRINTF("================= [Info] The student details are ================\n");
    DPRINTF("   Student Roll Number: %d\n", student->roll);
    DPRINTF("   First Name: %s\n", student->fName);
    DPRINTF("   Last Name: %s\n", student->lName);
    DPRINTF("   GPA: %f\n", student->GPA);
    DPRINTF("   Enrolled courses: ");
    for(uint8_t i=0; i<course_no; i++)
        DPRINTF("%d ", student->cId[i]);
    DPRINTF("\n");
}

// Student APIs
void STUDENT_add_student_file()
{
    FILE* file;
 
    // Opening file in reading mode
    file = fopen("text.txt", "r");
 
    if (file == NULL) {
        DPRINTF("[ERROR] text.txt file can't be opened \n");
    }
 
    Student_Data_t student;
    while (!feof(file))
    {
        // read student data
        fscanf(file, "%s", student.fName);
        fscanf(file, "%s", student.lName);
        fscanf(file, "%d", &student.roll);
        fscanf(file, "%f", &student.GPA);
        for(uint8_t i=0; i<course_no; i++)
            fscanf(file, "%d", &student.cId[i]);

        // Insert the student into database
        // check if the student is already exist
        if(FIFO_IS_Student_Exist(&fifo_buf, &student, student.roll)){
            DPRINTF("[ERROR] Roll number %d is already taken\n", student.roll);
        }
        else{
            uint8_t status = FIFO_enqeue(&fifo_buf, student);
            if(status == FIFO_null){
                DPRINTF("[ERROR] the student buffer is NULL\n");
            }else if(status == FIFO_full){
                DPRINTF("[ERROR] the student buffer is FULL\n");
            }else{
                DPRINTF("[Info] Student Details is added successfully\n");
            }
        }
    }
     
    // Closing the file
    fclose(file);
}

void STUDENT_add_student_manually()
{
    Student_Data_t student_temp;
    Enter_Student_Data(&student_temp);

    // check if the student is already exist
    if(FIFO_IS_Student_Exist(&fifo_buf, &student_temp, student_temp.roll)){
        DPRINTF("[ERROR] Roll number %d is already taken\n", student_temp.roll);
    }
    else{
        uint8_t status = FIFO_enqeue(&fifo_buf, student_temp);
        if(status == FIFO_null){
            DPRINTF("[ERROR] the student buffer is NULL\n");
        }else if(status == FIFO_full){
            DPRINTF("[ERROR] the student buffer is FULL\n");
        }else{
            DPRINTF("[Info] Student Details is added successfully\n");
        }
    }
}

void STUDENT_find_By_rollNum()
{    
    uint8_t id;
    DPRINTF("Enter Student Roll number: ");
    scanf("%d", &id);
    
    Student_Data_t student_temp;

    // check if the student is already exist
    if(FIFO_IS_Student_Exist(&fifo_buf, &student_temp, id)){
        show_student(&student_temp);
    }
    else{
        DPRINTF("[ERROR] Student not found!");
    }
}

void STUDENT_find_By_fName()
{
    char fName[50];
    DPRINTF("Enter Student first name: ");
    gets(fName);

    Student_Data_t* student_temp = fifo_buf.tail;
    for(uint8_t i=0; i<fifo_buf.count; i++){
        if(strcmp(fName, student_temp->fName) == 0){     // found
            show_student(student_temp);
            return;
        }else{
            // circular fifo
            if(student_temp == (fifo_buf.base + (fifo_buf.length * sizeof(element_type))))
                student_temp = fifo_buf.base;
            else
                student_temp++;
        }
    }

    // not found
    DPRINTF("[ERROR] The student is no found\n");
}

void STUDENT_find_Students_Enrolled_In_CourseId()
{
    uint8_t course_id;
    DPRINTF("Enter the course ID: ");
    scanf("%d", &course_id);

    Student_Data_t* student_temp = fifo_buf.tail;
    for(uint8_t i=0; i<fifo_buf.count; i++){
        for(uint8_t j=0; j<course_no; j++){
            if(student_temp->cId[j] == course_id){     // found
                show_student(student_temp);
                break;
            }
        }
        
        // circular fifo
        if(student_temp == (fifo_buf.base + (fifo_buf.length * sizeof(element_type))))
            student_temp = fifo_buf.base;
        else
            student_temp++;

    }
}

void STUDENT_total_students()
{
    DPRINTF("[Info] Total number of students are: %d", fifo_buf.count);
}

void STUDENT_del_student()
{
    uint8_t id;
    DPRINTF("Enter the student rolling number: ");
    scanf("%d", &id);

    Student_Data_t* student_temp = fifo_buf.tail;
    for(uint8_t i=0; i<fifo_buf.count; i++){
        if(student_temp->roll == id){     // found
            // delete student
            if(FIFO_deqeue(&fifo_buf, student_temp) == FIFO_no_error)
                DPRINTF("[Info] The student is deleted successfully\n");
        }
        
        // circular fifo
        if(student_temp == (fifo_buf.base + (fifo_buf.length * sizeof(element_type))))
            student_temp = fifo_buf.base;
        else
            student_temp++;
    }
}

void STUDENT_update_student()
{
    uint8_t id, option;
    DPRINTF("Enter Student Roll number: ");
    scanf("%d", &id);
    
    Student_Data_t* student_temp = fifo_buf.tail;
    for(uint8_t i=0; i<fifo_buf.count; i++){
        if(student_temp->roll == id){     // found
            show_student(student_temp);

            DPRINTF("1 Update First Name\n");
            DPRINTF("2 Update Last Name\n");
            DPRINTF("3 Update Rolling Number\n");
            DPRINTF("4 Update GPA\n");
            DPRINTF("5 Update course id\n");
            DPRINTF("Enter which data you want to modified: ");
            scanf("%d", &option);

            switch (option)
            {
                case 1:
                    DPRINTF("Enter the new First Name: ");
                    gets(student_temp->fName);
                    break;
                
                case 2:
                    DPRINTF("Enter the new Last Name: ");
                    gets(student_temp->lName);
                    break;
                
                case 3:
                    DPRINTF("Enter the new rolling number: ");
                    scanf("%d", &student_temp->roll);
                    break;
                
                case 4:
                    DPRINTF("Enter the new GPA: ");
                    scanf("%f", &student_temp->GPA);
                    break;
                    
                case 5:
                    DPRINTF("Enter the new courses: ");
                    for(uint8_t i=0; i<course_no; i++)
                        scanf("%d", &student_temp->cId[i]);
                    break;
                
                default:
                    break;
            }

            DPRINTF("================ [Info] The Updated student =============\n");
            show_student(student_temp);

        }else{
            // circular fifo`
            if(student_temp == (fifo_buf.base + (fifo_buf.length * sizeof(element_type))))
                student_temp = fifo_buf.base;
            else
                student_temp++;
        }
    }
}

void STUDENT_show_all_students()
{
    if(fifo_buf.count == 0){
        DPRINTF("[ERROR] There is no students to desplay\n");
    }else{
        Student_Data_t* student_temp = fifo_buf.tail;
        for(uint8_t i=0; i<fifo_buf.count; i++){
            show_student(student_temp);
            // circular fifo
            if(student_temp == (fifo_buf.base + (fifo_buf.length * sizeof(element_type))))
                student_temp = fifo_buf.base;
            else
                student_temp++;
        }
    }
}