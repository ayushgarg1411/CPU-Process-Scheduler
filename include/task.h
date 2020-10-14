/**
 * @file: task.h
 * @author: Humayun Kabir, Instructor, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: August 05, 2020
 *
 * Defines the data structure for a cpu task.
 *
 */



#ifndef __TASK_HEADER__
#define __TASK_HEADER__


#define MIN_PRIORITY 1  	//The minimum priority of a task
#define MAX_PRIORITY 10		//The maxumum priority of a task
#define TASK_SIZE 100



// The data structure of a task
typedef struct task {
    char *name;
    int priority;
    int burst;
} Task;


#endif
