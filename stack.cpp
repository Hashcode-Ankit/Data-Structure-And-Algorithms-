#include<iostream>
using namespace std;
int arr[5];
class stack{
public:
	int top=-1;
public:
void  isempty()
{
  if(top==-1 )
  {
   cout<<"the stack is empty "<<endl;
  }
  else 
  	cout<<"stack has some elements "<<endl;

}
void push(int a)
{
	if(top<5)
	{
		top++;
		arr[top]=a;
		cout<<"element is successfully pushed"<<endl;
	}
	else
		cout<<"stack is overflow firstly pop some elements and then try to push"<<endl;
}
int pop()
{
	int a;
	if(top==-1)
	{
		cout<<"stack is underflow"<<endl;
	}
	else
	{
		 a=arr[top];
		top--;

	}
	return a;
}
int peek()
{
	int a;
	if(top==-1)
	{
		cout<<"stack is underflow"<<endl;
	}
	else
	{
		a=arr[top];
	}
	return a;
}
void display()
{
	if(top==-1)
	{
		cout<<"stack is empty nothing to print"<<endl;
		return ;
	}
	else{
		for(int i=0;i<=top;i++)
		{
			cout<<arr[i]<<"   " ;
		}
		cout<<"\n";
	}
}

};
int main()
{ int t=1,data;
	stack s;
	while(t)
{
	cout<<"0. To execute from the programme"<<endl;
	cout<<"1. To push the element "<<endl;
	cout<<"2. To pop to element "<<endl;
	cout<<"3. To know the peek element "<<endl;
	cout<<"4. To check whether the stack is empty or not"<<endl;
	cout<<"5. To display all the elements of the stack"<<endl;
    cout<<" Enter the operation you want to perform"<<endl;
    cin>>t;
    switch(t)
    {
    	case 0:
    	    break;
    	case 1:
    	cout<<"enter the data you want to push into the stack "<<endl;
    	cin>>data;
    	s.push(data);
    	break;
    	case 2:
    	data=s.pop();
    	cout<<"The data which is deleted is "<<data<<endl;
    	break;
    	case 3:
    	data=s.peek();
    	cout<<"data at the peek is "<<data<<endl;
    	break;
    	case 4:
    	s.isempty();
    	break;
    	case 5:
    	 cout<<" The element are "<<endl;
    	 s.display();
    	 break;
    	default : 
    	cout<<"enter the correct value"<<endl;


    }
    	
	
}
}