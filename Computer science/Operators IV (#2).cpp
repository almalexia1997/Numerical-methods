#include <iostream>
usingnamespace std;
int main()
{
int m, n;
cout<<"количество строк";cin>> m;
cout<<"количество столбцов";cin>> n;
for(int i =1; i <= m;++i, cout<< endl)
{
for(int j =1; j <= n;++j)
{
cout<< j <<"\t";
}
}
return0;
}
