#include <iostream>
#include <cmath>
usingnamespace std;
 
double f(int N,int i)
{
if(i!=N)
{
returnsqrt(i+f(N,i+1));
}
else{returnsqrt(N);}
}
 
int main()
{
int N;
double y;
cout<<"N=";cin>>N;
int i=1;
if(N<0)
{cout<<"***Ошибка***"<<endl;return0;}
	y=f(N,i);
cout<<"y=F(N)="<<N/y<<endl;
return0;
}
