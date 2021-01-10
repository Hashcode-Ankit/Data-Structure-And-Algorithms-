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
if(l==r-1)
{
	if(a[l]<a[r])
{	m.min=a[l];
	m.max=a[r];
}
else{
	m.min=a[r];
	m.max=a[l];
}
return m;
}
else{
	int mid=(l+r)/2;
	struct mm m1=minmax(a,l,mid);
	struct mm m2=minmax(a,mid+1,r);
	if(m1.min<m2.min)
	{
		m.min=m1.min;
	}
	else{
		m.min=m2.min;
	}
    if(m1.max<m2.max)
	{
		m.max=m2.max;
	}
	else{
		m.max=m1.max;
	}
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