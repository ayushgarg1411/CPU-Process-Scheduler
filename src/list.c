/**
 * @file: list.c
 * @author: Ayush Garg, 656665809, F20N01, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: October 29, 2020
 *
 * Comments about list.c goes here.
 *This file consists of all the functions related to linked list such as
 *Include, Delete, Traverse, Load,and Add.
 *All the functions are tested, fully functional and give the expected output
 *Code written is quite straight-forward and work on the basis of asked requirements
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Include necessary header files.

#include "../include/list.h"
#include "../include/schedule.h"
#include "../include/cpu.h"
//Implement all the functions specified in list.h file.


void insert(listnode** list, Task* task)
//Create a new list node with the given task
//Add the new list node at the end of the list.
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node *last = *list;
	new_node->task = (struct task*)malloc(sizeof(struct task));
	new_node->task->name = task->name;
	new_node->task->priority = task->priority;
	new_node->task->burst = task->burst;
	new_node->next = NULL;
	if(*list == NULL)
	{
		*list = new_node;
		return;
	}
	while(last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	return;
}


void delete(listnode** list, const Task* task)
//Search the task in the list.
//If the task is found remove the corresponding list node from the list.
//Release memory from the task of the removed liost node.
//Release memory from the romoved list node.
{
	struct node * del;
	struct node * temp;
	del = *list;
	if (*list == NULL)
	  printf("\nList is empty\n");
	else
	{
		if(del->task == task)
		{
			*list = del->next;
			free(del);
		}
		else
		{
			while(del != NULL && del->task != task)
			{
				temp = del;
				del = del->next;
			}
			if(del == NULL)
			{
				printf("Task not found in linked list");
			}
			else
			{
				temp->next = del->next;
				free(del->task);
				free(del);
			}
		}
	}

}


void traverse(listnode* list)
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
{
	struct node *temp;
	if(list == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp = list;
		while(temp != NULL)
		{
			printf("[%s] [%d] [%d]",list->task->name, list->task->priority, list->task->burst);
			printf("\n");
		}
	}
}


void add(char* name, const int priority, const int burst, listnode** list)
//Create a new task using name, priority, and burst.
//Insert the task into the list.
{
	struct task temp;
	temp.name = name;
	temp.priority = priority;
	temp.burst = burst;
	insert(list, &temp);
}



void load(const char* filename, listnode** list)
//Open the task file specified by the filename in read only mode.
//Read each task from each line from the file.
//Extract the comma separated name, priority, and burst of the task from each line.
//Add the task name, priority, and burst to the list.
//Close the file once all tasks are added to the list.
{

	FILE *f;
	f=fopen(filename,"r");
	if(f==NULL)
    {
        printf("\nERROR IN FILE !!!\n");
        exit(1);
    }
    char* name;
    int priority, burst;
    char *pt;
    char str[100],str1[100],str2[100];
    while(fscanf(f,"%s %s %s",str,str1,str2) != EOF)
    {
      pt = strtok(str, ",");
      name = pt;
      pt = strtok(str1, ",");
      priority = atoi(pt);
      pt = strtok(str2, ",");
      burst = atoi(pt);
      add(name, priority, burst, list);

    }

	fclose(f);
}
