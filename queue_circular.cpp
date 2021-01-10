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
		if(front==-1 || rear==-1)
		return true;
	    else
	    return false;
	}
	void enqueue(int data)
	{
		if(front==(rear+1)%(size))
		{
			cout<<"overflow condition"<<endl;
		}
		else if(rear==-1)
		{
			front=rear=0;
			arr[rear]=data;
			cout<<"data is enqueue at first position"<<endl;
		}
		else if(rear==size-1)
		{
			rear=0;
			arr[rear]=data;
			cout<<"the data is again at 0"<<endl;
		}
		else
		{
			rear++;
			arr[rear]=data;
			cout<<"data is enqued successfully "<<endl;
		}
	}
	int dequeue()
	{
		int data;
		if(front==-1)
		{
			cout<<"queue has no element to delete"<<endl;
			return 0;
		}
		else if(front==rear)
		{
			data=arr[front];
			front =-1;
			rear=-1;
			cout<<"data is dequeued rear===front case"<<endl;
		}
		else if(front==size-1 )
		{
			
			data=arr[front];
			front=0;
			cout<<"data is dequeued "<<endl;
		}
		else
		{
			data=arr[front];
			front++;
			cout<<"data is dequeued"<<endl;
		}
		return data;
	}
	void display()
	{ 
		if(front==-1||rear==-1)
		{
			cout<<"queue is empty"<<endl;
		     return ;
		}

		for(int i=front;i<=size-1;i++)
		{
			cout<<arr[i]<<" " ;
		}
		if(front!=0)
		{
			for(int i=0;i<=rear;i++)
			{
				cout<<arr[i]<<" ";
			}
		}
		
		cout<<endl;
	}

};
int main()
{
	int t;
	int data;
	queue q;
	while(t)
	{
		cout<<"0. To execute from the programme"<<endl;
		cout<<"1. To enqueue the element "<<endl;
		cout<<"2. To dequeue the element "<<endl;
		cout<<"3. To check whether the queue is empty or not "<<endl;
		cout<<"4. To print all the elements of the queue "<<endl;
		cout<<"enter the value you want to implement"<<endl;
		cin>>t;
		switch(t)
		{
			case 0:
			break;
			case 1:
			cout<<"enter the data you want to enqueue"<<endl;
			cin>>data;
			q.enqueue(data);
			break;
			case 2:
			cout<<"dequeue operation is chosen"<<endl;
			data=q.dequeue();
			if(data>0)
			cout<<"the data is "<<data<<endl;
			break;
			case 3:
			if(q.isempty())
				{
					cout<<"q is empty "<<endl;
				}
				else
				{
					cout<<"queue has some values"<<endl;
				}
			break;
			case 4:
			q.display();
			break; 
			default :
			cout<<"chosse right value"<<endl;

		}

	}
return 0;
}