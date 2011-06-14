// Queue Implementation Using Linked List //

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct link {
                              int info;
                              struct link *next;
                    }LINK; 
typedef struct queue {
                             LINK *front;
                             LINK *rear;
                     }QUEUE;
QUEUE q;

void inserts(int x);
int emptys(void);
LINK * getnode(void);
void freenode(LINK *);
int removes();
main(void)
{
   int ch,e,temp;
   LINK *x;
   q.rear=q.front=NULL;
   while(1)
   {
          system("cls"); 
          printf("\n\n\nQueue Implementation Using Linked List\n\n");
          printf("1. Insert Elements\n");
          printf("2. Delete Elements\n");
          printf("3. Display Elements\n");
          printf("4. Exit\n\n");
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
                       temp = removes();
                       printf("\n%d Deleted!",temp);                       
                     }         
                     fflush(stdin);
                     getchar();                        
                     break;
              case 3:
                     x = q.front;
                     if(q.front!=NULL)
                                       printf("\nQueue:");
                     while(x!=NULL)
                     {
                            printf("%d->",x->info);  
                            x = x->next;
                     }
                     if(q.front==NULL)
                            printf("\nQueue Empty!");    
                            fflush(stdin);
                            getchar();                                           
                     
                     break;
              case 4:
                     exit(0);        // returning 0 means successful 
          }
          
   }                 
}

int emptys(void)
{
    if(q.front==NULL)
                 return TRUE;
    else
                 return FALSE;    
}

void inserts(int x)
{
     LINK *p;
     p = getnode();
     p->info = x;
     p->next = NULL;
     
     if(q.front==NULL)
                       q.front = p;
     else
                       q.rear->next=p;
     q.rear = p;   
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

int removes()
{
    int temp;
    LINK *x;
    temp = q.front->info;
    x = q.front->next;      
    freenode(q.front);
    q.front = x;
    return temp;
}







