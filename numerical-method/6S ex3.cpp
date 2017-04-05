// h) , n=8,   Гиперболическое уравнение
#include<iostream>
#include<cmath>
#include<iomanip>
#include <algorithm>
using namespace std;

const int N = 5, n0 = 7, n = 8; //const double pi=3.14159;

//ПРОТОТИПЫ
double norma(double **nor, int N, int n0); //функция нормы +
void progonka(int n, double g0, double gN, double A, double B, double C, double *F, double *y1); // функция прогонки +
double u(double x, double t); // tochnoe resh.+
double f(double x, double t); //правая часть волн.ур.+
double u0(double x); // нач. усл. 0-го врем.слоя+
double uu0(double x, double tau); //началь.усл. 1-ой производной 
double uk0(double t); // краев. усл. при x=0+
double ukN(double t); // краев. при x=l+

int main()
{
	double g0, eps, gN, A, B, C, *F = new double[N + 1], *y1 = new double[N + 1];
	double **y = new double*[N + 1]; for (int i = 0; i < N + 1; ++i)y[i] = new double[n0 + 1];
	double **pogr = new double*[50]; for (int i = 0; i < 50; ++i) pogr[i] = new double[50];
	double h = 1. / N;
	double tau = 0.5 / n0;
	double gam = tau / h;
	double sigma = 0.5;
	A = sigma*gam*gam; B = sigma*gam*gam; C = 1. + 2.*sigma*gam*gam;
	eps = h*h + tau*tau; // теоретич.погр.разн.схемы

	for (int i = 0; i <= N; i++){
		y[i][0] = u0(i*h); // ??  u(i*h,0)начальные условия прибл.реш
		y[i][1] = u0(i*h) + tau*uu0(i*h, tau);  //  ??  u(i*h,0)
	}
	for (int k = 0; k <= n0; k++){
		y[0][k] = uk0(k*tau);
		y[N][k] = ukN(k*tau);
	} // краев. услов. прибл.решения
	for (int k = 1; k<n0; k++) //цикл по временным слоям
	{
		for (int i = 1; i<N; i++)
		{
			F[i] = (2 * y[i][k] - y[i][k - 1]) + tau*tau*(1. - 2.*sigma)* //правая часть разн.сх. для прогонки
				((y[i - 1][k] - 2.*y[i][k] + y[i + 1][k]) / (h*h)) + sigma*tau*tau*((y[i - 1][k - 1] -
				2.*y[i][k - 1] + y[i + 1][k - 1]) / (h*h)) + tau*tau*f(i*h, k*tau);
			g0 = y[0][k + 1];
			gN = y[N][k + 1]; // краевые. усл. для прогонки
		}
		progonka(N, g0, gN, A, B, C, F, y1);
		for (int i = 0; i <= N; i++)
			y[i][k + 1] = y1[i]; // построение решения
	}
	cout << "reshenie" << endl;
	for (int k = 0; k <= n0; k++, cout << endl)
	for (int i = 0; i <= N; i++)
		cout << fixed << setprecision(4) << y[i][k] << " ";
	cout << "tochnoe reshenie" << endl;
	for (int k = 0; k <= n0; k++, cout << endl)
	for (int i = 0; i <= N; i++)
		cout << fixed << setprecision(4) << u(i*h, k*tau) << " "; // tochnoe reshenie
	cout << endl << "sigma= " << sigma << endl << endl;
	for (int i = 0; i <= N; i++)
	for (int j = 0; j <= n0; j++)
		pogr[i][j] = fabs(y[i][j] - u(i*h, j*tau)); // погрешность
	cout << endl << " norma pogreshnosti " << norma(pogr, N, n0) << endl;
	cout << endl << " epsilon= " << eps << endl;
	return 0;
}
// ФУНКЦИИ
double f(double x, double t) {
	return 6 * n*x*x*x*t - 6 * n*x*t*t*t;
}
double u0(double x){
	return n*x + 1;
}
double uu0(double x, double tau){
	return x;
}
double uk0(double t){
	return 1;
}
double ukN(double t){
	return n*t*t*t + t + n + 1;
}
double u(double x, double t){
	return n*x*x*x*t*t*t + x*t + x*n + 1;
}

void progonka(int N, double g0, double gN, double A, double B, double C, double *F, double *y)
{
	double *alf=new double[N], *bet=new double[N];
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
