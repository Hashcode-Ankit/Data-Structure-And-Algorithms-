#include<iostream>
#include<set>
using namespace std;
void remove_duplicates(int arr[],int n)
{
	set<int> s;
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);
	}
	for(auto j: s)
	{
		cout<<j<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<"enter the size of the array"<<endl;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	remove_duplicates(arr,n);
return 0;

}