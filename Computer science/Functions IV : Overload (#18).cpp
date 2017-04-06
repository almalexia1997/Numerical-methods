#include <iostream>
#include <cmath>
usingnamespace std;
 
float F(float x)
{
if(x<3)
{
return x*x-0.3;
}
elseif(3<=x && x<=5)
{
return'0';
}
else
{
return x*x+1;
}
}
 
void F(float x, float&y)
{
	y=F(x);
}
 
int main()
{
float x,y;
cout<<"x=";cin>>x;
	F(x,y);
cout<<"F(x,y)="<<y<<endl;
cout<<"F(x)="<<F(x)<<endl;
return0;
}
