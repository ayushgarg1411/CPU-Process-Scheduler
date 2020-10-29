#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct task {
    char *name;
    int priority;
    int burst;
} Task;


typedef struct node {
	Task* task;
	struct node* next;
} listnode;



void insert(listnode** list, Task* task)
{
  //printf("[%s] [%d] [%d]\n",task->name,task->priority,task->burst);
  listnode* new_node = (listnode *)malloc(sizeof(listnode));
  listnode* last = *list;
  new_node->task = (Task *)malloc(sizeof(Task));
  new_node->task->name = malloc(strlen(task->name) + 1);
  //printf("\n%s\n", temp);
  strcpy(new_node->task->name, task->name);
  //printf(" %s %s\n",new_node->task->name,task->name);
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
  //printf("[%s] [%d] [%d]\n",task->name,task->priority,task->burst);
  }



  void traverse(listnode* list)
  {
    
  	struct node *temp;
    char c[100];
  	if(list != NULL)
  	{
  		temp = list;
  		while(temp != NULL)
  		{
        //c = temp->task->name;
  			printf("[%s] [%d] [%d]",temp->task->name, temp->task->priority, temp->task->burst);
  			printf("\n");
        temp = temp->next;
  		}
  	}
  }



void delete(listnode** list, const Task* task)
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




void add(char* name, const int priority, const int burst, listnode** list)
{
	struct task temp;
	temp.name = name;
	temp.priority = priority;
	temp.burst = burst;

  insert(list, &temp);
}



void load(const char* filename, listnode** list)
{

	FILE *f;
	f=fopen(filename,"r");
  char c[100];
  int d,e;
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
      name = str;
      pt = strtok(str1, ",");
      priority = atoi(pt);
      pt = strtok(str2, ",");
      burst = atoi(pt);
      add(name, priority, burst, list);

    }

	fclose(f);
}

void schedule_sjf(listnode** list)
{

  struct node *temp;
  struct task *t ;
  struct node *temp1 = NULL;
  int flag = 0;


    //temp = *list;
  do
    {
    //  printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
      flag = 0;
      temp = *list;
      while(temp->next != temp1)
      {
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

}

void schedule_pr(listnode** list)
{

  struct node *temp;
  struct task *t ;
  struct node *temp1 = NULL;
  int flag = 0;


    //temp = *list;
  do
    {
    //  printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
      flag = 0;
      temp = *list;
      while(temp->next != temp1)
      {
          if(temp->task->priority < temp->next->task->priority)
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

}


void run(const Task *task, const int slice)
{
  printf("\tRunning task = [%s] [%d] [%d] for %d units.\n", task->name, task->priority, task->burst, slice);
}

void schedule_fcfs(listnode** list)
{
  listnode *temp;
  temp = *list;
  while(temp != NULL)
  {
	   run(temp->task, temp->task->burst);
     temp = temp->next;
   }
}
void schedule_rr(listnode** list)
{
 listnode *temp, *temp2,*temp3;
 Task *t;
 int count=1,flag=1;
 temp = *list;
 t = temp->task;
 temp3 = *list;
 temp2 = *list;
 int fu, cu=0;

 int arr[200],i=0,arr1[200],j=0;



fu = -999;
 //printf("%d\n",fu);
 while(temp != NULL)
 {
   if(fu < temp->task->burst)
   {
     //printf("%d\n", fu);
     fu = temp->task->burst;
     //printf("\t%d\n", fu);
   }
   temp = temp->next;
 }
 fu = fu/10;
 temp = *list;
 while(cu != fu)
 {
     i=0;
     j=0;
     while(temp != NULL)
     {

         if(flag == 1)
         {
           arr[i] = temp->task->burst - 10;

             arr1[i] = 10;
           i++;

         }
         else
         {

           if(arr[i]>9)
           {
            // printf("%d  ", arr[i]);
             arr[i] = arr[i] - 10;
             //printf("%d\n", arr[i]);

               arr1[i] = 10;
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

void schedule_prr(listnode** list)
{
  struct node *temp, *temp2, *temp3,*temp4,*temp5;
  struct task *t ;
  struct node *temp1 = NULL;
  int flag = 0;
  int array[11]={0};
  int fu = -999,arr[200],i=0,arr1[200],j=0,cu=0;



    //temp = *list;
  do
    {
    //  printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
      flag = 0;
      temp = *list;

      while(temp->next != temp1)
      {
          if(temp->task->priority < temp->next->task->priority)
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
  temp3 = *list;
  temp4 = *list;
  temp5 = *list;
  flag=1;
//  while(temp2 != NULL)
  temp = *list;
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

    while(temp3 != NULL)
    {
        array[temp3->task->priority]++;
        temp3 = temp3->next;
    }

    temp3 = *list;
    for(int l=10; l>=1; l--)
    {
        if(array[l]==0)
        {
          //temp3 = temp3->next;
          continue;
        }
        else if(array[l]==1)
        {
          run(temp3->task, temp3->task->burst);
          temp3 = temp3->next;
        }
        else
        {
          run(temp3->task, temp3->task->burst);
          run(temp3->task, temp3->task->burst);
          temp3 = temp3->next;
        }


     }
   }

int main(int argc, char *argv[])

{

  char c;
  FILE *fp;
  struct node *list = NULL;
  if(argc < 2)
  {
    printf("no filename given\n");
    exit(0);
  }

  else if(argc >=2)
  {
        if(fp = fopen(argv[1], "r"))
        {
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
  //schedule_prr(&list);
  //schedule_rr(&list);
  //schedule_fcfs(&list);
  traverse(list);
  //printf("\n\n");
  //schedule_pr(&list);
  //traverse(list);


  return 0;
}
