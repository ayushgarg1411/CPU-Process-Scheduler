/**
 * @file: schedule.h
 * @author: Humayun Kabir, Instructor, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: August 05, 2020
 *
 * Defines the functions required for a process scheduler.
 *
 */



#ifndef __SCHEDULE_HEADER__
#define __SCHEDULE_HEADER__


#include "list.h"
 
void schedule(listnode** list);
//Schedule the tasks from the task list, implementing any of the following 
//cpu or process scheduling algorithm
//	First Come First Serve
//	Shortest Job First
//	Priority
//	Round Robin
//	Priority Round Robin


#endif
