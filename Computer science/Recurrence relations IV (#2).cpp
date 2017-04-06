#include <iostream>
#include <cmath>
#include <iomanip>
usingnamespace std;
 
double fun(double x, double eps, int&n)
{
double sum =0, a =1;
n =0;
while(abs(a)>= eps)
{
sum += a;
a *=-x /(2*7*(n +1));
if(n>0)
{
a *=7* n;
};
cout<<" "<<a<<endl;
n++;
}
return sum;
}
 
 
int main()
{
double a, b, eps, h, f, x;
cout<<"a=";cin>> a;
cout<<"b=";cin>> b;
cout<<"h=";cin>> h;
cout<<"eps=";cin>> eps;
int i, n;
cout<< setprecision(3);
cout<<"i \tx \t f(x) \tn \n";
for(x = a, i =1; x <= b+eps; x += h, i++)
{
f = fun(x, eps, n);
cout<< i <<"\t"<< x <<"\t"<< f <<"\t"<< n <<endl;
}
return0;
}
