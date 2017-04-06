#include <iostream>
#include <iomanip>
usingnamespace std;
int main()
{
int  n, i;
cout<<"Со скольки начинать?"<< endl;
cin>> i;
cout<<"До скольки заканчивать?"<< endl;
cin>> n;
if(i>n)
do
{
cout<< i << endl;
		i -=2;
}while(i >= n);
elsecout<<"Неправильно задан отрезок";
return0;
}
