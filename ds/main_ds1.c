#include <stdio.h>
struct std{
  int PRN;
  int rno;
  char name[100];
};

int main()
{  
  int choice;
  int n;
  printf("Number of students = \n");  
  scanf("%d" ,
    &n);
  struct std st[n];
  printf("Enter data of students:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name = \n");
        scanf("%s", st[i].name);
        printf("Enter the Roll Number = \n");
        scanf("%d", &st[i].rno);
        printf("Enter the PRN =  \n");
        scanf("%d", &st[i].PRN);
    }
  
  printf("Enter 1 for Bubble Sort. \n");
  printf("Enter 2 for Selection Sort. \n");
  printf("Enter 3 for Insertion Sort. \n");
  printf("Enter your choice: \n");
  scanf("%d" , &choice);

 
  switch(choice)
  //n-1 comparisons n-1 passes
  {
    
    
    case 1:
    for(int i=0; i<n-1; i++) 
    {
      for(int j=0; j<n-i-1; j++)//for reducing number of comparisons in each pass
      {
        if(st[j].rno > st[j+1].rno)
        {
          struct std temp = st[j];
          st[j] = st[j+1];
          st[j+1] = temp;
        }
      }
    }
    printf("Bubble-Sorted List: \n");
    for (int i = 0; i < n; i++)
    {
      printf("Name: %s\n", st[i].name);
          printf("PRN: %d\n", st[i].PRN);
          printf("Roll Number: %d\n", st[i].rno);
          printf("\n");
        }
        break;


    
    case 2:
    for(int i=0; i<n-1; i++)
    {
      int min = i;
      for(int j= i+1; j<n; j++)
      {
        if(st[j].rno < st[min].rno)
        {
          min = j;
        }
      
    struct std temp = st[i];
    st[i] = st[min];
    st[min] = temp;
    }
    printf("Selection-Sorted List: \n");
    for (int i = 0; i < n; i++)
    {
      printf("Name: %s\n", st[i].name);
          printf("PRN: %d\n", st[i].PRN);
          printf("Roll Number: %d\n", st[i].rno);
          printf("\n");
        }
        break;
   
    
    case 3:
    for(int i=1; i<n; i++)
    {
      struct std key = st[i];
      int j = i-1;
      while(j>=0 && st[j].rno > key.rno)
      {
        st[j+1] = st[j];
        j--;
      }
      st[j+1] = key;
    }
    printf("Insertion-Sorted List: \n");
    for (int i = 0; i < n; i++)
    {
      printf("Name: %s\n", st[i].name);
          printf("PRN: %d\n", st[i].PRN);
          printf("Roll Number: %d\n", st[i].rno);
          printf("\n");
        }
        break;
        default:
          printf("please enter a valid choice.");
  }
}}
