/**
 * @file: schedule_rr.c
 * @author: Ayush Garg, 656665809, F20N01, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: October 29, 2020
 *
 * Comments about schedule_rr.c goes here.
 This file shows the code of round robin algorithm
 *It is based on the QUANTUM number 10
 *This file compiles, and runs perfectly file for round robin algorithm
 *
 */



//Include necessary header files.
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
 listnode *temp, *temp2;
 int count=1,flag=1;
 temp = *list;

 temp2 = *list;
 int fu, cu=0;

 int arr[200],i=0,arr1[200];



fu = -999;
 while(temp != NULL)
 {
   if(fu < temp->task->burst)
   {
     fu = temp->task->burst;
   }
   temp = temp->next;
 }
 fu = fu/10;
 temp = *list;
 while(cu != fu)
 {
     i=0;
     while(temp != NULL)
     {

         if(flag == 1)
         {
           arr[i] = temp->task->burst - QUANTUM;

             arr1[i] = QUANTUM;
           i++;

         }
         else
         {

           if(arr[i]>9)
           {
             arr[i] = arr[i] - QUANTUM;

               arr1[i] = QUANTUM;
             i++;
           }
           else
           {
             if(arr[i] == 0)
             {
               arr1[i] = 0;
               i++;
             }
             else
             {
               arr1[i] = arr[i];
               arr[i] = 0;
               i++;
            }
           }
         }
         temp= temp->next;
     }
     flag++;
     temp = *list;

     i=0;

      printf("\t\tRound %d\n",count);

     while(temp2 != NULL)
     {
       if(arr1[i]>0)
       {
        run(temp2->task, arr1[i]);
       }

        temp2 = temp2->next;
        i++;
      }
      temp2 = *list;
      count++;
      cu++;
      i=0;

    }
  }

//Implement all the functions specified in schedule.h file.
//Implement round robin scheduling algorithm in this file.
