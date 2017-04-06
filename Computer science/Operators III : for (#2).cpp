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
cout<< endl;
for(; i >= n; i--)
if(i %2==0)
cout<< i << endl;
return0;
}
