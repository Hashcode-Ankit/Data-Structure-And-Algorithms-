#include<iostream>
#include<set>
using namespace std;
void count(int arr[],int n,int x)
{
	multiset<int> s;
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);
	}
	cout<<s.count(x)<<endl;
}
int main()
{
	int n;
	cout<<"enter the size of the array"<<endl;
    cin>>n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int x;
	cout<<"enter the number to check how much time it occurs"<<endl;
	cin>>x;
	count(arr,n,x);
return 0;

}