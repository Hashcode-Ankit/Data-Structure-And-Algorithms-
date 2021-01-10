/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<algorithm>
using namespace std;
int max_sum(int a[],int n,int k)
{
sort(a,a+n);
 for(int i=0;i<n-1;i++)
 {
	 int j=i+1;
	 if(a[i]==a[j])
	 {
		 for(j=i+1;j<n;j++)
		 {
			 if(j==n-1){
				 a[j]=0;
			 }
			 else{
				 a[j]=a[j+1];
				 n--;
			 }
		 }
	 }
 }
 int sum=0;
  for(int i=n-1;i<k;i--)
	{
  sum+=a[i];
	}
	return sum;
}
int main()
{
	int t,n,k;

	cin>>t;
	
	for(int j=1;j<=t;j++)
	{
		if(t<=100000 && t>=1)
	{
		cin>>n;
     cin>>k;
	}
	int arr[n];
	if(n<=100000 && n>=1)
	{
		 	
	for(int i=0;i<n;i++)
   {
	    cin>>arr[i];
   }
	}
int sum=	max_sum(arr,n,k);
cout<<sum;
}
return 0;
}