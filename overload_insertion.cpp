#include<iostream>
using namespace std;
class student{
	int roll;
	string st_name;
public:
	student(int roll_call,string name)
	{
		roll=roll_call;
		st_name=name;
	}
	friend ostream &operator<<(ostream &dout,student &s);
};
ostream &operator<<(ostream &dout,student &s)
{
	dout<<"here is the students roll  "<<s.roll;
	dout<<"\nhere is student name  "<<s.st_name;
		return dout;
}
int main()
{
	student s(13,"ankit");
	cout<<s;
return 0;
}