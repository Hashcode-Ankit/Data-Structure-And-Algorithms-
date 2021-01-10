#include<iostream>
using namespace std;
class node{
public:
	int data;       

	node* left;		

	node* right;			
};				
	class bst{			
public:				
node* root=NULL;				
public:				
bool isempty()				
{					
	if(root==NULL)T				
	{					
		cout<<"bst tree not exist"<<endl;
		return true;
	}
	else 
		return false;
}
void insert(node* root,node* n){
	if(root==NULL)
	{
	 root=n;
	 cout<<"node is attached"<<endl;
	 return;
	}
	else{
	if(n->data<root->data)
		insert(root->left,n);
	else if(n->data>root->data)
		insert(root->right,n);
	}
}
int delete_node(node* root,int d)
{
	if(root->data==d)
	{
		node* temp=root->left;
      root=root->right;
      if(root->left==NULL)
      	root->left=temp;
      else
	}
}
};
int main()
{
	
}