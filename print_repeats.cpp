#include<iostream>
#include<unordered_set>
using namespace std;
void print_repeats(int arr[],int n){
	unordered_set<int> s;
	cout<<"repeating elements  ";	
	for(int i=0;i<n;i++)
	{
		if(s.find(arr[i])!=s.end())
		{
			cout<<arr[i]<<" ";
		}
		s.insert(arr[i]);
	}
}
int main()
{
int n;
cout<<"enter the size of the array"<<endl;
cin>>n;
cout<<"enter the elements of the array"<<endl;
int arr[n];
for(int i=0;i<n;i++)
{
	cin>>arr[i];
}
print_repeats(arr,n);
}