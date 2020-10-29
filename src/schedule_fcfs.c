/**
 * @file: schedule_fcfs.c
 * @author: Ayush Garg, 656665809, F20N01, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: October 29, 2020
 *
 * Comments about schedule_fcfs.c goes here.
 *The basic functionality of fcfs is to print the tasks in the order they arrived
 *Therefore by simply lefting the function emply, I am getting the reuired results
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 //Include necessary header files.

 #include "../include/list.h"
 #include "../include/schedule.h"
 #include "../include/cpu.h"


//Implement all the functions specified in schedule.h file.
//Implement first come first serve scheduling algorithm in this file.

void schedule(listnode** list)
{
  listnode *temp;
  temp = *list;
  while(temp != NULL)
  {
	   run(temp->task, temp->task->burst);
     temp = temp->next;
   }
}
