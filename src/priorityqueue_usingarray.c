// Priority Queue Implementation Using Arrays //

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
#define FALSE 0
#define TRUE 1
struct pqueue {
                 int elements[SIZE];
                 int front;
                 int rear;
             }pq;
void pqinsert(struct pqueue *pq,int x);
int pqmaxdelete(struct pqueue *);
int pqmindelete(struct pqueue *);
int bsearchs(struct pqueue *pq, int x);
main()
{
     int ch,e,temp,old;
     pq.front=pq.rear=SIZE-1;
     while(1)
     {
     system("cls");
     char ch1='N';
     printf("\n\n\nPriority Queue Implementation\n\n\n");
     printf("1. Insert Elements\n");
     printf("2. Delete Smallest Element\n");
     printf("3. Delete Largest Element\n");
     printf("4. Display Elements\n");
     printf("5. Quit\n\n");
     printf("Enter Choice:");      
     scanf("%d",&ch);
     switch(ch)
     {
          case 1: 
                  printf("\nEnter Element:");
                  scanf("%d",&temp);
                  pqinsert(&pq,temp);                  
                  break;
          case 2:
                  fflush(stdin);
                  if(emptys(&pq))
                  {
                                 printf("\nUnderflow");
                                 getchar();
                                 break;                  
                  }
                  if(pq.front==SIZE-1)
                                printf("\nDelete %d (Y/N)?", pq.elements[0]);                                
                  else
                                printf("\nDelete %d (Y/N)?", pq.elements[pq.front+1]);
                  scanf("%c", &ch);
                  if(ch=='Y' || ch=='y')
                  {
                                  temp=pqmindelete(&pq);
                                  printf("\n%d Deleted !",temp);
                                  fflush(stdin);
                                  getchar();
                  }
                  break;
          case 3: 
                  fflush(stdin);
                  if(emptys(&pq))
                  {
                                 printf("\nUnderflow");
                                 getchar();
                                 break;                  
                  }
                  printf("\nDelete %d (Y/N)?", pq.elements[pq.rear]);
                  scanf("%c", &ch);
                  if(ch=='Y' || ch=='y')
                  {
                                  temp=pqmaxdelete(&pq);
                                  printf("\n%d Deleted !",temp);
                                  fflush(stdin);
                                  getchar();
                  }
                  break;
          case 4: 
                  fflush(stdin);
                  if(pq.front==pq.rear)
                  {
                                       printf("\nPriority Queue Empty");
                                       getchar();
                                       break;
                  }
                  old=pq.front; 
                  printf("\nPriority Queue List: ");
                  while(pq.front!=pq.rear)
                  {
                        if(pq.front==SIZE-1)
                                            pq.front=0;
                        else
                                            pq.front++;
                        printf("%d->",pq.elements[pq.front]);                        
                  }
                        getchar();
                  pq.front=old;
                  
                  break;
          case 5: exit(1);
          default:  printf("\nIncorrect Choice");                  
                    fflush(stdin);
                    getchar();
     }
     }
}

int pqmindelete(struct pqueue *pq)
{
    int temp;
    if(pq->front==SIZE-1)
    {
                         temp=pq->elements[0];
                         pq->front=0;
    }
    else
                         temp=pq->elements[++pq->front];
    return temp;
}

int pqmaxdelete(struct pqueue *pq)
{
    int temp;
    if(pq->rear==0)
    {
                         temp=pq->elements[0];
                         pq->rear=SIZE-1;
    }
    else
                         temp=pq->elements[pq->rear--];
    return temp;
}

int emptys(struct pqueue *pq)
{
    if(pq->front==pq->rear)
                           return TRUE;
    else
                           return FALSE;    
}

void pqinsert(struct pqueue *pq,int x)
{
     int pos,temp,flag,full=FALSE;
     if(emptys(pq))
     {
                   if(pq->rear==SIZE-1)
                                       pq->rear=0;
                   else
                                       pq->rear++;
                   pq->elements[pq->rear]=x;
     }
     else
     {
                   pos=bsearchs(pq,x);
                   if(pq->rear==SIZE-1)
                   {
                                       temp = pq->rear=0;
                                       flag=TRUE;
                   }
                   else
                   {
                                       temp=++pq->rear;
                                       flag=FALSE;
                   }
                   if(pq->front==pq->rear)
                   {
                                          printf("\nOverflow");
                                          fflush(stdin);
                                          getch();
                                          if(flag)
                                                  pq->rear=SIZE-1;
                                          else
                                                  pq->rear--;
                                          full=TRUE;
                   }
                   while((pq->rear!=pos) && !full)
                   {   
                       
                       if(flag)
                       {
                               pq->elements[pq->rear]=pq->elements[SIZE-1];
                               pq->rear=SIZE-1;
                               flag=FALSE;
                       }
                       else
                       {
                               pq->elements[pq->rear]=pq->elements[pq->rear-1];
                               pq->rear--;
                       }
                   }
                   if(!full)
                   {
                   pq->rear=temp;
                   pq->elements[pos]=x;            
                   }
     }
     
}

int bsearchs(struct pqueue *p, int x)
{
 int temp,old,temp1 ;
 old=p->front;    
 while(p->front!=p->rear)   
 {
  
  if(p->front==SIZE-1)
                      p->front=0;
  else
                      p->front++;                      
  temp = p->elements[p->front];
  if(temp>=x)
  {
             temp1=p->front;
             p->front=old;
             return(temp1);                                          
  }
 }
 p->front=old;
 if(p->rear==SIZE-1)
                     return(0);
 else
                     return(p->rear+1);
 
}


