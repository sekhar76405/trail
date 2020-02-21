
#include <iostream>
using namespace std;


class student
{
    int roll;
    char nam[20];
    int bat;
    
    public:
    student(){}
    
    void id()
    {
        cout<<"the id of student is ";
        cin>>roll;
    }
    void name()
    {
        cout<<"the name of student is ";
        cin>>nam;
    }
    void batch()
    {
        cout<<"the batch of student is ";
        cin>>bat;
    }
    
    void display()
    {
        cout<<"the student details:- "<<roll<<","<<nam<<","<<bat<<"\n";
        
    }
};




int main()
{
    student ob[3];
   for(int i=1;i<=3;i++)
   {
      ob[i].id();
      ob[i].name();
      ob[i].batch();
      cout<<"\n\n";
   }
   for(int i=1;i<=3;i++)
   {
      ob[i].display();
      cout<<"\n\n";
   }
   
    
    return 0;
}

