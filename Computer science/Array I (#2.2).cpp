#include <iostream>
#include <cmath>
#include <iomanip>
 
usingnamespace std;
 
void print(int**mas, int n, int m)
{
for(int i =0; i<n; i++, cout<< endl)
for(int j =0; j<m;++j)cout<< setw(10)<<right << mas[i][j]<<"\t";
}
 
void read(int**mas2, int n,int m)
{
for(int i =0; i<n;++i)
{
for(int j =0; j<m;++j)
cin>> mas2[i][j];
}
}
 
int main()
{
int n, m,k, ch=0;
cout<<"n=";cin>> n;
cout<<"m=";cin>> m;
cout<<"k=";cin>> k;
 
int**a =newint*[n];
for(int i =0; i<n;++i) a[i]=newint[m];
 
read(a,n,m);
 
for(int i =0; i<n;++i)
{
for(int j =0; j < m;++j)
{
if(a[i][j]< k)
{
a[i][j]= k;
ch++;
}
}
}
if(ch>0) print(a, n, m);
elsecout<<"замен нет"<<endl;
 
for(int i =0; i<n;++i)delete[] a[i];
delete[] a;
 
return0;
}
