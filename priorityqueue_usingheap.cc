#include<iostream>
#include<cmath>			// for floor function
#define SIZE 5
using namespace std;

class Heap
{
	public:
	
	    static void Heapify(int *a,int i,int num)
		{
			int l = Left(i);
			int r = Right(i);
			int largest;
			
			if(l<num && a[l] > a[i])
				largest = l;
			else
				largest = i;
			
			if(r<num && a[r] > a[largest])
				largest = r;
				
			if (largest != i)
			{
				Swap(&a[i],&a[largest]);
				Heapify(a,largest,num);		
			}							
		}
		
		static int Left(int i)
		{
			return(2*i+1);
		}
		
		static int Right(int i)
		{
			return(2*i+2);
		}
		
		static void Swap(int *a, int *b)
		{
				if(*a!=*b)
				{
					*a ^= *b;
					*b ^= *a;
					*a ^= *b;	
				}
		}
};

class PQueue
{
	private:
	
	static int a[];
	static int num;	
	
	public:
	
	static void Insert(int key)
	{
		if(num == SIZE)
			cout<<"\n\nOverflow!";
		else
		{
			num++;
			Update(num-1,key);
		}
		
	}
	
	static void Update(int i, int key)
	{
		a[i] = key;
		while(i>0 && a[Parent(i)] < a[i])
		{
			Swap(&a[i],&a[Parent(i)]);
			i = Parent(i);
		}
		
	}
	
	static int ShowMax(bool *flag)
	{
		if(num>0)
				return(a[0]);
		else
				cout<<"\n\nUnderflow!";
				*flag = false; 		
				return(0);		
	}
	
	static int ExtractMax(bool* flag)
	{
		if(num==0)
		{
			cout<<"\n\nUnderflow!";
			*flag = false;
			return(0);
		}
			
		else
		{
			int max = a[0];
			a[0] = a[num-1];
			num--;
			Heap::Heapify(a, 0, num);	
			return(max);
		}
	}
	
	static void Swap(int *a, int *b)
	{
			if(*a!=*b)
			{
				*a ^= *b;
				*b ^= *a;
				*a ^= *b;	
			}
	}
	
	static int Parent(int i)
	{
		return((int)(floor(i/2)));	
	}
	
	static int Search(int key, bool* flag)
	{
		for(int i=0;i<num;i++)
		{
			if(a[i] == key)
				return(i);
		}		
		
		*flag = false;		
		return(0);	
	}
	
	static int Valueat(int i)
	{
		return(a[i]);	
	}
};

int PQueue::num = 0;
int PQueue::a[SIZE];

int main()
{
     do
     {
		 system("clear");
		 int key,ch,i,max;
		 bool flag;
		 		
		 cout<<"\n\n\nPriority Queue Implementation\n\n\n";
		 cout<<"1. Insert Elements\n";
		 cout<<"2. Update Key\n";
		 cout<<"3. Show Maximum Element\n";
		 cout<<"4. Extract Maximum Element\n";
		 cout<<"5. Quit\n\n";
		 cout<<"Enter Choice:";      
		 scanf("%d",&ch);
		 
		 switch(ch)
		 {
			  case 1: 
			  		  cout<<"\n\nValue:";
			  		  cin>>key;
					  PQueue::Insert(key);  
					            
					  break;
			  case 2:
			  		  cout<<"Key to Update:";
			  		  cin>>key;
			  		  flag = true;
			  		  i = PQueue::Search(key,&flag);	
			  		  if(flag)
			  		  {
			  		  	  cout<<"Enter New Key Value:";
						  cin>>key;
						  
						  if(key<PQueue::Valueat(i))
								cout<<"\n\nNew Key is Smaller!";
						  else
						  		PQueue::Update(i,key);			  		  	
			  		  }	  		  	
			  		  else
			  		  	cout<<"Key not Found!";	 			  		  		
					  break;
			  case 3: 
			  		  flag = true;
			  		  max = PQueue::ShowMax(&flag);
			  		  if(flag)
			  		  	cout<<"\n\nMaximum Value:"<<max;
					  break;
			  case 4: 		
			  		  flag = true;		  
			  		  max = PQueue::ExtractMax(&flag);	
			  		  if(flag)
			  		  	cout<<"\n\nMaximum Value:"<<max;
					  break;
					  
			  case 5: 
			  		  exit(0);
			  		  
			  default:  
			  		  cout<<("\nIncorrect Choice");             
						
		 }
		 
     }while(1);
}

