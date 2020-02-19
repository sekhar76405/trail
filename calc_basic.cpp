// Write program for a calculator
// Which should perform 5 operations
// 1-addition
// 2-subtraction
// 3-division
// 4-multiplication
// 5-modulus
// There should be only 2 inputs which has to be entered by the user at runtime when a 
// constructor is called and all the operations have to be performed with the help of
// these two operations.



#include <iostream>
using namespace std;

class sum
{
    public:
    sum(){}
    
    sum(int x,int y)
    {
        int c=x+y;
        cout<<"the sum of the two numbers is: "<<c;
    }
};

class sub
{
    public:
    sub(){}
    sub(int x,int y)
    {
        int c=x-y;
        cout<<"the difference of the two numbers is: "<<c;
    }
};

class prod
{
    public:
    prod(){}
    prod(int x,int y)
    {
        int c=x*y;
        cout<<"the product of the two numbers is: "<<c;
    }
};

class divi
{
    public:
    divi(){}
    divi(int x,int y)
    {
        float c=x/y;
        cout<<"the quotient of the two numbers is: "<<c;
    }
};

class mod
{
    public:
    mod(){}
    mod(int x,int y)
    {
        int c=x%y;
        cout<<"the modulus of the two numbers is: "<<c;
    }
};


int main()
{
    int a,x,y;
    cout<<"Enter two numbers : ";
    cin>>x>>y;
    cout<<"press\n 1 to add\n 2 to subtract \n 3 to multiply\n 4 to divide \n 5 to modulus \n";
    cin>>a;
    switch(a)
    {
        case 1:
        {
            sum ob1(x,y);
            break;
        }
        
        case 2:
        {
            sub ob1(x,y);
            break;
        }
        case 3:
        {
            prod ob1(x,y);
            break;
        }
        case 4:
        {
            divi ob1(x,y);
            break;
        }
        case 5:
        {
            mod ob1(x,y);
            break;
        }
    }
    return 0;
}

