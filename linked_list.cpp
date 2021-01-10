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
	void insert_begining(node* n)
	{
		if(start==NULL)
		{
         start=n;
         cout<<"successfully appended"<<endl;
         return ;
		}
			node* ptr=start;
			start=n;
			n->link=ptr;
			cout<<"Node successfully appended"<<endl;
	}
	void insert_end(node* n){
		if(start==NULL)
		{
			start=n;
			cout<<"list was empty node is appended"<<endl;
		}
		else
		{
			node* ptr=start;
			while(ptr->link!=NULL)
			{
				ptr=ptr->link;
			}
			ptr->link=n;
			cout<<"Node is successfully at the end"<<endl;
		}
	}
	int linked_list_length()
	{
		int count=0;
		node* ptr=start;
		while(ptr!=NULL)
		{
			ptr=ptr->link;
			count++;
		}
		return count;
	}
	void delete_first()
	{
         if(start==NULL)
         {
         	cout<<"nothing to delete "<<endl;
         	return ;
         }
         cout<<"data of deleted node "<<start->data<<endl;
         start=start->link;
	}
	void delete_end()
	{
	if(start==NULL)
	{
		cout<<"linked list is empty"<<endl;
		return;
	}	
	node* temp=start->link->link;
	node* ptr=start->link;
	node* preTemp=start;
	while(temp!=NULL)
	{
		temp=temp->link;
		ptr=ptr->link;
		preTemp=preTemp->link;
	}
	cout<<"The data of deleted node is "<<ptr->data<<endl;
	preTemp->link=NULL;
	ptr->data=0;
	}
	void display()
	{
		if(start==NULL)
		{
			cout<<"no data to print at start node is null"<<endl;
			return;
		}
		node* temp;
		temp=start;
		while(temp!=NULL)
		{
           cout<<endl<<"node data:  "<<temp->data<<endl;
           temp=temp->link;
		}
	}

};
int main()
{
	cout<<"implementation of the linked list is there by the programmer ankit sharma "<<endl;
    int times=1,data;
    linked_list list;
    while(times)
    {
    	cout<<"0. To execute from the programme"<<endl;
    	cout<<"1.To insert node in the begining"<<endl;
    	cout<<"2. to insert the node at end"<<endl;
    	cout<<"3. To check the node length "<<endl;
    	cout<<"4. To print the data of the nodes"<<endl;
    	cout<<"5. To delete first node"<<endl;
    	cout<<"6. To delete the node from the end"<<endl;
    	cout<<"enter the operation you want to perform "<<endl;
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
    		list.insert_begining(n);
    		break;
    		case 2:
    		cout<<"enter the data of node to insert it at end"<<endl;
    		cin>>data;
    		n->data=data;
    		list.insert_end(n);
    		break;
    		case 3:
    		data=list.linked_list_length();
    		cout<<"the length of the linked list is "<<data<<endl;
    		break;
    		case 4:
    		cout<<"the data of the nodes given below in sequence"<<endl;
    		list.display();
    		break;
    		case 5:
    		list.delete_first();
    		break;
    		case 6:
    		list.delete_end();
    		break;
    		default :
    		cout<<"enter the correct value you may have entered a wrong value"<<endl;
    	}

    }
return 0;
    
}