#include <iostream>
usingnamespace std;
double min(double a, double b)
{
return(a > b)? b : a;
 
}
int main()
{
double x, y, z, v;
cout<<"x=";cin>> x;
cout<<"y=";cin>> y;
cout<<"z=";cin>> z;
cout<<"v=";cin>> v;
cout<<"min="<< min(min(min(x, y), z), v);
return0;
}
