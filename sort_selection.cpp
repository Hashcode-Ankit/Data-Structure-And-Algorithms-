
#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
		for(int i=0;i<n;i++)
		{
		      for(int j=i+1;j<n;j++)
		      {
			       if(arr[j]<arr[i])
				       {
					       	int temp=arr[j];
					       	arr[j]=arr[i];
					       	arr[i]=temp;
				       }
			      }
		}
}
int main()
{
	cout<<"enter the size of the array"<<endl;
	int n;
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	selection_sort(arr,n);
	for (int i = 0; i < n; i++)
	{
	    cout<<arr[i]<<" ";
	}
	return 0;
}