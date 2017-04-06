#include <iostream>
#include <cmath>
usingnamespace std;
 
int main()
{
int n;cout<<"n=";cin>> n;
int*b =newint[n];
 
for(int i =0; i < n;++i)
{
cin>> b[i];
}
 
int max = b[0];//ищем максимальный элемент
for(int i =0; i < n;++i)
{
if(b[i]>max)
{
			max = b[i];
}
else max = max;
}
 
int*a =newint[n];int j =0;
for(int i =0; i < n;++i)
{
if(b[i]== max)
{
//a[j] = i; j++;
for(int j = i; j<n -1; j++)
				b[j]= b[j +1];
			n--;
			i--;
}
}
for(int i =0; i<n;++i)
cout<< b[i]<<" ";
//здесь начинается шняга
 
/*for (int i = 0; i < j; ++i) //выполняем удаление пока счетчик не сравняется с кол-вом макс индексов
	{
	if (i != 0)//если а[i]==0, то мы уменьшим индекс, а надо уменьшать когда уже сдвинули а мы еще не сдинули.
	{
	a[i]--;
	}
	int k = a[i];
	for (int i = k; i < n - 1; i++)b[i] = b[i + 1]; n--;
	}
	if(n==0)
	{
	cout<<"Все удалено к чертям"<<endl;
	}
 
	for (int i = 0; i < n; ++i) cout << b[i]<<" ";
 
 
 
	delete[]b;
	delete[]a;*/
return0;
}
