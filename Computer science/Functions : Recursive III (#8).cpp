#include <iostream>
#include <cmath>
usingnamespace std;
 
void Nature (int x)
{
if(x!=0)
{
        Nature(x/10);
cout<<x%10<<" ";
}
 
}
 
int main()
{
int A,B;
cout<<"A=";cin>>A;
cout<<"B=";cin>>B;
if(A>B)
{
cout<<"error: A>B"<<endl;
return0;
}
elseif(A<0&& B<0)
{
cout<<"error: A and B - negative"<<endl;
return0;
}
elseif(A==0&& B==0)
{
cout<<"error: A=B=0"<<endl;
}
for(int i=A;i<=B;++i)
{
if(i>0)
{
            Nature(i);
cout<<endl;
}
}
return0;
 
}
