#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
	int data;
	struct node* left;
	struct node* right;
public:
	node(int x)
	{
		data=x;
		left =NULL;
		right= NULL;
	}
};
void inorder(node* n)
{
	if(n==NULL)
	{
		return ;
	}
	inorder(n->left);
	cout<<n->data<<" ";
	inorder(n->right);
}
void preorder(node* n)
{
	if(n==NULL)
	{
		return;
	}
	cout<<n->data<<" ";
	preorder(n->left);
	preorder(n->right);
}
void postorder(node* n)
{
	if(n==NULL)
	{
		return ;
	}
	postorder(n->left);
	postorder(n->right);
	cout<<n->data<<" ";
}
void levelorder(node* n)
{
  queue<node*> q;
  q.push(n);
  while(!q.empty())
  {
  	node* p=q.front();
  	q.pop();
  	cout<<p->data<<" ";
  	if(p->left!=NULL)
  	{
  	q.push(p->left);
  }
  	if(p->right!=NULL)
  	{
  		q.push(p->right);

  	}
  }
}
int height(node* n)
{
	if(n==NULL)
	{
		return 0;
	}
	return max(height(n->left),height(n->right))+1;
}
int main()
{
 node* n=new node(10);
 node* p=new node(25);
 node* q=new node(30);
  node* r=new node(40);
 node* s=new node(50);
 node* t=new node(60);
  node* u=new node(70);
 node* v=new node(80);
 node* w=new node(90);
 n->left=p;
 n->right=q;
 p->left=r;
 p->right=s;
 r->left=u;
 r->right=v;
 s->left=w;
 cout<<"inorder is :";
 inorder(n);
 cout<<endl<<"preorder is :";
 preorder(n);
 cout<<endl<<"postorder is :";
 postorder(n);
 cout<<endl<<"level order :";
 levelorder(n);
 cout<<"\nheight of the binary tree is :"<<height(n);

}

