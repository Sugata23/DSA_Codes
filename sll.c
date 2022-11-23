#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
  int data;  
  struct node *next;   
};  
struct node *HEAD;  
 
void insert_at_begin();   
void insert_at_last();  
void insert_random();  
void delete_at_begin();  
void delete_at_last();  
void delete_random();  
void print();  
void searching();  
void main()  
{  
  int your_choice=0;  
  while(your_choice != 9)   
  {
      printf("\n**************************************\n");
      printf("\n\nTechVidvan Tutorial: Performing operations on Singly Linked List!\n\n");
      printf("Choose an option from the below list!\n");  
      printf("\n**************************************\n");  
      printf("1.Do insertion at beginning of the list!\n2.Do insertion at last!\n3.Do insertion at random location!\n4.Do deletion from the beginning of the list!\n5.Do deletion at the last of the list!\n6.Do deletion of a node after a specified node!\n7.Perform a searching operation for an element!\n8.Display!\n9.Exit!\n");  
      printf("\nEnter your choice?\n");       
      scanf("\n%d",&your_choice);  
      switch(your_choice)  
      {  
          case 1:  
          insert_at_begin();    
          break;  
          case 2:  
          insert_at_last();       
          break;  
          case 3:  
          insert_at_last();     
          break;  
          case 4:  
          delete_at_begin();     
          break;  
          case 5:  
          delete_at_last();      
          break;  
          case 6:  
          delete_random();        
          break;  
          case 7:  
          searching();       
          break;  
          case 8:  
          print();      
          break;  
          case 9:  
          exit(0);  
          break;  
          default:  
          printf("Please enter a choice from the following list!");  
      }  
  }  
}  
void insert_at_begin()  
{  
  struct node *point;  
  int value;  
  point = (struct node *) malloc(sizeof(struct node *));  
  if(point == NULL)  
  {  
      printf("\nInvalid!!");  
  }  
  else  
  {  
      printf("\nEnter the value: \n");    
      scanf("%d",&value);    
      point->data = value;  
      point->next = HEAD;  
      HEAD = point;  
      printf("\nNice, The Node is inserted at the beginning!");  
  }  
    
}  
void insert_at_last()  
{  
  struct node *point,*tmp;  
  int value;   
  point = (struct node*)malloc(sizeof(struct node));    
  if(point == NULL)  
  {  
      printf("\nInvalid!!");   
  }  
  else  
  {  
      printf("\nEnter the value: \n");  
      scanf("%d",&value);  
      point->data = value;  
      if(HEAD == NULL)  
      {  
          point -> next = NULL;  
          HEAD = point;  
          printf("\nNice, The Node is inserted!");  
      }  
      else  
      {  
          tmp = HEAD;  
          while (tmp -> next != NULL)  
          {  
              tmp = tmp -> next;  
          }  
          tmp->next = point;  
          point->next = NULL;  
          printf("\nNice, The Node is inserted!");  
        
      }  
  }  
}  
void insert_random()  
{  
  int a,pos,value;   
  struct node *point, *tmp;  
  point = (struct node *) malloc (sizeof(struct node));  
  if(point == NULL)  
  {  
      printf("\nInvalid!!");  
  }  
  else  
  {  
      printf("\nEnter the value of element: ");  
      scanf("%d",&value);  
      point->data = value;  
      printf("\nEnter the position where you want to insert: ");  
      scanf("\n%d",&pos);  
      tmp=HEAD;  
      for(a=0;a<pos;a++)  
      {  
          tmp = tmp->next;  
          if(tmp == NULL)  
          {  
              printf("\nSorry, but you cannot insert!\n");  
              return;  
          }  
        
      }  
      point ->next = tmp ->next;   
      tmp ->next = point;   
      printf("\nNice, The Node is inserted at your given location!");  
  }  
}  
void delete_at_begin()  
{  
  struct node *point;  
  if(HEAD == NULL)  
  {  
      printf("\nThe List is empty!\n");  
  }  
  else   
  {  
      point = HEAD;  
      HEAD = point->next;  
      free(point);  
      printf("\nThe node is deleted from the beginning!\n");  
  }  
}  
void delete_at_last()  
{  
  struct node *point,*point1;  
  if(HEAD == NULL)  
  {  
      printf("\nThe List is empty!");  
  }  
  else if(HEAD -> next == NULL)  
  {  
      HEAD = NULL;  
      free(HEAD);  
      printf("\nOne node is deleted from the list!\n");  
  }  
  else  
  {  
      point = HEAD;   
      while(point->next != NULL)  
      {  
          point1 = point;  
          point = point ->next;  
      }  
      point1->next = NULL;  
      free(point);  
      printf("\nThe Node is deleted from the last of the node!\n");  
  }   
}  
void delete_random()  
{  
  struct node *point,*point1;  
  int pos,a;    
  printf("\nEnter the position of the node after which you want to delete!\n");  
  scanf("%d",&pos);  
  point=HEAD;  
  for(a=0;a<pos;a++)  
  {  
      point1 = point;     
      point = point->next;  
            
      if(point == NULL)  
      {  
          printf("\nSorry, but you cannot delete!");  
          return;  
      }  
  }  
  point1 ->next = point ->next;  
  free(point);  
  printf("\nThe Node is deleted at location: %d",pos+1);  
}  
void searching()  
{  
  struct node *point;  
  int value,a=0,count;  
  point = HEAD;   
  if(point == NULL)  
  {  
      printf("\nSorry, but the list is empty!\n");  
  }  
  else  
  {   
      printf("\nEnter the value which you want to search: \n");   
      scanf("%d",&value);  
      while (point!=NULL)  
      {  
          if(point->data == value)  
          {  
              printf("The value which you searched for, found at: %d ",a+1);  
              count=0;  
          }   
          else  
          {  
              count=1;  
          }  
          a++;  
          point = point -> next;  
      }  
  if(count==1)  
  {  
      printf("Sorry, the value is not found!\n");  
  }  
  }   
        
}  
 
void print()  
{  
  struct node *point;  
  point = HEAD;   
  if(point == NULL)  
  {  
      printf("Please enter something to print!");  
  }  
  else  
  {  
      printf("\nPrinting the values!\n");   
      while (point!=NULL)  
      {  
          printf("\n%d",point->data);  
          point = point -> next;  
      }  
  }  
}