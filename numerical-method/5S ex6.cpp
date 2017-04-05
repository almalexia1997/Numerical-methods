//Конечно-разностный метод 3 рода
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
const int N = 10 ,n = N+1; // vseh tochek n, promegutkov dliny h vsego N shtuk.

void prog(double p[],double q[],double r[],double y[],double k0,double k1, double v0, double v1, double mu0, double mu1, double h){
	double A[N-1],B[N-1],C[N-1],F[N-1], a0, b0, g0, a1,b1,g1;
	for(int j=1;j<=N-1;j++)
	{
		A[j] = 0.5;
		B[j] = 0.5;
		C[j] = 1+h*exp(4)/2;
		F[j] = h*h*r[j]/2;
	}
	double al[N],bt[N];

	b0 = v0*(1./h + p[0]/2.);
	a0 = k0+b0+v0*q[0]*h/2.;
	g0 = mu0 - v0*r[0]*h/2.;

	b1 = v1*(1/h - p[N]/2);
	a1 = k1 + b1 + v1 *q[N]*h/2;
	g1 = mu1 - v1*r[N]*h/2;

	al[1] = b0/a0; bt[1] = g0/a0;

	for(int j=1;j<=N-1;j++)
	{//?????? ???
		al[j + 1] = B[j] / (C[j] - A[j] * al[j]);
		bt[j + 1] = (A[j] * bt[j] - F[j]) / (C[j] - A[j] * al[j]);
	}

	y[N] = (g1 + b1*bt[N])/(a1-b1*al[N]);

	for(int i=N-1;i>0;i--)
	{//????????
		y[i] = al[i + 1] * y[i + 1] + bt[i + 1];
	}
}

int main()
{
	double p[n], q[n], r[n], h, x[n], y[n];
	double k0 = 3, k1 = 0, v0 = 2.8, v1 = 1, mu0 = 1.4, mu1 = sqrt(2.4), a = 0, b = 1;
	h = 1./N;
	for(int j=0;j<=N;j++)
	{
		x[j] = a + j*h;
		p[j] = 0.5/(x[j]+1.4);
		q[j] = 0;
		r[j] = 1/sqrt(x[j]+1.4);
		cout<<"x["<<j<<"]= "<<x[j]<<endl;
	}
	prog(p, q, r, y, k0, k1, v0, v1, mu0, mu1, h);

	x[0] = a; x[N] = b;

	cout<<endl;
	cout << setw(10) << "x[i]" << setw(10) << "y[i]" << setw(15) << "h^2" << endl;
	for (int i = 0; i <= N; i++)
		cout << setprecision(5) << setw(10) << x[i] << setw(10) << y[i]	<< setw(15) << pow(1. / N, 2) << endl;
}
