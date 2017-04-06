#include <iostream>
#include <cmath>
#include <iomanip>
usingnamespace std;
int main()
{
double x, y;
cout<<"Enter x"<< endl;cin>> x;
cout<<"Enter y"<< endl;cin>> y;
if(x*x + y*y<81&& x>0)
cout<<"Yes";
elseif(x*x + y*y >81|| x <0)
cout<<"No";
elsecout<<"on the border"<<endl;
 
return0;
}
