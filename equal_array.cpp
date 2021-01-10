#include<iostream>
using namespace std;
int duplicates(int arr[],int n)
{
    int k=0;
    int temp[n];
    for (int i = 0; i < n-1; ++i)
    {
       if(arr[i]!=arr[i+1])
       {
           temp[k]=arr[i];
           k++;
       }
    }
    temp[k]=arr[n-1];
    for (int i = 0; i < k; ++i)
    {
       arr[i]=temp[i]; /* code */
    }
    return k;
}
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
void compare(int arr[],int brr[],int n,int m)
{
 if(n!=m)
 {
    cout<<"array not equal "<<endl;
 }
 else
 {
    for (int i = 0; i < n; ++i)
    {
       if(arr[i]==brr[i])
       {
        cout<<"array equal"<<endl;
       }
    }
 }
}
int main()
{
    int n;
    int m;
    cout<<"enter the size of the first array"<<endl;
    cin>>n;
    cout<<"enter the size of the second array"<<endl;
    cin>>m;
    int arr[n];
    int brr[m];
    cout<<"enter the elements of the first array"<<endl;
    for (int i = 0; i < n; ++i)
    {
        /* code */cin>>arr[i];
    }
    cout<<"enter the elements of the first array"<<endl;
    for (int i = 0; i < m; ++i)
    {
        /* code */cin>>brr[i];
    }
    selection_sort(arr,n);
    selection_sort(arr,m);
    int p= duplicates(arr,n);
    int q=duplicates(brr,m);
    compare(arr,brr,p,q);
    return 0;
}