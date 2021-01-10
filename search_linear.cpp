#include<iostream>
using namespace std;
void linear_search(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			cout<<"element at the index " <<i<<endl;
			return ;
		}
	}
	cout<<"element is not in the array"<<endl;
}
int main()
{
	int n;
	cout<<"enter the number of elements in the array"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter elements in the array"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int x;
	cout<<"enter the mumber to search"<<endl;
	cin>>x;
	linear_search(a,n,x);
	return 0;
}