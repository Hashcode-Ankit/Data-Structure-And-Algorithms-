#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
class heap{
public:
	int capacity;
	int size;
	int *arr;
public:
	heap(int c)
	{
		arr=new int[c];
		capacity=c;
		size=0;
	}
	int left(int i){
		return (2*i+1);
	}
	int right(int i)
	{
		return (2*i+2);
	}
	int parent(int i)
	{
		return (i-1)/2;
	}
void insert(int data)
{
	if(size==capacity)
	{
		return;
	}
	size++;
	arr[size-1]=data;
	for(int i=size-1;(i!=0 && arr[i]<arr[parent(i)]);i=parent(i))
	{
		swap(&arr[i],&arr[parent(i)]);	
	}
}	
void min_heapify(int i)
{
	int s=i;
	int left_node=left(i);
	int right_node=right(i);
  if(left_node<size && arr[i]>arr[left_node])
  {
      s=left_node;
  }	
  if(right_node<size && arr[s]>arr[right_node])
  {
  	s=right_node;
  }
  if(s!=i)
  {
  	swap(&arr[s],&arr[i]);
    min_heapify(s);
  }
}
int extract_min()
{
	if(size==0)
	{
		return INT_MAX ;
	}
	if(size==1)
	{
		size--;
		return arr[size];

	}

	int result=arr[0];
	arr[0]=arr[size-1];
	size--;
	min_heapify(0);
	return result;
}
void decrease(int x,int i)
{
	arr[i]=x;
	for(i;i!=0 && arr[i]<arr[parent(i)];i=parent(i))
	{
		swap(&arr[i],&arr[parent(i)]);
	}
}
void del(int i)
{
	decrease(INT_MIN,i);
	extract_min();
}
void build_heap()
{
	for(int i=(size-2)/2;i!=0;i--)
	{
		min_heapify(i);
	}
}
void inorder(int i)
{f-r
  if(i>=size)
  {

  	return ;
  }
  inorder(left(i));
  cout<<arr[i]<<" ";
  inorder(right(i));
}
};
int main()
{
heap h(10);
h.insert(10);
h.insert(20);
h.insert(30);
h.insert(50);
h.insert(60);
h.insert(70);
h.insert(80);
h.inorder(0);
cout<<endl;
cout<<h.extract_min()<<endl;
h.inorder(0);
h.decrease(5,5);
cout<<endl;
h.inorder(0);
h.del(7);
cout<<endl;
h.inorder(0);
}