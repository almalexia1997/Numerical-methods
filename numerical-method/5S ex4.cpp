//Краевая задача.метод дихотомии с пристрелкой.
#include <cmath>
#include <iostream>
#include<iomanip>

using namespace std;

const double eps = 0.001;  //??   взял поточнее...
const int m = 3, p = 2; //m=4,p=1;  ??       число ур. и поряд.метода

//================================================

double norma(int m, double y1[], double y2[])
{
	double sum = 0;
	for (int i = 0; i<m; i++)
		sum += pow(y1[i] - y2[i], 2);
	return sqrt(sum);
}

void fun(double u[m], double x, double f[m]) {
	f[0] = u[1]; // функция правой части ОДУ из краевой задачи
	f[1] = u[2];
	f[2] = -u[2] / x - 0.5*u[0] * u[2] / x;
}

void FormRK(double y0[m], double x, double h, double y[m])
{
	double f[m];
	fun(y0, x, f);
	for (int i = 0; i<m; ++i)// формулы мет. эйлера на шаге h
		y[i] = y0[i] + h*f[i];
}

void FormRK2(double y0[], double x, double h, double y[]){
	double f[m], k1[m], k2[m], r[m];
	fun(y0, x, f);
	for (int i = 0; i<m; ++i){
		k1[i] = h*f[i];
		r[i] = y0[i] + k1[i];
	}
	fun(r, x + h, f);
	for (int i = 0; i<m; ++i){
		k2[i] = h*f[i];
		y[i] = y0[i] + 0.5*(k1[i] + k2[i]);
	}
}

void shag(double y[m], double x, double &h, double eps, double &el)//vybor shaga ??
{// ф-я алгор. автомат.выбора шага h𝒌
	double yh[m], yhh[m];
	for (;;)
	{
		FormRK2(y, x, h, yh);
		FormRK2(y, x, h / 2, yhh);
		FormRK2(yhh, x + h / 2, h / 2, yhh);   //  ??   h/x
		el = norma(m, yhh, yh) / (pow(2., p) - 1);
		if (el >= eps){ h /= 2; }
		else if (el<eps / pow(2, (p + 1))) { h *= 2; break; }
		else break;
	}
}
//=================================================================///=====================

void MetRK(double y[m], double x, double xN, double h, double eps, double q)
{
	double el; // погрешность решения на шаге
	shag(y, 0.1, h, eps, el);
	if (q == 0){
		cout << setw(10) << "x" << setw(10) << "y[0]" << setw(10) //заголовки таблицы
			<< "y[1]" << setw(10) << "y[2]" << setw(10) << "h" << setw(10) << "el" << endl;
		cout << fixed << setw(10) << setprecision(4) << x << setw(10) << y[0] << setw(10) << y[1] <<
			setw(10) << y[2] << setw(10) << h << setw(10) << el << endl;
	}
	for (;;)
	{
		shag(y, x, h, eps, el);//cout<<fixed<<setw(10)<<setprecision(4)<<h<<endl;
		if ((xN - x) <= h) { h = xN - x; } //уточн. длины перемен.шага перед концом отрезка аргум
		FormRK2(y, x, h, y);
		x += h;
		if (q == 0){
			cout << fixed << setw(10) << setprecision(4) << x << setw(10) << y[0] << setw(10) <<
				y[1] << setw(10) << y[2] << setw(10) << h << setw(10) << el << endl;
		}
		if (x == xN) break;
	}
	if (q == 0){
		cout << fixed << "\n \t eps=" << eps << endl;
		cout << fixed << " \t h=" << h << endl;
	}
}


//======================дихотомия(метод пристрелки)==================
double psi(double s){
	double ps, u[m], x0 = 0.1, xN = 1., h;
	int q = 1;
	u[0] = 0; u[1] = 0, u[2] = s;
	h = pow(eps, 1. / p);
	MetRK(u, x0, xN, h, eps, q);
	ps = u[1] - 0.5;
	return ps;
}

//===========дихотомия(половинного деления)==========================
double function(double x){
	return sin(2 * x) / (x*x);
}
double dichotomy(double a, double b, double eps)
{
	double mid = (a + b) / 2.0;
	double s = 0;
	while ((b - a) / 2.0 > eps)
	{
		if (function(mid) == 0){
			return mid;
		}
		else if (function(a)*function(mid) < 0){
			b = mid;
		}
		else{
			a = mid;
		}
		mid = (a + b) / 2.0;
		s++;
	}
	cout << "s = " << s << endl;
	return mid;
}
//================главная функция====================================
int main(){
	double a = -4;
	double b = 4, s;
	cout << "psi(a) = " << psi(a) << "\npsi(b) = " << psi(b) << endl;
	for (;;){
		s = (b + a) / 2;
		if (psi(s)*psi(b)<0)a = s;  //  ??  было if(psi(a)*psi(b)<0)a=s;
		else b = s;
		if (fabs(psi(s))<eps) break;   //  ??  было if(fabs(psi(s)<eps)) 
	}
	cout << "s= " << s << "\n psi(s) = " << psi(s) << endl; //Вывод найд. s  и  psi(s)
	double  u[m], x0 = 0.1, xN = 1., h;
	int q = 0;
	u[0] = 0; u[1] = 0, u[2] = s;
	h = pow(eps, 1. / p);
	MetRK(u, x0, xN, h, eps, q);    // Вывод реш. зад.Коши совпад. с реш.краевой зад.
	return 0;
}
