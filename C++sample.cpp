# include <iostream>
#include <iomanip >
using namespace std ;
int main ()
{
	
int alpha[50];
for (int i=0;i<25;i++)
{
alpha[i]=i/i;
cout<<alpha[i]<<" ";
}
for(int i=25;i<50;i++)
{
alpha[i]=3/i;
cout<<alpha[i]<<" ";
}
for(int i=1 ; i<51 ; i++)    {                           
    {
            
            cout<<setw(3)<<alpha[i-1]<<" ";
            if( (i+1)%10 == 0)
            cout<<endl;
    }
    
}
return 0;
}