/*Programme FOr Single Inheritance with base class parameterized construcotr and having base class as Abstract claass*/
#include<iostream>
using namespace std;
class school{
public:
   string school_name;
   string location;
public:
	school(string name,string locate)
	{
		school_name=name;
		location=locate;
	}
	virtual void showdata()=0;   //define pure virtual function so that no object not be created of the class 
};
class student : public school{
    string name;
    int std;
    int roll_call;
public:
	student(string student_name,int stdd,int roll_number,string school_name,string address):school(school_name,address)   //showing programme having parametrized constructor in base class
	{
		name=student_name;
		std=stdd;
		roll_call=roll_number;
	}
	void showdata()
	{
		cout<<"The School Where Student study: "<<school_name<<"\n";
		cout<<"School is Situated at: "<<location<<"\n";
		cout<<"Student's Name: "<<name<<"\n";
		cout<<"Student Class: "<<std<<"\n";
		cout<<"Student Roll number: "<<roll_call<<"\n";
	}
};
int main()
{
	student s("Ankit",12,106,"JNV","JIND");
	s.showdata();

	return 0;	
}