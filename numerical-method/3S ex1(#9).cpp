#include<iostream>
#include<cmath>
#include<fstream>
 
usingnamespace std;
 
ofstream out1("nine1.txt");
ofstream out2("nine2.txt");
ofstream out3("nine3.txt");
 
constdouble eps =1e-6;
 
//first
double func1(double x, int n)
{
double sum =0;
double xn=1.0;
while(abs(xn)>eps)
{
		sum += xn;
		n++;
		xn*=-(x*x*x*x/((2*(n-1)+1)*(2*(n-1)+2)));
}
return sum;
}
 
//second
double func2(double x, int n, double max)
{
double sum =0;
double xn=1.0;
double q=1;
while(abs(xn*q)>eps)
{
        sum += xn;
        n++;
        xn*=-(x*x*x*x/((2*(n-1)+1)*(2*(n-1)+2)));
        q=abs(max*max*max*max/(4*n*n-max*max*max*max));
}
return sum;
}
 
int main()
{
int n, ch;
double sum1, sum2, a, b, h, prof;
	n=0, prof=500.0; ch=1;
cout<<"a=";cin>>a;
cout<<"b=";cin>>b;
	h=(b-a)/500.0;
double max=(fabs(a)>fabs(b))?(fabs(a)):(fabs(b));
for(double x=a; x<=b; x+=h)
{
		out1<<x<<' ';
		sum1 = func1(x,n);
		out1<<sum1<<'\n';
 
		out2<<x<<' ';
		sum2 = func2(x,n,max);
		out2<<sum2<<'\n';
 
		out3<<x<<' ';
		out3<<cos(x*x)<<'\n';
 
cout<<ch<<"/"<<prof<<endl;//прогресс в подсчете
		ch++;
}
cout<<h<<endl;
cout<<eps<<endl;
return0;
}
