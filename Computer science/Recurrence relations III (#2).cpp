#include <iostream>
#include <cmath>
usingnamespace std;
int main()
{
double eps, sum,xn;
int i, znam;
i =1; sum =0; xn =0.125; znam =1;
cout<<"eps=";cin>> eps;
while(abs(xn)> eps)
{
sum += xn;
i++;
znam =(i +1)*(i +1)*(i +1);
xn =1.0/ znam;
}
cout<<"sum="<< sum;
return0;
}
