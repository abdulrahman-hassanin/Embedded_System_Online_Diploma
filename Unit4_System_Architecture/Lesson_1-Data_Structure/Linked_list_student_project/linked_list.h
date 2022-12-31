/*
 * linked_list.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)    {fflush(stdin);\
                        fflush(stdout);\
                        printf(__VA_ARGS__);\
                        fflush(stdin);\
                        fflush(stdout);}

// effective data
struct Sdata
{
    int ID;
    char name[40];
    float height;
};

// linked list node
struct SStudent
{
    struct Sdata student;
    struct SStudent* PNextStudent;  
};

void AddSudent();

int DeleteStudent();

void view_students();

void delete_all();

void GetNthStudent();

void GetLength();

void ReverstList();

#endif /* LINKED_LIST_H_ */