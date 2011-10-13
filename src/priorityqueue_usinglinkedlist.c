// Priority Queue Implementation Using Linked List //

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct link {
                              int info;
                              struct link *next;
                    }LINK; 
typedef struct pqueue {
                             LINK *front;
                             LINK *rear;
                     }PQUEUE;
PQUEUE pq;

void inserts(int x);
int emptys(void);
LINK * getnode(void);
void freenode(LINK *);
int removesL();
int removesS();
main(void)
{
   int ch,e,temp;
   LINK *x;
   pq.rear=pq.front=NULL;
   while(1)
   {
          system("cls"); 
          printf("\n\n\nPriority Queue Implementation Using Linked List\n\n");
          printf("1. Insert Elements\n");
          printf("2. Remove Largest Element\n");
          printf("3. Remove Smallest Element\n");
          printf("4. Display Elements\n");
          printf("5. Exit\n\n");
          printf("Enter Choice:");
          scanf("%d",&ch);
          switch(ch)
          {
              case 1:
                     printf("\nEnter Element:");
                     scanf("%d",&e);
                     inserts(e);                           
                     break;
              case 2:
                     if(emptys())
                           printf("\nUnderflow!");             
                     else
                     {
                       temp = removesL();
                       printf("\n%d Deleted!",temp);                       
                     }         
                     fflush(stdin);
                     getchar();                        
                     break;
              case 3:
                     if(emptys())
                           printf("\nUnderflow!");             
                     else
                     {
                       temp = removesS();
                       printf("\n%d Deleted!",temp);                       
                     }         
                     fflush(stdin);
                     getchar();                        
                     break;
              case 4:
                     x = pq.front;
                     if(pq.front!=NULL)
                                       printf("\nPriority Queue:");
                     while(x!=NULL)
                     {
                            printf("%d->",x->info);  
                            x = x->next;
                     }
                     if(pq.front==NULL)
                            printf("\nPriority Queue Empty!");    
                     fflush(stdin);
                     getchar();                                           
                     
                     break;
              case 5:
                     exit(0);        // returning 0 means successful 
          }
          
   }                 
}

int emptys(void)
{
    if(pq.front==NULL)
                 return TRUE;
    else
                 return FALSE;    
}

void inserts(int x)
{
     LINK *p,*y,*z=NULL;
     p = getnode();
     p->info = x;
       
     if(pq.front==NULL)                       //first element
     {
                       pq.front = p;
                       p->next = NULL;
                       pq.rear = p; 
     }
     else                                           
     {
                       y = pq.front;
                       while(y!=NULL)
                       {
                                     if(y->info>x)
                                           break;       
                                     z = y;             
                                     y = y->next;              
                       }  
                       if(y==NULL)                                  //last entry
                       {
                                  z->next = p;
                                  p->next = NULL;
                                  pq.rear = p;           
                       }
                       else
                       {
                                  if(z!=NULL)
                                  {
                                             p->next = z->next;                       
                                             z->next = p;                                  
                                  }
                                  else                         //Insert at begining
                                  {
                                             p->next = pq.front;
                                             pq.front = p;
                                                                          
                                  }
                                             
                       }                                                                            
     }
                       
       
}

LINK * getnode(void)
{
     LINK *p;
     p = (LINK*)malloc(sizeof(LINK));
     return p;     
}

void freenode(LINK *x)
{
     free(x);    
}

int removesS()
{
    int temp;
    LINK *x;
    temp = pq.front->info;
    x = pq.front->next;      
    freenode(pq.front);
    pq.front = x;
    return temp;
}

int removesL()
{
    int temp;
    LINK *x,*y=NULL;
    x = pq.front;
    while(x!=NULL)
    {
                  if(x==pq.rear)
                               break;
                  y = x;
                  x = x->next;              
    }
    temp = pq.rear->info;
    freenode(pq.rear);
    pq.rear = y;
    if(y!=NULL)
        y->next = NULL;
    else
        pq.front = NULL;
    return temp;
}






