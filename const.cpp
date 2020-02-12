#include<iostream>
using namespace std;


class sample
{

	
public:

    int x,y;
    sample()
	{
	  x=0;
	  y=0;
	  cout<<" default constructor called successfully!\n";
	}

    sample(int a, int b)

	{
	 x=a;
	 y=b;
	 cout<<"parametrised constructor successfully ! \n";
	}

    sample(const sample &d)
	{
	 x=d.x;
	 y=d.y;
	 cout<<"copy constuctor called successfully! \n";
	}

    sample sum(sample m,sample n)
	{
	 sample c;
	 c.x=m.x+n.x;
	 c.y=m.y+n.y;
	 return c;
	}
  

};


int main()
{

 sample s1,s2,s4;

 cout<<"enter 2 numbers";
 cin>>s2.x>>s4.x;
 

 
 sample s3(s4);

 cout<<" "<<s3.x<<" "<<s3.y<<"\n";
 
 s1=s3.sum(s4,s2);
 
 cout<<" "<<s1.x<<"\n";
 

 return 0;


}


			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
