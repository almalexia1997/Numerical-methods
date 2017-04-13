// h) , n=8,   Гиперболическое уравнение
#include<iostream>
#include<cmath>
#include<iomanip>
#include <algorithm>
using namespace std;

const int N = 7, n0 = 9; //const double pi=3.14159;
const double l=4, T=2, c=1;

//ПРОТОТИПЫ
double norma(double **nor, int N, int n0); //функция нормы
void progonka(int n, double g0, double gN, double A, double B, double C, double *F, double *y1); // функция прогонки
//double u(double x, double t); // точное решение
double f(double x, double t); //правая часть волнового уравнения
double u0(double x); // начальное условие 0-го временного слоя
double uu0(double x, double tau); //начальное условие 1-ой производной
double uk0(double t); // краевое условие при x=0
double ukN(double t); // краевое условие при x=l

int main()
{
	//1) Задаем начальные данные
	double g0, eps, gN, A, B, C;
	double h = l / N;
	double tau = T / n0;
	double sigma = 0.5;
	double gam = tau / h;
	cout<<"h="<<h<<"; gam="<<gam<<"; tau="<<tau<<"; sigma="<<sigma<<endl;
	double *F = new double[N + 1], *y1 = new double[N + 1]; //массивы для F и y1
	double **y = new double*[N + 1]; for (int i = 0; i < N + 1; ++i)y[i] = new double[n0 + 1];//массив для y
	double **pogr = new double*[50]; for (int i = 0; i < 50; ++i) pogr[i] = new double[50]; //массив для pogr
	A = sigma*gam*gam; B = sigma*gam*gam; C = 1. + 2.*sigma*gam*gam;
	eps = h*h + tau*tau; // теоретическая погрешность разностной схемы

	//2) Аппроксимируем заданные функции сеточными функциями
	for (int i = 0; i <= N; i++){
		y[i][0] = u0(i*h); // начальные условия прибл.реш
		y[i][1] = u0(i*h) + tau*uu0(i*h, tau);
	}
	for (int k = 0; k <= n0; k++){
		y[0][k] = uk0(k*tau); // краев. услов. прибл.решения
		y[N][k] = ukN(k*tau);
	}
	//3) Неявный метод
	for (int k = 1; k<n0; k++) //цикл по временным слоям
	{
		for (int i = 1; i<N; i++)
		{	//правая часть разн.сх. для прогонки
			F[i] = (2 * y[i][k] - y[i][k - 1]) + tau*tau*(1. - 2.*sigma)*
			((y[i - 1][k] - 2.*y[i][k] + y[i + 1][k]) / (h*h)) + sigma*tau*tau*
			((y[i - 1][k - 1] -	2.*y[i][k - 1] + y[i + 1][k - 1]) / (h*h)) + tau*tau*f(i*h, k*tau);
			// краевые. усл. для прогонки
			g0 = y[0][k + 1];
			gN = y[N][k + 1];
		}
		//метод прогонки
		progonka(N, g0, gN, A, B, C, F, y1);
		for (int i = 0; i <= N; i++)
			y[i][k + 1] = y1[i]; // построение решения
	}
	//Вывод всех результатов
	cout << "reshenie" << endl;
	for (int k = 0; k <= n0; k++, cout << endl)
		for (int i = 0; i <= N; i++)
			cout << fixed << setprecision(4) << y[i][k] << " ";
	/*cout << "tochnoe reshenie" << endl;
	for (int k = 0; k <= n0; k++, cout << endl)
		for (int i = 0; i <= N; i++)
			cout << fixed << setprecision(4) << u(i*h, k*tau) << " "; // tochnoe reshenie*/
	cout << endl << "sigma= " << sigma << endl << endl;
	/*for (int i = 0; i <= N; i++)
		for (int j = 0; j <= n0; j++)
			pogr[i][j] = fabs(y[i][j] - u(i*h, j*tau)); // погрешность
	cout << endl << " norma pogreshnosti " << norma(pogr, N, n0) << endl;*/
	cout << endl << "epsilon= " << eps << endl;
	return 0;
}
// ФУНКЦИИ

/*double u(double x, double t){
	return n*x*x*x*t*t*t + x*t + x*n + 1;
}*/

double f(double x, double t) {
	return x*x*x*(l-x*x)*t;
}
double u0(double x){
	return 0;
}
double uu0(double x, double tau){
	return 0;
}
double uk0(double t){
	return t*0.5;
}
double ukN(double t){
	return 0;
}

void progonka(int N, double g0, double gN, double A, double B, double C, double *F, double *y)
{
	double *alf = new double[N], *bet = new double[N];
	alf[1] = 0;
	bet[1] = g0;
	for (int i = 1; i <= N - 1; i++)
	{
		alf[i + 1] = B / (C - A*alf[i]);
		bet[i + 1] = (F[i] + A*bet[i]) / (C - A*alf[i]);
	}
	y[N] = gN;
	for (int j = N - 1; j >= 0; j--)
		y[j] = alf[j + 1] * y[j + 1] + bet[j + 1];
}


double norma(double **nor, int N, int n0)
{
	double sum, m = 0;
	for (int k = 0; k <= n0; k++){
		sum = 0;
		for (int i = 0; i <= N; i++){
			sum += pow(fabs(nor[i][k]), 2);
		}
		m = max(m, sqrt(sum));
	}
	return m;
}
