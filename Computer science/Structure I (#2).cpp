#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <locale> //кириллица
usingnamespace std;
 
 
struct coordinates //создали тип данных для координат точки
{
double x, y;
void show();
double dlina();
};
 
void coordinates::show()
{
cout<<"Координаты точки :("<< x <<","<< y <<")"<< endl;
double d = dlina();
cout<<"Расстояние до начала координат:"<< d << endl;
cout<< endl;
}
 
double coordinates::dlina()//длина радиус вектора
{
returnsqrt(pow(x, 2)+pow(y, 2));
}
 
int main()
{
	setlocale(LC_ALL, "Russian");//всегда в начале функции
int n;
cout<<"Введите количество точек в множестве: ";
cin>> n;
	vector<coordinates>a(n);//динамический массив множества произвольных точек
if(n ==0)cout<<"Нет точек"<< endl;
else{
for(int i =0; i < n;++i)
{
cout<<"Введите координаты точки №"<< i <<": ";
cin>> a[i].x>> a[i].y;
 
 
}
cout<<"Наши точки: "<< endl;
int t =0;
double max = a[0].dlina();
for(int i =0; i < n;++i)
{
			a[i].show();
if(a[i].dlina()>max)
{
				max = a[i].dlina();
				t = i;
}
}
cout<<"*************************"<< endl;
cout<<"Наиболее удаленная точка: "<< endl;
		a[t].show();
}
return0;
}
