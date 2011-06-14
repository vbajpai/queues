// Queue Implementation Using Array //

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
#define FALSE 0
#define TRUE 1
struct queue {
                 int elements[SIZE];
                 int front;
                 int rear;
             }q;
void inserts(struct queue *, int);
int emptys(struct queue *);
int removes(struct queue *);
main()
{
     int ch,e,temp,old;
     q.front=q.rear=SIZE-1;
     while(1)
     {
     system("cls");
     char ch1='N';
     printf("\n\n\nQueue Implementation\n\n\n");
     printf("1. Insert Elements\n");
     printf("2. Delete Elements\n");
     printf("3. Display Elements\n");
     printf("4. Quit\n\n");
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
                   if(!emptys(&q))
                   {
                                fflush(stdin);  
                                if(q.front==SIZE-1)
                                      printf("\n\nDelete %d (Y/N)?",q.elements[0]);  
                                else
                                      printf("\n\nDelete %d (Y/N)?",q.elements[q.front+1]);
                                scanf("%c",&ch1);
                   }
                   else
                   {
                                printf("\nUnderflow!");
                                fflush(stdin);
                                getchar();
                   }
                   while(ch1=='Y' || ch1=='y')
                   {
                        temp = removes(&q);
                        printf("%d Deleted !", temp);
                        if(!emptys(&q))
                        {
                        printf("\n\nDelete %d (Y/N)?",q.elements[q.front+1]);  
                        fflush(stdin);                                
                        scanf("%c",&ch1);  
                        }
                        else               ch1='N';
                   }
                   break;
        case 3:    
                   if(emptys(&q))
                   {
                                 printf("\nQueue Empty!");
                                 fflush(stdin);
                                 getchar();
                                 break;
                   }
                   else
                       old=q.front;
                       printf("\nQueue Lists: ");
                   while(q.front!=q.rear)
                   {
                                     if(q.front==SIZE-1)
                                                      q.front=0;
                                     else
                                                      q.front++;
                                     printf("%d <-", q.elements[q.front]);                                                       
                   }
                    fflush(stdin);
                    getchar();
                    q.front=old;
                   break;
        case 4:
                   exit(1);                   
        default:
                   printf("Incorrect Choice");       
                   
     }
     }
}

void inserts(struct queue *q, int x)
{
     if(q->rear==SIZE-1)
                     q->rear=0;
     else
                     q->rear++;
     if(q->rear==q->front)
     {
                          printf("\nOverflow!");
                          fflush(stdin);
                          getchar();
                          q->rear--;
     }
     else
                          q->elements[q->rear]=x;     
}

int emptys(struct queue *q)
{
    if(q->front==q->rear)
                         return TRUE;
    else
                         return FALSE;
}

int removes(struct queue *q)
{
    if(q->front==q->rear)
                         printf("Underflow");
    else
                         if(q->front==SIZE-1)
                                             q->front=0;
                         else
                                             q->front++;
    return(q->elements[q->front]);
                             
}
