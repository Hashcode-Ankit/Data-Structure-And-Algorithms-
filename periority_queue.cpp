#include<iostream>
#include<queue> ///////////     remains to learn with user defined comparator//////////s
#include<vector>
using namespace std;
int main()
{
vector<int> v={10,20,30};
    priority_queue<int> pq(v.begin(),v.end());
    cout<<pq.top()<<endl;
    cout<<pq.size();
    pq.pop();
    cout<<endl<<pq.size();
    if(!pq.empty())
     {
	cout<<endl<<"kya khe diya hai"<<endl;
     }
    else
     {
	cout<<"kuch na kha hmne"<<endl;
     }
}