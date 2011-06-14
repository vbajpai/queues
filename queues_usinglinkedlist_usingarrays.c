// Queue Implementation using Linked List Implemented Using Arrays //

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define NUL -1
#define TRUE 1
#define FALSE 0
typedef struct linklist {
                         int info;
                         int next;
                        }LINK;
struct queue {
                        int front;
                        int rear;
             }q;
LINK l[SIZE]; 
int avail=0;
int emptys(struct queue *q);
void inserts(struct queue *,int e);
int removes(struct queue *);
void freenode(int);
int getnode(void);
main(void)
{
      q.front=q.rear=NUL;    
      int ch,e,x;
      int i;
      // Initialising the pool of available nodes //
      for(i=0;i<SIZE-1;i++)
                     l[i].next=i+1;
      l[SIZE-1].next=NUL;
      while(1)
      {
              system("cls");
              printf("\n\nQueue Implementation using Linked List Implemented Using Arrays\n\n\n");       
              printf("1. Insert Element\n");
              printf("2. Remove Element\n");
              printf("3. Display Elements\n");
              printf("4. Exit\n\n");
              printf("Enter Choice:");
              scanf("%d",&ch);
              switch(ch)
              {
               case 1:
                        printf("\n\nEnter Element:");
                        scanf("%d",&e);
                        inserts(&q,e);                                                         
                        break;
               case 2:
                        x=q.front;
                        if(x==NUL)
                        {
                                     printf("\nUnderflow!");
                                     fflush(stdin);
                                     getchar();
                        }
                        else
                        {
                         printf("\nFront: %d", l[q.front].info);
                         x = removes(&q);
                         printf("\n\n Deleted !", x);
                         fflush(stdin);
                         getchar();
                        }
                        break;
               case 3:
                        x=q.front;
                        if(x!=NUL)
                        {
                              printf("\nQueue: ");
                              while(x!=NUL)
                               {
                                    printf("%d->",l[x].info);
                                    x = l[x].next;
                               }
                        }
                        else
                               printf("\nQueue Empty");
                         fflush(stdin);
                         getchar();
                        break;
               case 4:
                        exit(1);                              
              }            
      }          
}
int emptys(struct queue *q)
{
    if(q->front==NUL)
              return TRUE;
    else
              return FALSE;                  
}

void inserts(struct queue *q,int e)                            
{
          int p;
          p=getnode();
          if(p!=NUL)
          {
           l[p].info=e;
           l[p].next=NUL;
           if(emptys(q))
                       q->front=p;
           else
                       l[q->rear].next=p;
           q->rear=p;          
           
          }     
}

int getnode()
{
           int p;  
           if(avail==NUL)
           {
                         printf("\nOverflow!");    
                         fflush(stdin);
                         getchar();
                         return NUL;
           }
           else
           {
                         p = avail;
                         avail=l[avail].next;                        
                         return p;    
           }
                                       
}

void freenode(int x)
{
  l[x].next=avail;
  avail=x;     
}

int removes(struct queue *q)
{
    int temp;
    int temp2=q->front;
    temp = l[q->front].info;
    q->front = l[q->front].next;    
    freenode(temp2);
    return temp;   
}

