#include <iostream>
#include <cmath>
#include "Matrix.cpp"
#include "Vector.cpp"


using namespace std;

const double eps = 1e-12;

void Forward(Matrix A, Matrix S, int size)
{
	cout << "Forward loading..." << endl;
	double sum1 = 0;
	double sum2 = 0;
	S[0][0] = sqrt(abs(A[0][0]));
	for (int j = 1; j<size; ++j)
		S[0][j] = A[0][j] / S[0][0];
	for (int i = 1; i<size; ++i)
	{
		for (int j = 0; j<size; ++j)
		{

			if (i == j)
			{
				for (int k = 0; k<i; ++k)
					sum1 = sum1 + S[k][i] * S[k][i];
				S[i][i] = sqrt(abs(A[i][i] - sum1));
			}
			else if (i<j)
			{
				for (int k = 0; k<i; ++k)
					sum2 = sum2 + S[k][i] * S[k][j];
				S[i][j] = (A[i][j] - sum2) / (S[i][i]);
			}
			else
				S[i][j] = 0;
		}
	}
}

void Reverse(Vector b, Vector x, Matrix S, int size)
{
	cout << "Reverse loading..." << endl;
	double sum1 = 0;
	double sum2 = 0;
	Vector y(size);
	y[0] = b[0] / (S[0][0]);
	for (int i = 1; i<size; ++i)
	{
		for (int k = 0; k<i; ++k)
			sum1 = sum1 + S[k][i] * y[k];
		y[i] = (b[i] - sum1) / (S[i][i]);
	}
	x[size - 1] = y[size - 1] / S[size - 1][size - 1];
	for (int i = size - 2; i >= 0; --i)
	{
		for (int k = i+1; k<size; ++k)
			sum2 = sum2 + S[i][k] * x[k];
		x[i] = (y[i] - sum2) / S[i][i];
	}
}

bool Check(Matrix A, Vector x, Vector b, int size) {
	int k = 0;
	Vector Result(size);
	Result = x.MultMatrixInVector(A);
	cout << "\nResult:" << endl;
	Result.ShowData();
	for (int i = 0; i<size; ++i)
	if (abs(Result[i] - b[i])>eps)
	{
		k++; cout << "Proverka***" << k <<"   "<< abs(Result[i] - b[i]) << endl;
	}
	else 
		cout << "Proverka***" << k << "   " << abs(Result[i] - b[i]) << endl;
	if (k != 0)
		return false;
	else
		return true;
}

int main()
{
	cout << eps << "\n" << endl;
	int size;
	cout << "size="; cin >> size;
	Matrix A(size); //matrix coefficients
	A.Random(); //random elements
	//A.showData();
	Matrix At(size);
	At = A;
	At.Trans(size); //transpose matrix
	//At.showData();

	//create a symmetric matrix
	Matrix A2(size);
	A2 = A.MultMatrix(At);
	A2.DivInNumber(size);
	cout << "\nMatrix A:" << endl;
	A2.showData();

	//We create a vector of free terms
	Vector b(size); 
	b.Random();
	cout << "\nVector b" << endl;
	b.ShowData();

	//First part
	Matrix S(size); //matrix decomposition
	Matrix St(size);//transposed matrix decomposition
	Forward(A2, S, size); //create matrix decomposition
	St = S;
	St.Trans(size); //create transposed matrix decomposition
	S.showData();
	St.showData();

	//Second part
	Vector x(size); //unknown vector
	Reverse(b, x, S, size);
	cout << "\nVector x" << endl;
	x.ShowData();

	if (Check(A2, x, b, size))
		cout << "OK" << endl;
	else
		cout << ":(" << endl;
	return 0;
};
