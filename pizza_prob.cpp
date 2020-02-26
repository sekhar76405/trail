#include<iostream>
using namespace std;

int main()
{
    int a[16],ar[8];
    int sum[8],sum1;
    int c=0,b=3,g,t;
    
    for(int i=0;i<8;i++)
        cin>>a[i];
        
    for(int h=0;h<8;h++)
       ar[h]=a[h];
        
    for(g=8,t=0;g<16,t<8;g++,t++)
        a[g]=ar[t];
    
    for(int k=0;k<8;k++)
    {   
       sum1=0;
       for(int j=c;j<=b;j++)
       {
           sum1=sum1+a[j];
       }
       
       sum[k]=sum1;
       //cout<<sum[k]<<endl;
       
       if(c==0&&b==3){c=1;b=4;}
       else if(c==1&&b==4){c=2;b=5;}
       else if(c==2&&b==5){c=3;b=6;}
       else if(c==3&&b==6){c=4;b=7;}
       else if(c==4&&b==7){c=5;b=8;}
       else if(c==5&&b==8){c=6;b=9;}
       else if(c==6&&b==9){c=7;b=10;}
       else if(c==7&&b==10){c=8;b=11;}
       else if(c==8&&b==11){break;}
    }
    
    for(int q=1;q<8;++q)
    {
        if(sum[0]<sum[q])
        {
            sum[0]=sum[q];
        }
    }
    cout<<sum[0];
    return 0;
}