/**
 * @file: cpu.c
 * @author: Ayush Garg, 656665809, F20N01, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: October 29, 2020
 *
 * Comments about cpu.c goes here.
 *This file consists of the function related to reun and print the given list of tasks
 *Function below is tested, fully functional and give the expected output
 *Code written is quite straight-forward and work on the basis of asked requirements
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 //Include necessary header files.

 #include "../include/list.h"
 #include "../include/schedule.h"
 #include "../include/cpu.h"



//Implement all the functions specified in cpu.h file.
void run(const Task *task, const int slice)
// run the specified task for the following time slice
{
  printf("\tRunning task = [%s] [%d] [%d] for %d units.\n", task->name, task->priority, task->burst, slice);
}
