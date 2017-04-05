//Конечно-разностный метод 1 рода
#include <cmath>
#include <iostream>
#include<iomanip>
using namespace std;
const int N = 10 ,n = N+1; // vseh tochek n, promegutkov dliny h vsego N shtuk.

void prog(double p[],double q[],double r[],double y[],double m0,double m1,double h){
	double A[N-1],B[N-1],C[N-1],F[N-1];
	for(int j=1;j<=N-1;j++)
	{
		A[j] = 0.5;
		B[j] = 0.5;
		C[j] = 1+h*exp(4)/2;
		F[j] = h*h*r[j]/2;
	}
	double al[N],bt[N];

	al[1] = 0; bt[1] = m0;

	for(int j=1;j<=N-1;j++)
	{//?????? ???
		al[j + 1] = B[j] / (C[j] - A[j] * al[j]);
		bt[j + 1] = (A[j] * bt[j] - F[j]) / (C[j] - A[j] * al[j]);
	}

	y[N] = m1;

	for(int i=N-1;i>0;i--)
	{//????????
		y[i] = al[i + 1] * y[i + 1] + bt[i + 1];
	}
}

int main()
{
	double p[N-1], q[N-1], r[N-1], h, x[n], y[n];
	double m0 = 1, m1 = exp(4) + 1, a = 0, b = 1;
	h = 1./N;
	for(int j=1;j<N;j++)
	{
		x[j] = a + j*h;
		p[j] = 0;
		q[j] = exp(4);
		r[j] = exp(4)*x[j];
		cout<<"x["<<j<<"]= "<<x[j]<<endl;
	}
	prog(p, q, r, y, m0, m1, h);
	x[0] = a; x[N] = b; y[0] = m0; y[N] = m1;
	cout<<endl;
	cout << setw(10) << "x[i]" << setw(10) << "y[i]" << setw(15) << "h^2" << endl;
	for (int i = 0; i <= N; i++)
		cout << setprecision(5) << setw(10) << x[i] << setw(10) << y[i]	<< setw(15) << pow(1. / N, 2) << endl;
}
