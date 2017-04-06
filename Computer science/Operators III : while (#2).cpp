#include <iostream>
usingnamespace std;
int main()
{
int i, n;
cout<<"со скольки начинать?";cin>> i;
cout<<"до скольки заканчивать?";cin>> n;
while(i >= n)
{
cout<< i << endl;
		i -=2;
}
if(i < n)
{
cout<<"не правильно задан отрезок";
}
return0;
}
