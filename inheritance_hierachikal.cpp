/*Programme FOr multiple Inheritance with base classes parameterized construcotr and having base class as Abstract claass*/
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
public:
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
	virtual void showdata()=0; //again defining pure virtual function so that we can not create any object of the class
	
};
class teacher:public school{    //derived class of base class 
	string name;
	string qualification;
public:
	void showdata()
	{
		cout<<"Teacher name"<<name<<endl;
		cout<<"teacher qualification"<<qualification<<endl;
	}
};
class marks : public student{ // derived class from derived class student which is further derived from base class school
	int subjects;	int student_marks;
public:
	marks(int subj,int stud_marks,string student_name,int stdd,int roll_number,string school_name,string address):student(student_name, stdd,roll_number,school_name,address)
  {
  	subjects=subj;
  	student_marks=stud_marks;
  }
  void showdata()    //polymorphism of showdata
	{
		cout<<"The School Where Student study: "<<school_name<<"\n";
		cout<<"School is Situated at: "<<location<<"\n";
		cout<<"Student's Name: "<<name<<"\n";
		cout<<"Student Class: "<<std<<"\n";
		cout<<"Student Roll number: "<<roll_call<<"\n";
		cout<<"Student  have marks prcentage: "<<(student_marks/subjects)<<"%\n";

	}
};
int main()
{
	marks s(5,400,"Ankit",12,106,"JNV","JIND");
	s.showdata();

	return 0;	
}