#include<iostream>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
	int temp[r+1];
	int i=l;
	int j= m+1;
	int k=l;
	while(i<=m  && j<=r)
	{
		      if(arr[i]<=arr[j])
		      {
		      	temp[k]=arr[i];
		      	k++;
		      	i++;
		      }
		      else
		      {
		      	temp[k]=arr[j];
		      	j++;
		      	k++;
		      }
	}
	while(i<=m)
	{
			temp[k]=arr[i];
			i++;
			k++;
	}
	while(j<=r)
	{
		temp[k]=arr[j];
		k++;
		j++;
	}
	for (int p=l ;p<r+1; ++p)
	{
		arr[p]=temp[p];
	}

}
void merge_sort(int arr[],int l,int r)
{
  if(l<r)	
  {
  	int mid=(l+r)/2;
  	merge_sort(arr,l,mid);
  	merge_sort(arr,mid+1,r);
  	merge(arr,l,mid,r);

  }
}
int main()
{
	int n;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	merge_sort(arr,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<" " <<arr[i];/* code */
	}
return 0;
	
}