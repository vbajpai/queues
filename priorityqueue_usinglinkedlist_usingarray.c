// Ascending Priority Queue Implementation using Linked List Implemented Using Arrays //

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
struct pqueue {
                        int front;
                        int rear;
             }pq;
LINK l[SIZE]; 
int avail=0;
int emptys(struct pqueue *);
void inserts(struct pqueue *,int e);
int removesS(struct pqueue *);
int removesL(struct pqueue *);
void freenode(int);
int getnode(void);
main(void)
{
      pq.front=pq.rear=NUL;    
      int ch,e,x;
      int i;
      // Initialising the pool of available nodes //
      for(i=0;i<SIZE-1;i++)
                     l[i].next=i+1;
      l[SIZE-1].next=NUL;
      while(1)
      {
              system("cls");
              printf("\n\nPriority Queue Implementation using Linked List Implemented Using Arrays\n\n\n");       
              printf("1. Insert Element\n");
              printf("2. Remove Smallest Element\n");
              printf("3. Remove Largest Element\n");
              printf("4. Display Elements\n");
              printf("5. Exit\n\n");
              printf("Enter Choice:");
              scanf("%d",&ch);
              switch(ch)
              {
               case 1:
                        printf("\n\nEnter Element:");
                        scanf("%d",&e);
                        inserts(&pq,e);                                                         
                        break;
               case 2:
                        x=pq.front;
                        if(x==NUL)
                        {
                                     printf("\nUnderflow!");
                                     fflush(stdin);
                                     getchar();
                        }
                        else
                        {
                         printf("\nFront: %d", l[pq.front].info);
                         x = removesS(&pq);
                         printf("\n\n Deleted !", x);
                         fflush(stdin);
                         getchar();
                        }
                        break;
                 case 3:
                        x=pq.front;
                        if(x==NUL)
                        {
                                     printf("\nUnderflow!");
                                     fflush(stdin);
                                     getchar();
                        }
                        else
                        {
                         printf("\nRear: %d", l[pq.rear].info);
                         x = removesL(&pq);
                         printf("\n\n Deleted !", x);
                         fflush(stdin);
                         getchar();
                        }
                        break;
               case 4:
                        x=pq.front;
                        if(x!=NUL)
                        {
                              printf("\nPriority Queue: ");
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
               case 5:
                        exit(1);                              
              }            
      }          
}
int emptys(struct pqueue *q)
{
    if(q->front==NUL)
              return TRUE;
    else
              return FALSE;                  
}

void inserts(struct pqueue *q,int e)                            
{
          int p,y=NUL,x;
          p=getnode();
          if(p!=NUL)
          {
           x = q->front;
           while(x!=NUL)
           {
                        if(e<l[x].info) 
                        {
                            break;
                        }                                                   
                        y=x;                 
                        x=l[x].next;             
           }          
           if(q->front==NUL)                     //first element
           {
                       l[p].info=e;
                       l[p].next=NUL;
                       q->front=p;
                       q->rear=p;
           }
           else
           {
               if(x==NUL)                        //last entry
               {
                       l[p].info=e;
                       l[p].next=NUL;
                       q->rear=p;      
                       l[y].next=p;
               }
               else                             //between
               {
                       if(y!=NUL)
                       {
                                  l[p].info=e;
                                  l[p].next=l[y].next;
                                  l[y].next =p;
                       }
                       else                           //Insert at beginning
                       {
                                  l[p].info=e;
                                  l[p].next=q->front;
                                  q->front=p;
                       }
               }          
           }
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

int removesS(struct pqueue *q)
{
    int temp;
    int temp2=q->front;
    temp = l[q->front].info;
    q->front = l[q->front].next;    
    freenode(temp2);
    return temp;   
}

int removesL(struct pqueue *q)
{
   int x=q->front;
   int temp2=q->rear;
   int temp;
   while(x!=NUL)
   {
             if(l[x].next==q->rear)
             {
                                   temp = l[q->rear].info;
                                   q->rear = x;
                                   l[x].next=NUL;
                                   freenode(temp2);                                   
             }
                                   
             else
                 x=l[x].next;          
   }
   return temp;
   
}
