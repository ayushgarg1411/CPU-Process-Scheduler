/**
 * @file: schedule_sjf.c
 * @author: Ayush Garg, 656665809, F20N01, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: October 29, 2020
 * Comments about schedule_sjf.c goes here.
 *This file schedule the tasks based on its burst time
 *Task with the shortest burst time will be executed First
 *To do so, I simply use a loop that will sort the linked list based on its burst time
 */


 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 //Include necessary header files.

 #include "../include/list.h"
 #include "../include/schedule.h"
 #include "../include/cpu.h"

//Implement all the functions specified in schedule.h file.
//Implement shortest job first scheduling algorithm in this file.


void schedule(listnode** list)
{

  struct node *temp,*temp2;
  struct task *t ;
  struct node *temp1 = NULL;
  int flag = 0;


  do
    {
      flag = 0;
      temp = *list;
      while(temp->next != temp1)
      {
        if(temp->task->burst == temp->next->task->burst)
        {
          temp = temp->next;
          continue;
        }
          if(temp->task->burst > temp->next->task->burst)
          {
            t = temp->task;
            temp->task = temp->next->task;
            temp->next->task = t;
            flag = 1;

          }
            temp = temp->next;
        }
      temp1 = temp;
}while(flag);

temp2 = *list;
while(temp2 != NULL)
{
   run(temp2->task, temp2->task->burst);
   temp2 = temp2->next;
 }

}
