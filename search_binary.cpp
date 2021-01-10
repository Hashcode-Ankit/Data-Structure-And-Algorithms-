#include<iostream>
using namespace std;
void  binarySearch(int a[],int left,int right,int x)
{
	if(left<=right)
	{
		int mid = (left + right ) / 2;
		if(a[mid]==x)
		cout<<mid<<" element position";
		else if(a[mid]<x)
		 binarySearch(a,mid+1,right,x);
		else if(a[mid]>x)
		 binarySearch(a,left,mid-1,x);
	}

}

int main()
{
	int n,x;
	cout<<"enter the number of elements in the array"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter the elements of the array"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"enter the element to search in the array "<<endl;
	cin>>x;
	binarySearch(a,0,n-1,x);
	return 0;
}