#include<iostream>
#include<unordered_set>
using namespace std;
int max_consecutive(int arr[],int n)
{
  int count=1;
  int res=0;
  unordered_set<int> s;
  for(int j=0;j<n;j++)
  {
   s.insert(arr[j]);
  }
  for(int i=0;i<n;i++)
  {
    if(s.find(arr[i]-1)!=s.end())
      continue;
    else{
      while(s.find(arr[i]+count)!=s.end())
        count++;
      res=max(count,res);
    }
  }
  return res;
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
cout<<max_consecutive(arr,n);
  	return 0;
}