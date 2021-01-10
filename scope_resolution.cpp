/* Defining Member Function Outside The Class Using Scope Resolution Operator*/
#include<iostream>
using namespace std;
class student{    //automatically private 
	string name;
	int roll_number;
	int std;
public:
	student()
	{
		cout<<"written by Ankit Sharma"<<endl;
	}
	void getdata(string u_name,int n,int stdd)
	{   name=u_name; //Name Of the student 
		roll_number=n; // Roll Number of the student   Programme by ::  Ankit Sharma
		std=stdd; //For class Of the student
	}
  void showdata();
};
void student  :: showdata()
 {
	cout<<"Student Name is "<<name<<"\n";
	cout<<"Student Roll Number is "<<roll_number<<"\n";
	cout<<"Student Class is "<<std<<"\n";
}

int main()
{
int roll,std;
		string name;
		student s;
		cout<<"enter the name of the student  \n";
		cin>>name;
		cout<<"enter the class of the student \n";
		cin>>std;
		cout<<"enter the roll number of the student \n";
		cin>>roll;
		s.getdata(name,roll,std);
		s.showdata();
	return 0;
}