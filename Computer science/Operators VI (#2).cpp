#include <iostream>
#include <iomanip>
#include <cmath>
usingnamespace std;
 
constdouble eps =1e-6;
 
float f(double x)
{
if(abs(x)<3-eps)
returnsin(x);
else
if((3-eps <=abs(x))&&(abs(x)<9-eps))
returnsqrt(x*x +1)/sqrt(x*x +5);
else
returnsqrt(x*x +1)-sqrt(x*x +5);
}
int main()
{
double a, b, h;
cout<<"a=";cin>> a;
cout<<"b=";cin>> b;
cout<<"h=";cin>> h;
cout<<"x\tf(x)\n"<< endl;
cout<< fixed << setprecision(6);
for(double x = a; x <= b+eps; x += h)
{
cout<< x <<"\t"<< f(x)<< endl;
}
return0;
}
