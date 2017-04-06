#include <iostream>
#include <iomanip>
#include <cmath>
usingnamespace std;
int main()
{
double s,n,a;
	s =0;
	a =0;
cout<<"n=";cin>> n;
cout<< fixed << setprecision(6);
for(int i =1; i <= n; i++)
{
cout<<sqrt(i);
		a =sqrt(i);
		s += a;
if(i<n)
cout<<"+";
}
cout<<"="<< s;
return0;
}
