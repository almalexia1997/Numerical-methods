#include <iostream>
#include <cmath>
#include <iomanip>
usingnamespace std;
int main()
{
int n;cout<<"n=";cin>> n;
int k;cout<<"k=";cin>> k;
int*a =newint(n);
for(int i =0; i < n;++i)
{
cout<<"a["<< i <<"]=";cin>> a[i];
}
for(int i =0; i < n;++i)
{
if(a[i]< k)
{
 a[i]= k;
}
}
for(int i =0; i < n;++i)
{
if(i ==0)
{
cout<< endl;
}
cout<<"a["<< i <<"]=";cout<< a[i]<<" ";
}
return0;
}
