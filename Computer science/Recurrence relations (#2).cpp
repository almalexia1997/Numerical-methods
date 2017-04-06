#include <iostream>
#include <iomanip>
usingnamespace std;
int main()
{
int b1,b2,bn,n;//b1 - первый член, b2- bn-1, bn - последний.
	b1 =-1;
	b2 = b1;
cout<<"до какого числа хотите вычислить?"<<endl<<"n=";cin>> n;
if(n ==1)
{
cout<<"b1="<< b1 <<"\t";
}
if(n ==0)
{
cout<<" ";
}
elseif(n >1)
{
cout<<"b1="<< b1 <<"\t";
}
for(int i =2; i <= n; i++)//высчитывает только первые 30 членов последовательности
{
if(n >1)
{
 
			bn =9-2* b2;
cout<<"b"<< i <<"="<< bn <<"\t";
			b2 = bn;
}
 
}
return0;
}
