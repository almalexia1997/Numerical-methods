//Параболическое уравнение, неявный метод
#include<iostream>
#include<cmath>
#include<iomanip>
#include <algorithm>
using namespace std;

const int N = 10;
const int n0 = 8;
const int n = 6; //  ??   1.6;
double fun(double x, double t); // функция точ.решен.
double f(double x, double t);
double u0(double x); // функция начальн.условия
double ux0(double t); // функция краевого услов. в x=0
double uxl(double t); // функция краевого услов. в x=l
void progonka(double g0, double gN, double A, double B, double C, double *F, double *y); // функция прогонки
double norma(double **nor, int N, int n0);

int main()
{
	double l = 1, T = 1, h = l / N, tau = T / n0, sigma = 0.5, gamma = tau / (h*h), g0, gN;
	double A, B, C, F1[N + 1][n0 + 1], *y1 = new double[N], *F = new double[N], *x = new double[N + 1], *t = new double[n0 + 1];
	double **y = new double*[N + 1]; for (int i = 0; i < N + 1; ++i)y[i] = new double[n0 + 1];
	double **nor = new double*[N + 1]; for (int i = 0; i < N + 1; ++i)nor[i] = new double[n0 + 1];
	A = B = sigma*gamma;
	C = 1 + 2 * sigma*gamma;
	for (int i = 0; i <= N; ++i){ x[i] = i*h; } //аргументы
	for (int k = 0; k <= n0; ++k){ t[k] = k*tau; }
	for (int i = 0; i <= N; ++i)
		y[i][0] = y1[i] = u0(x[i]); // начальн.услов.
	for (int k = 0; k <= n0; ++k){
		y[0][k] = ux0(t[k]);
		y[N][k] = uxl(t[k]); // краев. услов.для правой части
	}
	for (int k = 0; k<n0; ++k){ // цикл по временным слоям
		for (int i = 1; i <= N - 1; ++i){ // правая часть для прогонки
			F1[i][k] = (1 - sigma)*gamma*y[i + 1][k] + (1 - 2 * gamma*(1 - sigma))*y[i][k] + (1 - sigma)*gamma*y[i - 1][k] + tau*f(x[i], t[k] + 0.5*tau);//1 ?,f(x[i],t[k]+0.5*tau)
			F[i] = F1[i][k];
		}
		g0 = ux0(t[k + 1]);
		gN = uxl(t[k + 1]); // краевые усл. для прогонки
		progonka(g0, gN, A, B, C, F, y1);
		for (int i = 1; i<N; ++i)
			y[i][k + 1] = y1[i];
	} //конец врем.цикла
	cout << " pribligennoe reshenie" << endl;
	for (int k = 0; k <= n0; ++k, cout << endl)
	for (int i = 0; i <= N; ++i)
		cout << fixed << setprecision(5) << y[i][k] << " ";
	cout << endl;
	cout << "tochnoe reshenie" << endl;
	for (int k = 0; k <= n0; ++k, cout << endl)
		for (int i = 0; i <= N; ++i)
			cout << fixed << setprecision(5) << fun(x[i], t[k]) << " ";
	cout << endl;
	for (int k = 0; k<n0; ++k){  //  ??
		for (int i = 0; i <= N; ++i){ // погрешность реш.
			nor[i][k] = y[i][k] - fun(x[i], t[k]);
		}
	}
	cout << "Norma pogreshn = " << norma(nor, N, n0) << endl;   //  ??
	return 0;
} // конец main ()

// Задание функций
double fun(double x, double t){
	return x*x*t*t + n*x*t + x + n;
} // функция точ.решен.

double f(double x, double t){
	return x*(n + 2 * t*x) - 2 * t*t; // функция неоднородности уравнен.
}

double u0(double x){
	return x + n;
} // функция начальн.условия

double ux0(double t){
	return n;
} // функция краевого услов. в x=0

double uxl(double t){
	return t*t + n*t + 1 + n;
} // функция краевого услов. в x=l

void progonka(double g0, double gN, double A, double B, double C, double *F, double *y){

	double *alf = new double[N], *bet = new double[N];
	alf[1] = 0, bet[1] = g0;
	for (int i = 1; i <= N - 1; ++i) // прямой ход
	{
		alf[i + 1] = 1. / (C - A*alf[i])*B;
		bet[i + 1] = 1. / (C - A*alf[i])*(F[i] + A*bet[i]);
	}
	// обратный ход  
	y[N] = gN;
	for (int j = N - 1; j >= 0; --j)
	{
		y[j] = alf[j + 1] * y[j + 1] + bet[j + 1];
	}
}

double norma(double **nor, int N, int n0) // надо nor[N][n0] //функция нормы
{
	double m = 0;
	double *sum = new double[n0];
	for (int k = 0; k<n0; ++k){
		sum[k] = 0;
		for (int i = 0; i <= N; ++i){
			sum[k] += pow(abs(nor[i][k]), 2);
			sum[k] = sqrt(sum[k]);
		}
		m = max(m, abs(sum[k]));
	}
	return m;
}
