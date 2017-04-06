#include <iostream>
#include <iomanip>
#include <cmath>
usingnamespace std;
 
constdouble eps=1e-6;
void f(double x)
{
if((abs(x-1)<eps)||(abs(x+1)<eps))
cout<<"не определена";
elsecout<<1/(x*x -1);
}
int main()
{
double a, b, h;
cout<<"a=";cin>> a;
cout<<"b=";cin>> b;
cout<<"h=";cin>> h;
cout<<"x\tf(x)\n"<<endl;
cout<<setprecision(6)<<fixed;
for(double x = a; x < b+eps; x += h)
{
cout<< x <<"\t";
f(x);
cout<< endl;
}
return0;
}
