#include <iostream>
#include <cmath>
#include <iomanip>
usingnamespace std;
int main()
{
double x, y;
cout<<"Enter x"<<endl;cin>> x;
cout<<"Enter y"<<endl;cin>> y;
cout<< fixed << setprecision(6)<< endl;
double S =(exp(-x)-cos(x)+sin(2*x* y));
cout<<"S="<< S;
return0;
}
