#include <iostream>
#include <cmath>
usingnamespace std;
 
bool Chislo (int k)
{
if(k==1)returnfalse;
int c=0, u=floor((sqrt(k)));
for(int i=2;i<=u;++i)
{
if(k%i==0)
		c++;
}
if(c==0)
returntrue;
elsereturnfalse;
}
 
int main()
{
setlocale(LC_ALL, "Russian");
int a,b,ch=0;cout<<"Введите координаты отрезка: \n";
cout<<"a = ";cin>>a;
cout<<"b = ";cin>>b;
for(int i=a;i<=b;++i)
if(Chislo(i))
{cout<<i<<" ";ch++;}
cout<<"количество всех простых чисел на отрезке ["<<a<<","<<b<<"]="<<ch;
return0;
}
