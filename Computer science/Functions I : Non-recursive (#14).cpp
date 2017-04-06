#include <iostream>
#include <cmath>
usingnamespace std;
 
int sum(int i)
{
int sum=0;
while(i>0)
{
		sum+=i%10;
		i/=10;
}
return sum;
}
 
int main()
{
int a,b,n,s,c;
cout<<"a=";cin>>a;
cout<<"b=";cin>>b;
cout<<"Заданное значение: "<<endl;cin>>n;
for(int i=a;i<=b;++i)
{
		s=sum(abs(i));
if(s==n)
{
cout<<i<<" ";
			c++;
}
}
if(c==0)cout<<"нет подходящих"<<endl;
return0;
}
