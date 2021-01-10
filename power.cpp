#include<iostream>
using namespace std;
long long int power(int x,int p)
{
	if(p==1)
		return x;
	else
		{if(p%2==0)
		return power(x,p/2)*power(x,p/2);
	    else
		return power(x,p/2)*power(x,p/2)*x; 
	    }
}
int main()
{
int a,p;
cout<<"enter the number"<<endl;
cin>>a;
cout<<"enter the power of the number"<<endl;
cin>>p;
long long int ans=power(a,p);
cout<<"required answer is "<<ans<<endl;
return 0;

}