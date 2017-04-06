#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
usingnamespace std;
 
constdouble AreaQuarter =0.25;
 
class Triangle
{
private:
double a;
double b;
double c;
staticint count;//статическая переменная для подсчета количества объектов класса
 
public:
 
//Конструктор без параметров
Triangle();
//конструктор инициализации
Triangle(double inA, double inB, double inC);
//Функция, возвращающая значение статического поля
int GetCount();
//Функция, выводящая информацию о треугольнике
void GetInfo();
//Функции, выводящие периметр
double GetPerimeter();
void PrintPerimeter();
//Функция, выводящая площадь
double GetArea();
//Функция, выводящая длину сторон
void GetSide();
//Функция, выясняющая существует ли треугольник или нет
bool GetProof();
//Функция, вызывающая методы класса
void Methods();
//Перегрузка унарных операций
void operator ++();
void operator --();
//Перегрузка бинарных операции
Triangle operator *(double scalar);
bool operator >(Triangle temp);
};
 
int Triangle::count=0;//инициализировали счетчик объектов
 
int main()
{
 
	setlocale(LC_ALL,"Russian");
double a,b,c;//стороны треугольника
int n;//количество треугольников
int i=0;//счетчик для цикла while
	ifstream in("input.txt");
	ofstream out("output.txt");
if(!in)
{
cout<<"Error input"<<endl;
return0;
}
else
{
	in>>n;
	vector<Triangle>arr( n );//контейнер с экземплярами класса
	vector<bool>checkbox(n,false);//контейнер с флажками помеченных экземпляров
while(in.peek()!=EOF)
{
		in>>a;
		in>>b;
		in>>c;
		arr[i]={a,b,c};//используем конструктор инициализации
		i++;
}
for(int i=0;i<(int)arr.size();i++)
{
cout<<"arr["<<i<<"]"<<endl;
		arr[i].Methods();//выводим всю информацию о треугольнике с помощью метода Methods()
cout<<endl;
}
cout<<"Сравнение: Какой из треугольников больше?"<<endl;
for(int i=0;i<(int)arr.size();i++)
{
for(int j=i+1;j<(int)arr.size();j++)
{
 
if(arr[i]>arr[j])
cout<<"arr["<<i<<"]>arr["<<j<<"]"<<endl;
elsecout<<"arr["<<i<<"]<=arr["<<j<<"]"<<endl;
 
}
}
cout<<"\nCount="<< arr[0].GetCount()-1<< endl;
}
return0;
}
//определения методов
 
Triangle::Triangle()
{
	a=0;
	b=0;
	c=0;
	count+=1;
}
Triangle::Triangle(double inA, double inB, double inC)
{
if(!GetProof())
{
		a=0;
		b=0;
		c=0;
}
else
{
		a=inA;
		b=inB;
		c=inC;
}
count+=1;
}
void Triangle::operator++()
{
++a;
++b;
++c;
}
void Triangle::operator--()
{
--a;
--b;
--c;
}
Triangle Triangle::operator*(double scalar)
{
return Triangle(a*scalar, b*scalar, c*scalar);
}
bool Triangle::operator>(Triangle temp)
{
double S1=(*this).GetArea();
double S2=temp.GetArea();
if(S1>S2)
returntrue;
else
returnfalse;
}
void Triangle::GetInfo()
{
if(a == b || a == c || b == c)
cout<<"треугольник - равнобедренный"<< endl;
if(a == b && b== c)
cout<<"треугольник - равносторонний"<< endl;
if((a*a + b*b == c*c)||(a*a + c*c == b*b)||(b*b + c*c == a*a))
cout<<"треугольник - прямоугольный"<< endl;
}
double Triangle::GetPerimeter()
{
return a + b + c;
}
 
void Triangle::PrintPerimeter()
{
cout<<GetPerimeter()<<endl;
}
 
double Triangle::GetArea()
{
return AreaQuarter*sqrt((a + b + c)*(b + c - a)*(a + c - b)*(a + b - c));
}
void Triangle::GetSide()
{
cout<<"Длина стороны а="<< a << endl;
cout<<"Длина стороны b="<< b << endl;
cout<<"Длина стороны с="<< c << endl;
}
int Triangle::GetCount()
{
return count;
}
bool Triangle::GetProof()
{
if(c <(a + b)|| a <(c + b)|| b <(c + a))
{
returntrue;
}
else
{
returnfalse;
}
}
void Triangle::Methods()
{
	GetSide();
if(GetProof())
{
cout<<"треугольник существует"<< endl;
		GetInfo();
		PrintPerimeter();
cout<<"S="<<GetArea()<<endl;
}
else
cout<<"треугольник не существует"<< endl;
}
