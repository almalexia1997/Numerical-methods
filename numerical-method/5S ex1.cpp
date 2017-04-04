//Зад.№15: мет.Рунге-Кутты 1 порядка
#include <cmath>
#include <iostream>
#include<iomanip>

using namespace std;

const int m = 4, p = 1; // число ур. и поряд.метода

double ut(double x) //fun. tochnogo reshenija (esli danо)
{
	double u = (exp(5.*x - 5.)*sin(x) - exp(5. - 5.*x)*cos(x)) / 148.413;   //  ??
	return u;
}

void fun(double u[m], double x, double f[m]) {
	f[0] = u[1]; // функция правой части ОДУ
	f[1] = u[2];
	f[2] = u[3];
	f[3] = -5.*u[3] - u[2] - 120.*u[1] - 650.*u[0] + exp(5 * x - 5)*(11.5*sin(x) + 4.9*cos(x));
}

void FormRK(double y0[m], double x, double h, double y[m])
{
	double f[m];
	fun(y0, x, f);
	for (int i = 0; i<m; i++)// формулы мет. эйлера на шаге h
		y[i] = y[i] + h*f[i];
}

void MetRK(double y[m], double x, double xN, double h, double eps)
{
	double el; // погрешность решения на шаге
	cout << setw(10) << "x" << setw(10) << "y[0]" << setw(10) //заголовки таблицы
		<< "y[1]" << setw(10) << "y[2]" << setw(10) << "y[3]" << setw(10) << "h" << endl;
	cout << fixed << setw(10) << setprecision(4) << x << setw(10) << y[0] << setw(10) << y[1] <<
		setw(10) << y[2] << setw(10) << y[3] << setw(10) << h << endl;
	for (;;)   //  ??
	{
		FormRK(y, x, h, y);
		x += h;
		if (x >= xN) break;
		el = fabs(y[0] - ut(x)); //погрещность y[0] решения на шаге
		cout << fixed << setw(10) << setprecision(4) << x << setw(10) << y[0] << setw(10) << y[1] <<
		setw(10) << y[2] << setw(10) << y[3] << setw(10) << h << endl;
	}
	cout << fixed << "\n \t eps=" << eps << endl;
	cout << fixed << " \t h=" << h << endl;
}

int main() {
	int N = 11.; //количество шагов аргумента
	double x0 = 0, xN = 1, h = 1. / (N - 1.); // начальные значения и шаг
	cout << "h=" << h << endl;
	double eps = h; //погрешность
	double y0[m] = { -1., 1., -2., 6. };   //??  {-1,1,-2,0}; //значения начальных условий
	MetRK(y0, x0, xN, h, eps); // получение решения
	return 0;
}

