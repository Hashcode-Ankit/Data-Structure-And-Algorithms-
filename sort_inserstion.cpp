#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
	for (int i = 1; i < n; ++i)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			
			arr[j+1]=arr[j];
			j--;
            
		}
		arr[j+1]=key;
	}

}
int main()
{
	int n;
	cout<<"enter the size of the array to short using insertion_sort time complexity o(n^2)"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the elements to be shorted"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	insertion_sort(arr,n);//calling to insertion sort
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
return 0;
}