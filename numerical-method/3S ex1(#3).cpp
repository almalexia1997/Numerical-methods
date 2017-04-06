#include<iostream>
#include<cmath>
#include<fstream>
 
usingnamespace std;
 
ofstream out1("tree1.txt");
ofstream out2("tree2.txt");
constdouble eps =1e-2;
 
double func1(double x, double n)
{
double an =sin(x);
double sum =0;
while(abs(an)>eps)
{
		sum += an;
		n++;
		an =sin(n*x)/(n*n*n);
}
return sum;
}
 
double func2(double x, double n)
{
double an =sin(x);
double sum =0;
while((1.0/(2* n*n))>eps)
{
		sum += an;
		n++;
		an =sin(n*x)/(n*n*n);
}
return sum;
}
 
int main()
{
int n, ch;
double eps, sum1, sum2, a, b, h, prof;
	n=1, prof=500; ch=1;
cout<<"a=";cin>>a;
cout<<"b=";cin>>b;
	h=(b-a)/prof;
for(double x=a; x<=b;)
{
		out1<<x<<' ';
		sum1 = func1(x,n);
		out1<<sum1<<'\n';
		out2<<x<<' ';
		sum2 = func2(x,n);
		out2<<sum2<<'\n';
		x+=h;
cout<<ch<<"/"<<prof<<endl;//прогресс в подсчете
		ch++;
}
return0;
}
