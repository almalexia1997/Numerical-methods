#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const int n=10;
double u (double x, double y){ //точное решение
	return x*x*x+n*y*y*y+x+n*y++0.1*n;}
double f (double x, double y){ //неоднородность уравн. Пуассона
	return -6*x-6*n*y;}
double norma (double nor[][100], int N1, int N2) // норма
{
	double norm = 0;
	for (int i = 0; i <= N1; i++)
		for (int j = 0; j <= N2; j++)
			norm += pow(nor[i][j], 2);
	return sqrt(norm);
}
int main()
{
	int N1=5,N2=6,iter=0;
	double w =1.5, l1 =1, l2 =1;
	double h1 =l1/N1, h2 =l2/N2;
	double a = -1/(h1*h1);
	double b = -1/(h2*h2);
	double c = 2/(h1*h1) +2/(h2*h2) ;
	double eps = h1*h1 + h2*h2;
	// описание массивов Nev,Y,Y1,Popr,Pogr
	// начальное приближение итераций
	// задание краевых условий
	
	//начало итерационного процесса
	do
	{iter++; // число итераций
	{// предыдущая итерация 𝒀𝒌=𝒀𝟏𝒌−𝟏
	// невязка
	// итерационная формула мет.верхн.релаксации
	// поправка, погрешность
	} while (norma(Popr, N1, N2) > eps // конец итераций
	//вывод результатов
	cout<<" Reshenie: "<<endl;
	for(int i=0;i<=N1;++i, cout<<endl) 
		for(int j=0;j<=N2;++j)
			cout<<fixed<< setprecision(4)<<Y[i][j]<<" ";
	cout<<" Tochnoe reshenie: "<<endl;
	for(int i=0;i<=N1;++i, cout<<endl) 
		for(int j=0;j<=N2;++j)
			cout<<fixed<< setprecision(4)<<u(i*h1, j*h2)<<" ";
	cout<<endl;
	cout<<"Norma popravki = "<< <<endl;
	cout<<" Norma nevyazki = "< < ?<< ?<<endl;
	cout<<" Norma pogreshnosti = "<< ?<<endl;
	cout<<" Kolichestvo iteraciy = "<<iter<<endl;
	cout<<" eps = "<<eps<<endl;
	cout<<" w = "<<w<<endl;
	cout<<"\t"<<N1*h1<<"\t"<<N2*h2<<endl;
	return 0;
}
