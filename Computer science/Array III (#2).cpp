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
cout<<"mass["<< i <<"]["<< j <<"]=";cin>> mass[i][j];
}
}
return mass;
}
 
int main()
{
int n;
int sum =0, ch =0;
double sredarifm =0;
int**a = creat(n);
for(int i =0; i < n;++i)
{
for(int j =0; j < n;++j)
{
if(i >j && a[i][j]>0)
{
sum += a[i][j];
ch++;
}
}
}
sredarifm =(double) sum / ch;
cout<< sredarifm << endl;
return0;
for(int i =0; i < n; i++)delete[] a[i];
delete[]a;
}
