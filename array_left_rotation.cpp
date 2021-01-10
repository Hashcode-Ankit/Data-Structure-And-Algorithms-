#include<iostream>
using namespace std;
void left_rotation(int arr[],int n,int k)
{
  int rotate=k%n;
  for (int i = 0; i < n; ++i)
  {
    cout<<arr[(i+rotate)%n]<<" ";
  }
}
int main()
{
  int n;
  cout<<"enter the size of the array "<<endl;
  cin>>n;
  int arr[n];
  cout<<"enter the elements of the array"<<endl;
  for (int i = 0; i < n; ++i)
  {
    cin>>arr[i];
      /* code */
  }
  int k;
  cout<<"Rotation to do "<<endl;
  cin>>k;
  left_rotation(arr,n,k);
  return 0;
}