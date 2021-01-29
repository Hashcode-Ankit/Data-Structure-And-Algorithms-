#include<iostream>
#include<unordered_map>
using namespace std;
string winner(string arr[],int n)
{
  string winner;
  unordered_map<string,int> s;
  for(int i=0;i<n;i++)
  {
  	s[arr[i]]++;
  }
  int max=0;
  for(int i=0;i<n;i++)
  {
     if(s[arr[i]]>max)
     {
     	winner=arr[i];
     	max=s[arr[i]];
     }
  }
  return winner;
}
int main()
{
	int n;
	cout<<"enter the number of voters"<<endl;
	cin>>n;
	string arr[n];
	cout<<"enter whom they voted"<<endl;
	for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
	cout<<"winner of the elections : "<<winner(arr,n);	
}
 ////////////////////////////////
#include <bits/stdc++.h>

using namespace std;
int reach(long n)
{
    if((n&(n-1))==0)
    {
      return (n>>1);
    }
    else {
        int s=n;
    while((n&(n-1))!=0)
    {
        n=n&(n-1);
    }
   return (s-n);
    }
}

// Complete the counterGame function below.
string counterGame(long n) {
    if(n==1)
    {
        return "Richard";
    }
    while(n!=1)
    {
        n=reach(n);
        if(n==1)
        {
            return "Louis";
        }
        n=reach(n);
         if(n==1)
        {
            return "Richard";
        }
    }
    return "rechard";
}
int main()
{
    long n;
    cin>>n;
  cout<<  counterGame(n);
}