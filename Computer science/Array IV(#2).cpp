#include <iostream>
#include <cmath>
usingnamespace std;
 
int**creat(int&n)
{
cout<<"n=";cin>> n;
int**mass =newint*[n];
for(int i =0; i < n;++i) mass[i]=newint[n];
for(int i =0; i < n;++i)
{
for(int j =0; j < n;++j)
{
cout<<"mas["<< i <<"]["<< j <<"]=";cin>> mass[i][j];
}
}
return mass;
}
 
 
 
int main()
{
int n, min;
int**a = creat(n);
int*b =newint[n];
int k =0;
for(int j =0; j < n;++j)
{
		b[j]=0; min = a[0][j];
for(int i =0; i < n; i++)
{
if(a[i][j]< min)
{
				min = a[i][j];
				b[j]= a[i][j];
}
else b[j]= min;
}
}
for(int j =0; j < n;++j)
cout<< b[j]<<"\t";
for(int i =0; i < n; i++)delete[] a[i];
delete[]a;
delete[]b;
return0;
}
