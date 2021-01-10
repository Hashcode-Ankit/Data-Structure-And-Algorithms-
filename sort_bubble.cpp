#include<iostream>
using namespace std;
void bubbleshort(int arr[])  //Function for bubble short 
{
   
    for(int i=0;i<5;i++)
    {
        int  flag=true;
        for(int j=0;j<5-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                 flag=false;
                 long  int temp=arr[j+1];
                 arr[j+1]=arr[j];
                 arr[j] =temp; 
            }

        }
        if(flag==true)
            return;
    }
}
int main()
{

    int arr[5];
    cout<<"enter the elements of the array to short the array using bubble short"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    bubbleshort(arr);
      for(int i=0;i<5;i++)
    {
        cout<<"  " <<arr[i];
    }
    cout<<endl<<"here is the value"<<arr[4];
    return 0;
}
