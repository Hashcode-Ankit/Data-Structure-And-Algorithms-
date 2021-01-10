#include<iostream>
using namespace std;
#define size 5
int arr[size];
class queue{
public:
	int front=-1;
	int rear=-1;
public:
	bool isempty()
	{
		if(front==-1)
		{
		 return true;
		}
		
		else
			return false;
	}
	void enqueue(int data)
	{
		if(front==-1)
		{
		  front=0;
		  rear=0;
		  arr[rear]=data;
		  cout<<"data at index 0"<<endl;
		}
		else if(rear==5-1)
		{
			cout<<"queue is full no element can be entered"<<endl;
		}
		else 
		{
			rear++;
			arr[rear]=data;
			cout<<"enqueue successfull"<<endl;
		}
	}
	int dequeue()
	{
		int data;
		if(front==-1 )
		{
			cout<<"queue is empty nothing can be deleted"<<endl;
		}
		else if(front == rear)
		{
         data=arr[front];
         front=-1;
         rear=-1;
		}
		else
		{
			data=arr[front];
			front++;
		}
		return data;
	}
    void display()
    {
    	if(front==-1)
    	{
    		cout<<"queue is empty nothing can be displayed "<<endl;

    	}
    	else
    	{
    		for(int i=front;i<=rear;i++)
    			cout<<arr[i]<<" ";
    	}
    	cout<<endl;
    }
};
int main()
{
int t,data;
queue q;
while(t)
{
	cout<<"0. To execute from the programme"<<endl;
	cout<<"1. To enqueue the element "<<endl;
	cout<<"2. To dequeue to element "<<endl;
	cout<<"3. To check whether the queue is empty or not"<<endl;
	cout<<"4. To display all the elements of the queue "<<endl;
    cout<<" Enter the operation you want to perform"<<endl;
    cin>>t;
    switch(t)
    {
    	case 1:
    	cout<<"enter the data you want to enqueue"<<endl;
    	cin>>data;
    	q.enqueue(data);
    	break;
    	case 2:
    	data=q.dequeue();
    	cout<<"The data which is deleted is "<<data<<endl;
    	break;
    	case 3:
    	if(q.isempty())
    		cout<<"queue is empty"<<endl;
    	else 
    		cout<<"queue has some elements"<<endl;
    	break;
    	case 4:
    	 cout<<" The element are "<<endl;
    	 q.display();
    	 break;
    	default : 
    	cout<<"enter the correct value"<<endl;


    }
}
return 0;
}