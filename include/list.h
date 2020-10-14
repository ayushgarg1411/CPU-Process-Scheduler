/**
 * @file: list.h
 * @author: Humayun Kabir, Instructor, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: August 05, 2020
 *
 * Defines the data structure and the functions for a single linked list of cpu tasks.
 *
 */



#ifndef __LIST_HEADER__
#define __LIST_HEADER__

#include "task.h"


typedef struct node {
	Task* task;
	struct node* next;
} listnode;



void insert(listnode** list, Task* task);
//Create a new list node with the given task
//Add the new list node at the end of the list.


void delete(listnode** list, const Task* task);
//Search the task in the list.
//If the task is found remove the corresponding list node from the list.
//Release memory from the task of the removed liost node.
//Release memory from the romoved list node.



void add(char* name, const int priority, const int burst, listnode** list);
//Create a new task using name, priority, and burst.
//Insert the task into the list.


void load(const char* filename, listnode** list);
//Open the task file specified by the filename in read only mode.
//Read each task from each line from the file.
//Extract the comma separated name, priority, and burst of the task from each line.
//Add the task name, priority, and burst to the list.
//Close the file once all tasks are added to the list.



void traverse(listnode* list);
//Loop through the task list.
//Display each task in a separate line as follows:
//	[T1] [4] [20]
//	[T2] [3] [25]
//	[T3] [3] [25]
//	[T4] [5] [15]
//	[T5] [5] [20]
//	[T6] [1] [10]
//	[T7] [3] [30]
//	[T8] [10] [25]


#endif
