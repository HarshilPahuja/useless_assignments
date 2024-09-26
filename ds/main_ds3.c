#include<stdio.h>
#include <string.h>


int  Q[5]; 
int CQ[2];
int circularrear=0;
int circularfront=0;
int rear = -1;
int front = -1;





int circularisEmpty(){
    if(circularrear==circularfront){
        return 1;
    }
    else{
        return 0;
    }
}
int circularisFull(){
    if((circularrear+1)%2==circularfront){
        return 1;
    }
    else{
        return 0;
    }
}

void circularadd(int CQ[2],int val){
    if (circularisFull()){
        printf("the queue is full.");
    }
    else{
        circularrear=(circularrear+1)%2;
        CQ[circularrear]=val;
    }
}

void circulardel(){
    if (circularisEmpty()){
        printf("its an empty queue");
    }
    else{
        circularfront=(circularfront+1)%2;
        printf("deleted item is %d\n", CQ[circularfront]);
    }
}

int linearisEmpty()
{
    if(rear==front)
       return 1;
    else
       return 0;
}

int linearisFull()
{
    if(rear==4)    
        return 1;
    else
        return 0;
}

void linearadd(int Q[5],int val)
{
    if(linearisFull())
    {
        printf("Queue is Full\n\n");
    }
    else
    {
        rear++;  
        Q[rear]=val; 
        printf("\nElement added id = %d \n",Q[rear]);
    }
}

void lineardel()
{
    if (linearisEmpty())
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nDeleted item is : Id = %d ", Q[front + 1]); 
        front++; 

        
    }
}


void lineardisplay()
{ int i;
   printf ("\n Id : ");
    for(i= front+1;i<=rear;i++)
    {
        printf("\t %d " ,Q[i]);
    }
}
void circulardisplay(){
    int i;
    printf("\n Id: ");
    for(i=circularfront+1;i<=circularrear;i++)
        {
            printf("\t %d " ,CQ[i]);
        }
}


int main() {
     int choice, queueType, value;
     int cont = 1;

     while (cont == 1) {
         printf("Select Queue Type:\n 1) linear queue\n, 2)circular queue\n 3)exit\n");
         scanf("%d", &queueType);

         if (queueType == 3) {
             break;
         }

         switch (queueType) {
             case 1:
                 do {
                     printf("do you want to perform 1) Add, 2)Delete, 3)Display, 4, exit\n");
                     scanf("%d", &choice);

                     switch (choice) {
                         case 1:
                             printf("Enter value to add: ");
                             scanf("%d", &value);
                             linearadd(Q,value);
                             break;
                         case 2:
                             lineardel();
                             break;
                         case 3:
                             lineardisplay();
                             break;
                         case 4:
                             break;
                         default:
                             printf("Invalid choice.\n");
                     }
                 } 
                while (choice != 4);
                 break;

             case 2:
                 do {
                     printf("1)Add, 2)Delete, 3)Display, 4)exit\n");
                     scanf("%d", &choice);

                     switch (choice) {
                         case 1:
                             printf("Enter value to add: ");
                             scanf("%d", &value);
                             circularadd(CQ,value);
                             break;
                         case 2:
                             circulardel();
                             break;
                         case 3:
                             circulardisplay();
                             break;
                         case 4:
                             break;
                         default:
                             printf("Invalid choice.\n");
                     }
                 } while (choice != 4);
                 break;

             default:
                 printf("Invalid choice.\n");
         }

         printf("Do you want to continue? (1 for Yes / 0 for No): ");
         scanf("%d", &cont);
     }

     return 0;
 }

