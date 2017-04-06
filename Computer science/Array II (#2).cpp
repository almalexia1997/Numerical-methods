#include <iostream>
#include <cmath>
usingnamespace std;
int main()
{
int n,min;
cout<<"n=";cin>> n;
int*a =newint[n];
for(int i =0; i < n; i++)
{
cin>> a[i];
}
if(n==0)
{
cout<<"ничего нет";return0;
}
min = a[0];
for(int i =0; i < n; i++)
{
if(a[i]< min)
min = a[i];
}
for(int i =0; i < n; i++)
{
if(a[i]== min)
cout<< i <<" ";
}
return0;
}
