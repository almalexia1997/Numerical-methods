//Эллептическое уравнение №8, n=10. Юсупов Р.
#include <iostream>
#include <cmath>
#include <iomanip>

const int N1 = 5, N2 = 6;
int n=10;

using namespace std;

double u(double x, double y)
{
	return x*x*x + n*y*y*y + x + n*y + 0.1*n;
}
double f(double x, double y)
{
	return (-6*x-6*n*y);
}

double norma (double nor[N1+1][N2+1], int N1, int N2)
{
	double norm = 0;
	for (int i = 1; i < N1; i++)
		for (int j = 1; j < N2; j++)
			norm += pow(nor[i][j], 2);
	return sqrt(norm); //Евклидова норма
}

int main()
{
	//Объявление переменных
	int iter = 0;
	double w = 1.4, l1 = 1., l2 = 1.;
	double h1 = l1/N1, h2 = l2/N2;
	double a = -1./(h1*h1);
	double b = -1./(h2*h2);
	double c = 2./(h1*h1) + 2./(h2*h2);
	double eps = h1*h1 + h2*h2;
	double Nev[N1+1][N2+1], Y[N1+1][N2+1], Y1[N1+1][N2+1], Popr[N1+1][N2+1], 
	Pogr[N1+1][N2+1];
	//произвольное начальное приближение
	for (int i = 1; i < N1; i++)
		for (int j = 1; j <N2; j++)
			Y[i][j] = 1.;
	//задаем сеточные функции
	for(int i = 0; i <= N1; i++){
		Y[i][0] = i*h1*i*h1*i*h1+i*h1+0.1*n;     //   ?? mu2(i*h1);
		Y[i][N2] = i*h1*i*h1*i*h1+2*n+i*h1+0.1*n;//mu4(i*N2);
	}
	for(int j = 0; j <= N2; j++){
		Y[0][j] =n*pow(j*h2,3)+n*j*h2+0.1*n;  //  ??   -j*h2*j*h2;//mu1(j*h2);
		Y[N1][j] =  n*pow(j*h2,3) + n*j*h2+2+0.1*n;  //  ??  1.-j*h2*j*h2;// mu3(j*N1);
	}
	//МВР
	do
	{
		iter++;
		for (int i = 1; i < N1; i++)
			for (int j = 1; j < N2; j++){
				//сохраняем приближение
				Y1[i][j] = Y[i][j];
				//невязка
				Nev[i][j] = a*Y[i-1][j] + b*Y[i][j-1] + c*Y[i][j] +
				a*Y[i+1][j] + b*Y[i][j+1] - f(i*h1,j*h2);
				Y[i][j] = Y[i][j] - w*Nev[i][j]/c;
				//Поправка
				Popr[i][j]=Y[i][j]-Y1[i][j];
				Pogr[i][j]=Y[i][j]-u(i*h1,j*h2);
			}
	}
	while (norma(Nev, N1, N2) > eps); //ищем норму
    //Вывод данных
	cout << "Reshenie:" << endl;
	for(int i = 0; i <= N1; ++i, cout << endl)
		for(int j = 0; j <= N2; ++j)
			cout << fixed << setprecision(4) << Y[i][j] << " ";
	cout << "Tochnoe reshenie: " << endl;
	for(int i = 0; i <= N1; ++i, cout << endl)
		for(int j = 0; j <= N2; ++j)
			cout << fixed << setprecision(4) << u(i*h1, j*h2) << " ";
	cout << endl;
	cout << "Norma popravki = " <<norma(Popr,N1,N2) << endl;
	cout << "Norma nevyazki = " << norma(Nev,N1,N2) << endl;
	cout << "Norma pogreshnosti = " << norma(Pogr,N1,N2) <<endl;
	cout << "Kolichestvo iteraciy = " << iter << endl;
	cout << "eps = " << eps << endl;
	cout << "w = " << w << endl;
	cout << "N1*h1=" << N1*h1 << ";\tN2*h2=" << N2*h2 << endl;
	return 0;
}
 
