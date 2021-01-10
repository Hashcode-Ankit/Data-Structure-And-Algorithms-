#include<iostream>
#include<vector>

using namespace std;
int main()
{
	vector<int> v;
	v.push_back(4);
	cout<<"here is the capacity of the vector  "<<v.capacity()<<endl;
	cout<<"the number of elements in vector  "<<v.size()<<endl;
	v.push_back(5);
	cout<<" at second element \n here is the capacity of the vector  "<<v.capacity()<<endl;
	cout<<"the number of elements in vector  "<<v.size()<<endl;
	v.push_back(9);
	cout<<"at third element \n here is the capacity of the vector  "<<v.capacity()<<endl;
	cout<<"the number of elements in vector  "<<v.size()<<endl;
	vector<int> :: iterator it;
	for(it=v.begin();it<v.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<"\n\n\n";
	cout<<v.front()<<endl;
	cout<<v.back()<<endl;
	cout<<"\n\n\n";
	 it=v.begin();
	v.insert(it+2,10);
	for(it=v.begin();it<v.end();it++)
	{
		cout<<*it<<endl;
	}
	v.erase(it);
    for(it=v.begin();it<v.end();it++)
	{
		cout<<*it<<endl;
	}
		return 0;
}