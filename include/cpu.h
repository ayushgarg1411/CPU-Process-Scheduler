/**
 * @file: cpu.h
 * @author: Humayun Kabir, Instructor, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: August 05, 2020
 *
 * Defines the functions required to simulate cpu cycles.
 *
 */


#ifndef __CPU_HEADER__
#define __CPU_HEADER__

#include "task.h"


#define QUANTUM 10 	//length of a time quantum


void run(const Task *task, const int slice);
// run the specified task for the following time slice


#endif
