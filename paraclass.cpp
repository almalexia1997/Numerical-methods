#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;


class Matrix {

private:
	int size;//переменная для размера матрицы
	double **A; //здесь храниться матрица
public:

	Matrix(int size): size(size) //конструктор матрицы
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
				A[i][j] = ceil(A[i][j]/(k*k));
	}

	Matrix Trans(int size)
	{
		Matrix B(size);
		for (int i = 0; i<size; i++)
			for (int j = 0; j < size; j++)
			{
				B[j][i] = A[i][j];
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
	//~Matrix(); //деструктор матрицы

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

	Matrix (const Matrix &B) //перегрузка оператора присваивания
	{
		for (int i = 0; i<size; ++i)
		delete[] A[i];
		delete[] A;
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
	} //умножение матрицы на векто
	double &operator[](int j) //перегрузка []
	{
		return V[j];
	}
	Vector (const Vector &B) {
		delete[] V;
		size = B.size;
		V = new double [size];
		for (int i = 0; i < size; ++i)
		{
			V[i] = B.V[i];
		}
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
