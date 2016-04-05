#include <ctime> // в ней функция time
#include <cstdlib>

using namespace std;

class Matrix //класс матрицы
{
private:
	int size;//переменная для размера матрицы
	double **A; //здесь храниться матрица
public:
	//********************************************************************************************

	Matrix(int size); //конструктор матрицы
	Matrix MultMatrix(Matrix B); //умножение матриц
	Matrix SumMatrix(Matrix B); //сложение матриц
	Matrix SubMatrix(Matrix B); //вычитание матриц
	void DivInNumber(int k);
	void Trans(int size); //транспонированная матрица
	void showData();         //вывод данных массива на экран
	//~Matrix(); //деструктор матрицы
	double ReturnElementMatrix(int i, int j);
	void Random();
	void Kroneker();

	//********************************************************************************************

	double *operator [](int i) //взять элемент матрицы
	{
		return A[i];
	}
	Matrix& operator=(Matrix &B) //перегрузка оператора присваивания
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
		return *this;
	}

	/*Matrix operator= (const Matrix &obj) {
		//копируем obj
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				A[i][j] = obj.A[i][j];
			}
		}
		return *this;
	}*/
};

//********************************************************************************************

Matrix::Matrix(int size) : size(size)
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

Matrix Matrix::MultMatrix(Matrix B) //умножение матриц
{
	Matrix result(size); //создали матрицу result
	for (int k = 0; k<size; k++) //перемещаемся по строкам матрицы result
	for (int i = 0; i<size; i++) //перемещаемся по столбцам матрицы result
	for (int j = 0; j<size; j++) //индекс который меняется при умножении
		result.A[k][i] = result.A[k][i] + A[k][j] * B.A[j][i];
	return result;
}

Matrix Matrix::SumMatrix(Matrix B) //сложение матриц
{
	Matrix result(size);
	for (int i = 0; i<size; i++)
	for (int j = 0; j<size; j++)
		result.A[i][j] = A[i][j] + B.A[i][j];
	return result;
}
Matrix Matrix::SubMatrix(Matrix B) //вычитание матриц
{
	Matrix result(size);
	for (int i = 0; i<size; i++)
	for (int j = 0; j<size; j++)
		result.A[i][j] = A[i][j] - B.A[i][j];
	return result;
}

void Matrix::DivInNumber(int k)
{
	for (int i = 0; i<size; i++)
		for (int j = 0; j<size; j++)
			A[i][j] = ceil(A[i][j]/(k*k));
}
void Matrix::Trans(int size) //транспонированная матрица
{
	Matrix B(size);
	B = (*this);
	for (int i = 0; i<size; i++)
		for (int j = 0; j < size; j++)
			{
				A[i][j] = B[j][i];
			}			
}

void Matrix::showData()         //вывод данных массива на экран
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; ++j)
			cout << A[i][j] << "  ";
		cout << endl;
	}
}
/*Matrix::~Matrix()
{
	for (int i = 0; i<size; ++i)
		delete[] A[i];
	delete[] A;
};*/

double Matrix::ReturnElementMatrix(int i, int j)
{
	return A[i][j];
}

void Matrix::Random()
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

void Matrix::Kroneker(){
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
