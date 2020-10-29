/**
 * @file: scheduler.c
 * @author: Ayush Garg, 656665809, F20N01, CSCI 360, VIU
 * @version: 1.0.0
 * @modified: October 29, 2020
 *
 * Comments about scheduler.c goes here.
 *This file accepts the file name as a command line argument
 *then it starts its validation process in case if file donot exist or null
 *Once the validation is completed, it send the task list to load
 *After that it send the task list to schedule
 */



/*
 * Include necessary header files.
 */
#include<stdio.h>
#include<stdlib.h>

/*
 * Reference to the head of the task list.
 */
 #include "../include/list.h"
 #include "../include/schedule.h"
 #include "../include/cpu.h"



listnode *list = NULL;

int main(int argc, char *argv[])
//Check whether the task file name has been given as the command line argument or not.
//If not given, report it to the user and exit the program.
//If given, open the file in read only mode and load the tasks to the task list from the file.
//Show the loaded tasks.
//Schedule the tasks of the list
{


    FILE *fp;
    char c;

    if(argc < 2)
    {
      printf("no filename given\n");
      exit(0);
    }

    else if(argc >=2)
    {
          if((fp = (fopen(argv[1], "r"))))
          {
            c = fgetc(fp);
            while (c != EOF)
            {
                printf ("%c", c);
                c = fgetc(fp);
            }
            printf("\n");
            fclose(fp);
           load(argv[1], &list);
          }
          else
          {
            printf("file do not exist\n");
          }

    }
    else
    {
      printf("I don't know why I am here\n");
    }
    schedule(&list);

    return 0;
}
