#include <iostream>
#include <cmath>
#include <iomanip>
usingnamespace std;
int main()
{
int x, y;
cout<<"Number month"<< endl;cin>> x;
cout<<"Day"<< endl;cin>> y;
switch(x)
{
case1:case3:case5:case7:case8:case10:
if(y >31)cout<<"ERROR";
elsecout<<31- y << endl;break;
case4:case6:case9:case11:
if(y >30)cout<<"ERROR";
elsecout<<30- y << endl;break;
case2:if(y >28)cout<<"ERROR";//не берем во внимание високосные года
elsecout<<28- y << endl;break;
default:cout<<"Error"<< endl;
 
}
return0;
}
