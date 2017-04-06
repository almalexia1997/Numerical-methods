#include <iostream>
#include <cmath>
usingnamespace std;
int main()
{
double fact,s,k,b;
b =1;//инициализировали 2 в степени n
fact =1;//инициализировали fact
s =0;//инициализировали сумму
cout<<"k=";cin>> k;//до какого числа считать
for(int i =1; i <= k; i++)//начинаем считать с единицы по условию
{
 
b *=2;//2 в степени n
fact *= i;//n факториал
 
s +=(b*fact)/(i*i);//накапливаем сумму
cout<<"*"<<(b*fact)/(i*i)<<" ";
}
cout<< s;
return0;
}
