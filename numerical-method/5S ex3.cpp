//Метод Адамса
#include <iostream>
#include <cmath>
using namespace std;
const int N=21; // vhodnye dannye
double fun(double x,double u) // funkcija pravoi' chasti ODU
{
return 2*x*u*u+u;}
int main()
{
double a=0, b=0.8, h,x[50],y[50],f[50];
h=(b-a)/(N-1);  //  ??
x[0]=0;x[1]=h ;x[2]=2*h ;
y[0]=0.5,y[1]=-1./(2*x[1]-2.); y[2]=-1./(2*x[2]-2.);
for (int k=2;k<N;k++)
{
y[k+1]=y[k]+h/12*(23*fun(x[k],y[k])-16*fun(x[k-1],y[k-1])+5*fun(x[k-2],y[k-2]));
x[k+1]=x[k]+h;
}
for (int k=0;k<N;k++)
cout<<fixed<<" "<<x[k]<<" "<<y[k]<<" "<< -1./(2*x[k]-2)<<endl;
return 0;
}
