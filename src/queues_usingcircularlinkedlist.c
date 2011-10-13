// Queue Implementation using Circular Linked List //
// list points to last node, which is REAR //
// following node i.e. list->next is FRONT //

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct link {
                              int info;
                              struct link *next;
                    }LINK; 
LINK *list;
int count=0;
void inserts(int x);
int emptys(void);
LINK * getnode(void);
void freenode(LINK *);
int removes();
main(void)
{
   int ch,e,temp=0,end=FALSE;
   LINK *x;
   LINK *y;
   list=NULL;
   while(1)
   {
          system("cls"); 
          printf("\n\n\nQueue Implementation using Circular Linked List\n\n");
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
                     {
                                printf("\nUnderflow!");
                                fflush(stdin);
                                getchar();  
                     }
                     else
                     {
                         printf("\nFront: %d",(list->next)->info);
                         printf("\n\nDelete(Y/N)?");
                         fflush(stdin);
                         scanf("%c",&ch);
                         if(ch=='Y' || ch=='y')
                         {
                                    temp = removes();
                                    printf("\n%d Deleted Successfully!",temp);
                                    fflush(stdin);
                                    getchar();
                         }           
                     }        
                     
                     break;
              case 3:
                     x = list;
                     if(x!=NULL)
                                       printf("\nQueue(Front->Rear):");
                     while(end==FALSE && x!=NULL)
                     {
                            x = x->next;          
                            printf("%d->",x->info);                              
                            if(x==list)
                                       end = TRUE;
                     }
                     end = FALSE;
                     if(list==NULL)
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
    if(list==NULL)
                 return TRUE;
    else
                 return FALSE;    
}

void inserts(int x)
{
     
     LINK *p;
     p = getnode();
     p->info = x;
     if(emptys())
     {
            p->next = p;
            list= p; 
     }
     else
     {     
           p->next = list->next;
           list->next = p;
     }   
           list = p;
}

LINK * getnode(void)
{
     LINK *p;
     count++;
     p = (LINK*)malloc(sizeof(LINK));
     return p;     
}

void freenode(LINK *x)
{
     free(x);   
     count--; 
}

int removes()
{
    int temp;
    LINK *x;
    x = list->next;    // first node
    temp = x->info;   
    list->next = x->next;           
    if(list==x)                     // Single Node Deleted 
               list = NULL;
    freenode(x);
    return temp;
}







