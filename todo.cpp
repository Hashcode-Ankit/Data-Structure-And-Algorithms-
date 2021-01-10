#include <iostream>
#include<ctime>
#include<regex>
#include <stdio.h>
#include<string>
using namespace std;
int completed=0;
int pending=0;
class todo                            //todo class having data members which needed to develop 
{
    public:
      string s;
      int key;
      todo* next=NULL;
}*start=NULL;
void add(todo* b)                     // todo add function which will be called when add command is entered
{
     if(start==NULL)
     {
        b->key=1;
        start=b;
        cout<<"Added todo: \""<<b->s<<"\""<<endl;
        pending++;
     }
     else
     {
        int i=2;
        todo* temp=start;
        while(temp->next!=NULL)
        {
          i++;
          temp=temp->next;
        }
        b->key=i;
        temp->next=b;
        cout<<"Added todo: \""<<b->s<<"\""<<endl;
        pending++;
     }
}
void ls(todo* temp)
{
   if(temp!=NULL){
     ls(temp->next);
    cout<<"["<<temp->key<<"] "<<temp->s<<endl;
   
   }
}
void done_number(int key)
{
  if(start==NULL)
  {
      cout<<"empty list"<<endl;
      return;
  }
  else if(key==1)
  {
      todo* temp=start->next;
      start=temp;
      cout<<"Marked done todo #"<<key<<endl;
      completed++;
      pending--;
       int i=1;
       todo* teemp=start;
        while(teemp!=NULL)
        {
          teemp->key=i;
          i++;
          teemp=teemp->next;
        }
      return ;
  }
  else
  {
    todo* temp=start;
    todo* tempp=start->next;
    while(tempp!=NULL)
    {
      if(tempp->key==key)
      {
      temp->next=tempp->next;  
      pending--;
      completed++;
      cout<<"Marked todo #"<<key<<" as done"<<endl;
       int i=1;
       todo* teemp=start;
       while(teemp!=NULL)
        {
          teemp->key=i;
          i++;
          teemp=teemp->next;
        }
      return ;
      }
      temp=temp->next;
      tempp=tempp->next;
    }
    cout<<"Error: todo #"<<key<<" does not exist."<<endl;

  }
}
void del_number(int key)                         //todo function to delete the task
{
  if(start==NULL)
  {
    cout<<"empty todo list"<<endl;
  }
  else if(key==1)
  {
    todo* temp=start->next;
    start=temp;
    cout<<"Deleted todo #"<<key<<endl;
    int i=1;
    todo* teemp=start;
    while(teemp!=NULL)
    {
        teemp->key=i;
        i++;
        teemp=teemp->next;
    }
    pending--;
  }
  else
  {
     todo* temp=start;
    todo* tempp=start->next;
    while(tempp!=NULL)
    {
          if(tempp->key==key)
          {
          temp->next=tempp->next;
          pending--;
          cout<<"Deleted todo #"<<key<<endl;
          todo* teemp=start;
          int i=1;
          while(teemp!=NULL)
          {
              teemp->key=i;
              i++;
              teemp=teemp->next;
          }
          return ;
          }
          else
          { cout<<"Error:todo #"<<key<<" does not exist. Nothing deleted"<<endl;
          }
           temp=temp->next;
          tempp=tempp->next;
    }
  }
 
}
void report(){
  time_t t;    struct tm* tm;
    char Date[11], Time[11];
    
    time(&t);
    tm = localtime(&t);
    
    strftime(Date, sizeof Date, "%Y-%m-%d", tm);
    cout<<Date<<" ";
   cout<< "Pending : "<<pending<<"  Completed  : "<<completed<<endl;
}
int main()
{
 int n;
 string s;
 string a="usage";
 while(a!="exit") 
 {
    cout<<"\n"<<"Usage:-"<<endl;
    cout<<"add \"todo item\"         #add a new todo  :: without upper qoutes write todo task with space"<<endl;
    cout<<"ls                     #show remaining"<<endl;
    cout<<"del Number             #delete a todo :: enter the number after writing command"<<endl;
    cout<<"done Number            #done todo :: enter the number after writing the command"<<endl;
    cout<<"help                   #show usage"<<endl;
    cout<<"report                 #statistics"<<endl;
    cout<<"exit                   #to exit from your todo list :: Warning Your all to do item will be lost"<<endl;
    cin>>a;
    todo* b=new todo();
           if(a=="add")
           {
            getline(cin>>ws,s);
            s.erase(remove(s.begin(),s.end(),'\"'),s.end());
            b->s=s;
            add(b);
           
           }
           else if(a=="ls")
           {
            ls(start);
            
           }
           else if(a=="delete")
           {
            cin>>n;
            del_number(n);
          
           }
           else if(a=="done")
           {
            cin>>n;
            done_number(n);
         
           }
           else if(a=="help")
           {
             a="usage";  
           }
           else if(a=="report")
           {
            report();
          

           }
           else{
            if(a!="exit")
            {
              cout<<" choose from the usage"<<endl; 
            }
           }
 }
 return 0;
}
