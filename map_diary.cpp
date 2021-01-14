#include<iostream>
#include<map>
using namespace std;
map<string,long long int> m;
void add(string name,long long number)
{
	auto it =m.find(name);
	if(it!=m.end())
	{
		cout<<"value already exist"<<endl;
	    return ;
	}
	m[name]=number;
	cout<<"successfully added"<<endl;
}
void erase(string name)
{
 auto it= m.find(name);
 if(it!=m.end())
 {
 	m.erase(it);
 	cout<<"number successfully deleted"<<endl;
 }
 else
 {
  cout<<"given name does not found "<<endl;
 }
}
void find(string name)
{
	auto it =m.find(name);
	if(it!=m.end())
	{
		cout<<"Number is "<<it->second<<endl;
	}
	else{
		cout<<"number not found"<<endl;
	}
}
int main()
{
  int t=1;
  string name;
  long long number;
  while(t)
  {
  	cout<<"0. to execute from the programme"<<endl;
  	cout<<"1 Insert the number in the dictionary"<<endl;
  	cout<<"2. Erase the number from the phone book"<<endl;
  	cout<<"3. To find a given number "<<endl;
    cout<<"enter the operation you want to perform"<<endl;
    cin>>t;
    switch(t)
    {
    	case 0:
    	break;
    	case 1:
    	cout<<"enter the name of the person "<<endl;
    	getline(cin>>ws,name);
    	cout<<"enter the valid number of the person"<<endl;
        cin>>number;
    	add(name,number);
    	break;
    	case 2:
    	cout<<"enter the name whose number have to delete"<<endl;
    	getline(cin>>ws,name);
    	erase(name);
    	break;
    	case 3:
    	cout<<"enter the name whose number you have to find"<<endl;
    	getline(cin>>ws,name);
    	find(name);
    	break;
    	default :
    	cout<<"enter the correct value from the menu"<<endl;
    }
}
}







/* new programme */

#include<iostream>
#include<map>
using namespace std;
multimap<string,long long int> m;
void add(string name,long long number)
{
	// auto it =m.find(name);
	// if(it!=m.end())
	// {
	// 	cout<<"value already exist"<<endl;
	//     return ;
	// }
	m.insert(pair<string,long long int>(name,number));
	cout<<"successfully added"<<endl;
}
void erase(string name)
{
 auto it= m.find(name);
 if(it!=m.end())
 {
 	m.erase(it);
 	cout<<"number successfully deleted"<<endl;
 }
 else
 {
  cout<<"given name does not found "<<endl;
 }
}
void find(string name)
{
	
	for(auto it =m.find(name);it!=m.end();it++)
	{
		cout<<"Number is "<<it->second<<endl;
	}
	
}
int main()
{
  int t=1;
  string name;
  long long number;
  while(t)
  {
  	cout<<"0. to execute from the programme"<<endl;
  	cout<<"1 Insert the number in the dictionary"<<endl;
  	cout<<"2. Erase the number from the phone book"<<endl;
  	cout<<"3. To find a given number "<<endl;
    cout<<"enter the operation you want to perform"<<endl;
    cin>>t;
    switch(t)
    {
    	case 0:
    	break;
    	case 1:
    	cout<<"enter the name of the person "<<endl;
    	getline(cin>>ws,name);
    	cout<<"enter the valid number of the person"<<endl;
        cin>>number;
    	add(name,number);
    	break;
    	case 2:
    	cout<<"enter the name whose number have to delete"<<endl;
    	getline(cin>>ws,name);
    	erase(name);
    	break;
    	case 3:
    	cout<<"enter the name whose number you have to find"<<endl;
    	getline(cin>>ws,name);
    	find(name);
    	break;
    	default :
    	cout<<"enter the correct value from the menu"<<endl;
    }
}
}