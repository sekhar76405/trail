#include<iostream>
using namespace std;

int main()
{
    int x=0,y=0,z=0;
    cout<<" "<<"x"<<" "<<"y"<<" "<<"z"<<" "<<"x&&y||z"<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<" "<<x<<" "<<y<<" "<<z<<"   "<<(x&&y||z)<<endl;
        if(i==0){x=0;y=0;z=1;}
        else if(i==1){x=0;y=1;z=0;}
        else if(i==2){x=0;y=1;z=1;}
        else if(i==3){x=1;y=0;z=0;}
        else if(i==4){x=1;y=0;z=1;}
        else if(i==5){x=1;y=1;z=0;}
        else if(i==6){x=1;y=1;z=1;}
    }
    return 0;
}
