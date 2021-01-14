#include<iostream>
#include<unordered_set>
using namespace std;
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
  int sum=0;
  unordered_set<int> s;
  s.insert(0);
  for(int j=0;j<n;j++)
  {
  	sum+=arr[j];
  	if(s.find(sum)!=s.end())
  	{
  		cout<<"yes"<<endl;
  		return 0;
  	}
  	
  	s.insert(sum);
  }
  	cout<<"no there does not exist any pair with sum 0"<<endl;
  	return 0;
}