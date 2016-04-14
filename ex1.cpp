#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

const double eps = 1e-12;

class Matrix {
private:
	int size;//переменная для размера матрицы
	double **A; //здесь храниться матрица
public:
	Matrix(int size) : size(size) //конструктор матрицы
	{
		//создаем матрицу
		A = new double *[size];
		for (int i = 0; i < size; ++i)
		{
			A[i] = new double[size];
			for (int j = 0; j < size; ++j)
				A[i][j] = 0;
		}
	}
	Matrix MultMatrix(Matrix B)
	{
		Matrix result(size); //создали матрицу result
		for (int k = 0; k<size; k++) //перемещаемся по строкам матрицы result
		for (int i = 0; i<size; i++) //перемещаемся по столбцам матрицы result
		for (int j = 0; j<size; j++) //индекс который меняется при умножении
			result.A[k][i] = result.A[k][i] + A[k][j] * B.A[j][i];
		return result;
	} //умножение матриц
	Matrix SumMatrix(Matrix B) //сложение матриц
	{
		Matrix result(size);
		for (int i = 0; i<size; i++)
		for (int j = 0; j<size; j++)
			result.A[i][j] = A[i][j] + B.A[i][j];
		return result;
	}
	Matrix SubMatrix(Matrix B)
	{
		Matrix result(size);
		for (int i = 0; i<size; i++)
		for (int j = 0; j<size; j++)
			result.A[i][j] = A[i][j] - B.A[i][j];
		return result;
	} //вычитание матриц
	void DivInNumber(int k)
	{
		for (int i = 0; i<size; i++)
		for (int j = 0; j<size; j++)
			A[i][j] = ceil(A[i][j] / (k*k));
	}

	void MulInNumber(int k)
	{
		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				A[i][j] = A[i][j] * k;
	}

	Matrix Trans(int size)
	{
		Matrix B(size);
		for (int i = 0; i<size; i++)
		for (int j = 0; j < size; j++)
		{
			B[i][j] = A[j][i];
		}
		return B;
	} //транспонированная матрица
	void showData()
	{
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; ++j)
				cout << A[i][j] << " ";
			cout << endl;
		}
	} //вывод данных массива на экран
	double ReturnElementMatrix(int i, int j)
	{
		return A[i][j];
	}
	void Random()
	{
		srand(time(NULL)); // Инициализируем генератор случайных чисел.
		// А дальше работа как с обычным массивом.
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				(*this).A[i][j] = rand() % 10; // Каждый элемент случайному числу от 0 до 9
			}
		}
	}
	void Kroneker()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == j)
					A[i][j] = 1;
				else
					A[i][j] = 0;
			}
		}
	}
	double *operator [](int i) //взять элемент матрицы
	{
		return A[i];
	}
	Matrix(const Matrix &B) //перегрузка оператора присваивания
	{
		size = B.size;
		A = new double *[size];
		for (int i = 0; i < size; ++i)
		{
			A[i] = new double[size];
			for (int j = 0; j < size; ++j)
				A[i][j] = B.A[i][j];
		}
	}
};


class Vector
{
private:
	int size;
	double *V;
public:
	Vector(int size) : size(size)
	{
		size = size;
		V = new double[size];
		for (int i = 0; i < size; i++)
		{
			V[i] = 0;
		}
	}
	Vector MultMatrixInVector(Matrix A)
	{
		Vector result(size); //создали vector result
		for (int i = 0; i<size; i++) //перемещаемся по столбцам матрицы result
		for (int j = 0; j<size; j++) //индекс который меняется при умножении
			result.V[i] = result.V[i] + A.ReturnElementMatrix(i, j) * V[j];
		return result;
	} //умножение матрицы на вектор
	double &operator[](int j) //перегрузка []
	{
		return V[j];
	}
	Vector(const Vector &B) : size(B.size) {
		V = new double[size];
		for (int i = 0; i < size; i++) V[i] = B.V[i];
	}
	void ShowData()
	{
		for (int i = 0; i<size; ++i)
			cout << V[i] << "\n";
	}
	void Random()
	{
		srand(time(NULL)); // Инициализируем генератор случайных чисел.
		// А дальше работа как с обычным массивом.
		for (int i = 0; i < size; i++)
			(*this).V[i] = rand() % 10; // Каждый элемент случайному числу от 0 до 9
	}
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


/*Matrix Forward(Matrix A, int size)
{
Matrix S(size);
cout << "\nForward loading..." << endl;
double sum1 = 0;
double sum2 = 0;
S[0][0] = sqrt(abs(A[0][0]));//+
for (int j = 1; j<size; ++j)
S[0][j] = A[0][j] / S[0][0]; //+
for (int i = 1; i<size; ++i)
{
for (int j = 0; j<size; ++j)
{
if (i == j)
{
sum1 = 0;
for (int k = 0; k < i; ++k)
sum1 += S[k][i] * S[k][i];
S[i][i] = sqrt(abs(A[i][i] - sum1));
}
else if (i<j)
{
sum2 = 0;
for (int k = 0; k<i; ++k)
sum2 += S[k][i] * S[k][j];
S[i][j] = (A[i][j] - sum2) / (S[i][i]);
}
else
S[i][j] = 0;
sum1 = 0;
sum2 = 0;
}
}
return S;
}


Vector Reverse(Vector b, Matrix S, int size)
{
Vector x(size);
cout << "\nReverse loading..." << endl;
double sum1 = 0;
double sum2 = 0;
Vector y(size);
y[0] = b[0] / (S[0][0]);
for (int i = 1; i<size; ++i)
{
sum1 = 0;
for (int k = 0; k<i; ++k)
sum1 = sum1 + S[k][i] * y[k];
y[i] = (b[i] - sum1) / (S[i][i]);
}
x[size - 1] = y[size - 1] / S[size - 1][size - 1];
for (int i = size - 2; i >= 0; --i)
{
sum2 = 0;
for (int k = i + 1; k<size; ++k)
sum2 = sum2 + S[i][k] * x[k];
x[i] = (y[i] - sum2) / S[i][i];
}
return x;
}
*/

Matrix Diagonal(Matrix A, int size)
{
	Matrix D(size);
	Matrix S(size);
	cout << "\nDiagonal loading..." << endl;
	double sum1 = 0;
	double sum2 = 0;
	(A[0][0]>0) ? D[0][0] = 1 : D[0][0] = -1; //1
	S[0][0] = sqrt(abs(A[0][0]));
	for (int j = 1; j < size; ++j)
		S[0][j] = A[0][j] / (S[0][0] * D[0][0]);
	for (int i = 1; i<size; ++i)
	{
		for (int j = 0; j<size; ++j)
		{
			if (i == j)
			{
				sum1 = 0;
				for (int k = 0; k<i; ++k)
				{
					if (k == 0) sum1 = 0;
					sum1 += D[k][k] * abs(S[k][i]) * abs(S[k][i]);
				}
				cout << "\nD[" << i + 1 << "][" << i + 1 << "]***sum1***  " << sum1 << endl;
				((A[i][i] - sum1)>0) ? D[i][i] = 1 : D[i][i] = -1; //2
				cout << "\nA[" << i + 1 << "][" << i + 1 << "]-sum1 = " << A[i][i] << " - " << sum1 << " = " << A[i][i]-sum1 << endl;
				S[i][i] = sqrt(abs(A[i][i] - sum1));
			}
			else if (i+1<=j)
			{
				sum2 = 0;
				for (int k = 0; k<i; ++k)
					sum2 += D[k][k] * S[k][i] * S[k][j];
				S[i][j] = (A[i][j] - sum2) / (S[i][i] * D[i][i]);
			}
			else
				S[i][j] = 0;
			sum1 = 0;
			sum2 = 0;
		}
	}
	return D;
}

Matrix Forward(Matrix A, Matrix D, int size)
{
	Matrix S(size);
	cout << "\nForward loading..." << endl;
	double sum1 = 0;
	double sum2 = 0;
	S[0][0] = sqrt(abs(A[0][0]));//+
	for (int j = 1; j<size; ++j)
		S[0][j] = A[0][j] / (S[0][0] * D[0][0]); //+
	for (int i = 1; i<size; ++i)
	{
		for (int j = 0; j<size; ++j)
		{
			if (i == j)
			{
				sum1 = 0;
				for (int k = 0; k < i; ++k)
					sum1 += D[k][k] * abs(S[k][i]) * abs(S[k][i]);
				S[i][i] = sqrt(abs(A[i][i] - sum1));
			}
			else if (i+1<=j)
			{
				sum2 = 0;
				for (int k = 0; k<i; ++k)
					sum2 += D[k][k] * S[k][i] * S[k][j];
				S[i][j] = (A[i][j] - sum2) / (S[i][i] * D[i][i]);
			}
			else
				S[i][j] = 0;
			sum1 = 0;
			sum2 = 0;
		}
	}
	return S;
}



Vector Reverse(Vector b, Matrix S, Matrix D, int size)
{
	Vector x(size);
	cout << "\nReverse loading..." << endl;
	double sum1 = 0;
	double sum2 = 0;
	Vector y(size);
	y[0] = b[0] / (S[0][0] * D[0][0]);
	for (int i = 1; i<size; ++i)
	{
		sum1 = 0;
		for (int k = 0; k<i; ++k)
			sum1 += D[k][k] * S[k][i] * y[k];
		y[i] = (b[i] - sum1) / (S[i][i] * D[i][i]);
	}
	x[size - 1] = y[size - 1] / S[size - 1][size - 1];
	for (int i = size - 2; i >= 0; --i)
	{
		sum2 = 0;
		for (int k = i + 1; k<size; ++k)
			sum2 += S[i][k] * x[k];
		x[i] = (y[i] - sum2) / S[i][i];
	}
	return x;
}

bool Check(Matrix A, Vector x, Vector b, int size) {
	Vector Result(size);
	Result = x.MultMatrixInVector(A);
	cout << "\n++++++++++++++++++++" << endl;
	cout << "\nResult:" << endl;
	Result.ShowData();
	cout << "\nVector b" << endl;
	b.ShowData();
	int flag[1] = { 0 };
	for (int i = 0; i<size; ++i)
	{
		if (abs(Result[i] - b[i])>eps)
		{
			flag[0] = 1; cout << "Pogreshnost***" << " " << abs(Result[i] - b[i]) << endl;
		}
		else
			cout << "Pogreshnost***" << " " << abs(Result[i] - b[i]) << endl;
	}
	if (flag[0] != 0)
		return false;
	else
		return true;
}
int main()
{
	cout << "eps = " << eps << "\n" << endl;
	int size;
	int gamma;
	cout << "size="; cin >> size;
	cout << "gamma="; cin >> gamma;


	Matrix A(size); //matrix coefficients
	A.Random(); //random elements
	//A.showData();
	Matrix At(size);
	At = A.Trans(size); //transpose matrix
	//At.showData();

	//create a symmetric matrix
	Matrix A3(size);
	A3 = At.MultMatrix(A);
	//A3.DivInNumber(size);
	Matrix E(size);
	E.Kroneker();
	E.MulInNumber(gamma);
	cout << "\ngamma*E" << endl;
	E.showData();
	Matrix A2(size);
	A2 = A3.SumMatrix(E);


	//We create a vector of free terms
	Vector b(size);
	b.Random();

	//Diagonal create
	Matrix D(size);
	D = Diagonal(A2, size);
	cout << "\nD" << endl;
	D.showData();


	//First part
	Matrix S(size); //matrix decomposition
	Matrix St(size);//transposed matrix decomposition
	//D.Kroneker();
	S = Forward(A2, D, size); //create matrix decomposition
	//S=Forward(A2,size);
	St = S.Trans(size); //create transposed matrix decomposition
	cout << "\nS" << endl;
	S.showData();
	cout << "\nSt" << endl;
	St.showData();


	Matrix T(size);
	T = St.MultMatrix(D);
	Matrix R(size);
	R = T.MultMatrix(S);
	cout << "\nMatrix A:" << endl;
	A2.showData(); //symmetric matrix
	cout << "\nSt*D*S" << endl;
	R.showData();



	//Second part
	Vector x(size); //unknown vector
	x = Reverse(b, S, D, size);
	//x=Reverse(b, S, size);
	cout << "\nVector x" << endl;
	x.ShowData();
	if (Check(A2, x, b, size))
		cout << "Vivod: OK" << endl;
	else
		cout << "Vivod: NO" << endl;
	return 0;
};
