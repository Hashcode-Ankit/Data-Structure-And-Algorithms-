#include<iostream>
using namespace std;
struct mm{
	int min;
	int max;
};
struct mm minmax(int a[],int l,int r)
{
	struct mm m;
if(l==r)
{
m.min=a[l];
m.max=a[l];
return m;
}
if(a[l]>a[l+1])
{
	m.min=a[l+1];
	m.max=a[l];
}
else{
	m.min=a[l];
	m.max=a[l+1];
}
for(int i=l+2;i<=r;i++)
{
	if(a[i]>m.max)
		m.max=a[i];
	else if(a[i]<m.min)
		m.min=a[i];
}
return m;

}
int main(){
	int n;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	struct mm m=minmax(a,0,n-1);
	cout<<"Minimum in the array "<<m.min<<endl;
	cout<<"maximum in the array"<<m.max<<endl;
 return 0;

}