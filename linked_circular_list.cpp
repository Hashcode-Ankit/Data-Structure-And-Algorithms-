#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* link=NULL;
};
class linked_list{
   node* start=NULL;  
public:
	void insert(node* n)
	{
		if(start==NULL)
		{
			start=n;
			n->link=start;
			cout<<"node is added"<<endl;
			return;
		}
		node* temp=start;
		while(temp->link!=start)
		{
			temp=temp->link;
		}
		temp->link=n;
		n->link=start;
		cout<<"data is successfully added"<<endl;
	}
	void deleted(){
		if(start==NULL)
		{
			cout<<"linked list is empty so nothing to be deleted"<<endl;
			return;
		}
		node* temp=start->link;
		node* pretemp=start;
		while(temp->link!=start)
		{
			temp=temp->link;
			pretemp=pretemp->link;
		}
		pretemp->link=start;
		cout<<"NOde deleted with the data :   "<<temp->data<<endl;
		temp->link=NULL;
	}
	void display(){
		if(start==NULL)
		{
			cout<<"there is no data to print"<<endl;
			return;
		}
		node* temp=start;
		while(temp->link!=start)
		{
			cout<<"Node data  :   "<<temp->data<<endl;
			temp=temp->link;
		}
		cout<<"Node data:    "<<temp->data<<endl;


	}
};
int main()
{
    int times=1,data;
    linked_list list;
    while(times)
    {
    	cout<<"0. To execute from the programme"<<endl;
    	cout<<"1.To insert node in the begining"<<endl;
    	cout<<"2. to delete the node"<<endl;
    	cout<<"3. To display the nodes "<<endl; 
    	cin>>times;
    	node* n=new node();
    	
    	switch(times)
    	{
    		case 0:
    		cout<<"executing from the programme"<<endl;
    		break;
    		case 1:
    		cout<<"enter the data of node to insert at begining"<<endl;
    		cin>>data;
    		n->data=data;
    		list.insert(n);
    		break;
    		case 2:
    		list.deleted();
    		break;
    		case 3:
    		cout<<"the data of the nodes given below in sequence"<<endl;
    		list.display();
    		break;
    		default :
    		cout<<"enter the correct value you may have entered a wrong value"<<endl;
    	}

    }
return 0;
    
}