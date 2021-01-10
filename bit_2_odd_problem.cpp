#include<iostream>
using namespace std;
int main()
{
  cout<<"enter the value of "<<endl;
  int n;
  cin>>n;
  int arr[n];
  cout<<"enter the elements of the array"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
int ans=0;
for(int i=0;i<n;i++)
{
  ans=ans^arr[i];
}
int ans1=0,ans2=0;
int res=ans & ~(ans-1);
for(int i=0;i<n;i++)
{
 if((arr[i] & res)!=0)
 {
  ans1=ans1^arr[i];
 }
 else{
  ans2=ans2^arr[i];
 }
}
cout<<"results are "<<ans1<<" "<<ans2<<endl;
return 0;
}