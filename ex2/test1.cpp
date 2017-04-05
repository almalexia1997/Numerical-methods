#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

const double eps = 1.0e-3;

class Matrix {
private:
	int size;//переменная для размера матрицы
	double **A; //здесь храниться матрица
	//Следующие поля для матрицы поворота
	int k = 0; 
	int l = 0;
	bool transpan = false;
	bool turn = false;
public:
	//конструктор матрицы
	Matrix(int size) : size(size)
	{
		A = new double *[size];
		for (int i = 0; i < size; ++i)
		{
			A[i] = new double[size];
			for (int j = 0; j < size; ++j)
				A[i][j] = 0;
		}
	}
	//конструктор копирования
	Matrix(const Matrix &B)
	{
		size = B.size;
		A = new double *[size];
		for (int i = 0; i < size; ++i)
		{
			A[i] = new double[size];
			for (int j = 0; j < size; ++j)
				A[i][j] = B.A[i][j];
		}
		transpan = B.transpan; //копируем отметку транспанированности
		turn = B.turn; //копируем отметку поворота
		k = B.k; l = B.l; //копируем индексы
	}

	void CreateMatrix(){
		for (int i = 0; i<size; i++) //перемещаемся по столбцам матрицы result
			for (int j = 0; j < size; j++) //индекс который меняется при умножении
			{
				cout << "A[" << i + 1 << "][" << j + 1 << "]=";
				cin >> A[i][j];
			}
	}

	//умножение матриц
	Matrix MultMatrix(Matrix B)
	{
		Matrix result(size); //создали матрицу result
		for (int k = 0; k<size; k++) //перемещаемся по строкам матрицы result
			for (int i = 0; i<size; i++) //перемещаемся по столбцам матрицы result
				for (int j = 0; j<size; j++) //индекс который меняется при умножении
					result.A[k][i] = result.A[k][i] + A[k][j] * B.A[j][i];
		return result;
	}
	//сложение матриц
	Matrix SumMatrix(Matrix B)
	{
		Matrix result(size);
		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				result.A[i][j] = A[i][j] + B.A[i][j];
		return result;
	}
	//вычитание матриц
	Matrix SubMatrix(Matrix B)
	{
		Matrix result(size);
		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				result.A[i][j] = A[i][j] - B.A[i][j];
		return result;
	}
	//целочисленное деление матрицы на число
	void DivInNumber(int k)
	{
		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				A[i][j] = ceil(A[i][j] / (k*k));
	}
	//умножение матрицы на число
	void MulInNumber(int k)
	{
		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				A[i][j] = A[i][j] * k;
	}	
	//вывод данных массива на экран
	void showData()
	{
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; ++j)
				cout << A[i][j] << " ";
			cout << endl;
		}
	}
	//возвратить элемент матрицы
	double ReturnElementMatrix(int i, int j)
	{
		return A[i][j];
	}
	//создать рандомную матрицу
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
	//создать единичную матрицу
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
	//взять элемент матрицы
	double *operator [](int i)
	{
		return A[i];
	}
	//Создать симметричную матрицу
	Matrix Symmetric(int gamma)
	{
		Matrix A(size);
		Matrix At(size);
		Matrix R(size);
		Matrix E(size);
		(*this).Random();
		At = (*this).Trans(size);
		R = At.MultMatrix((*this));
		E.Kroneker();
		E.MulInNumber(gamma);
		A = R.SumMatrix(E);
		return A;
	}
	//транспонированние матрицы
	Matrix Trans(int size)
	{
		Matrix B(size);
		for (int i = 0; i<size; i++)
			for (int j = 0; j < size; j++)
				B[i][j] = A[j][i];
		B.transpan = true; //помечаем как транспанированную
		B.turn = turn; //наследуем отметку поворота
		B.k = k; B.l = l; //то же самое и с индексами
		return B;
	}
	//перегружаю оператор умножения матриц
	Matrix operator *(Matrix B)
	{
		Matrix result(size); //создали матрицу result
		for (int f = 0; f < size; f++) //перемещаемся по строкам матрицы result
		{
			for (int i = 0; i < size; i++) //перемещаемся по столбцам матрицы result
				for (int j = 0; j < size; j++)//индекс который меняется при умножении
				{
					if (B.transpan == false && B.turn == true)//Если у нас умножение вида: A*T
					{
						//cout << "\nAt" << endl;
						if (i != B.k && i != B.l) //копируем нужные столбцы
							result.A[f][i] = (*this).A[f][i];
						else //а все остальное умножаем как обычно
							result.A[f][i] = result.A[f][i] + A[f][j] * B.A[j][i];
					}
					else if (transpan == true && turn == true)//Если у нас умножение вида: Tt*A
					{
						//cout << "\nTtA" << endl;
						if (f != (*this).k && f != (*this).l) //копируем нужные строки
							result.A[f][i] = B.A[f][i];
						else //а все остальное умножаем как обычно
							result.A[f][i] = result.A[f][i] + A[f][j] * B.A[j][i];
					}
					else //Если у нас умножение не на матрицу поворота, то умножаем как обычно
					{
						cout << "\nnichuya" << endl;
						result.A[f][i] = result.A[f][i] + A[f][j] * B.A[j][i];
					}
				}
			}
		if (transpan == true && turn == true)
		{
			cout << "\nTt*A" << endl;
			result.showData();
		}
		else {
			cout << "\nTt*A*T" << endl;
			result.showData();
		}
		return result;
	}

		
	//нужная сумма квадрата внедиагональных элементов
	double MaxEl(){
		double max = 0;
		for (int i = 0; i<size; i++)
			for (int j = 0; j < size; j++)
				if (i != j && abs((*this)[i][j])>max)
					max = (*this)[i][j];
		return max;
	}
	Matrix Jacoby(){
		//Объявление необходимых переменных
		Matrix V(size);		
		Matrix T(size); //матрица поворота
		Matrix Tt(size);
		V = (*this); //теперь ЭТО наша исходная матрица
		double Control = 0; //нужная сумма квадрата внедиагональных элементов
		double max; //нужный максимальный внедиагональный элемент
		int k=0, l=0; //это нужные нам индексы cos and sin
		double p = 0, fi = 0; //нужный угол поворота
		double c = 0, s = 0; //cos and sin
		int ch = 0;
		//Итерационный процесс
		Control = V.MaxEl(); //ищем нужную нам сумму
		while (abs(Control)>eps){
			max = 0;
			T.Kroneker();//матрица поворота должна быть похожа на единичную
			//ищем нужный максимальный внедиагональный элемент
			for (int i = 0; i<size; i++)
				for (int j = 0; j < size; j++)
					if (i != j && j>i && V[i][j] > max){
						max = V[i][j];
						k = i; l = j;//находим индексы
					}
			cout << "max=V[" << k + 1 << "][" << l + 1 << "];" << endl;
			T.k = k; T.l = l; //Сохраняем найденные индексы в матрице поворота
			if (V[k][k] - V[l][l] == 0) {//если тангенса нет => угол равен 45
				fi = 0.78539816339;
				c = cos(fi); //косинус фи
				s = sin(fi);	//синус фи
			}
			else {
				p = 2.0 * V[k][l] / (V[k][k] - V[l][l]);//временная переменная из формулы
				fi = 0.5*atan(p); //находим угол фи
				c = cos(fi); //косинус фи
				s = sin(fi);	//синус фи
			}
			cout << "fi=" << fi << endl;
			//определяем матрицу поворота
			T.A[k][k] = c;
			T.A[k][l] = s*(-1);
			T.A[l][k] = s;
			T.A[l][l] = c;
			T.turn = true; //помечаем матрицу поворота
			Tt = T.Trans(size); //транспанируем матрицу поворота			
			V = Tt*V*T; //перемножение матриц
			cout << "\nT" << ch << endl; T.showData();
			cout << "\nV" << ch << endl; V.showData();
			Control = V.MaxEl();
			cout << "\nmax el=" << Control << endl;
			cout << "\nControl: " << Control - eps << endl;
			if (abs(Control) < eps)
				cout << "\nyes" << endl;
			else cout << "\nno" << endl;
			//if (ch == 5) break;
			ch++;
		}
		return V;
	}

};

class Vector {
private:
	int size;
	double *V;
public:
	//конструктор вектора
	Vector(int size) : size(size)
	{
		size = size;
		V = new double[size];
		for (int i = 0; i < size; i++)
			V[i] = 0;
	}
	//конструктор копирования
	Vector(const Vector &B) : size(B.size)
	{
		V = new double[size];
		for (int i = 0; i < size; i++)
			V[i] = B.V[i];
	}
	//умножение матрицы на вектор
	Vector MultMatrixInVector(Matrix A)
	{
		Vector result(size); //создали vector result
		for (int i = 0; i<size; i++) //перемещаемся по столбцам матрицы result
		for (int j = 0; j<size; j++) //индекс который меняется при умножении
			result.V[i] = result.V[i] + A.ReturnElementMatrix(i, j) * V[j];
		return result;
	}
	//взять элемент вектора
	double &operator[](int j)
	{
		return V[j];
	}
	//вывод данных вектора на экран
	void ShowData()
	{
		for (int i = 0; i<size; ++i)
			cout << V[i] << "\n";
	}
	//создать рандомный вектор
	void Random()
	{
		srand(time(NULL)); // Инициализируем генератор случайных чисел.
		// А дальше работа как с обычным массивом.
		for (int i = 0; i < size; i++)
			(*this).V[i] = rand() % 10; // Каждый элемент случайному числу от 0 до 9
	}

	//создать вектор b
	void Create(Matrix A)
	{
		int ch = 0;
		int k;
		cout << "\nКак хотите создать вектор свободных членов?\nВедите 1 чтобы создать рандомный.\nВведите 2 чтобы создать из любого столбца матрицы А\n";
		cout << "Ваш выбор: "; cin >> ch;
		if (ch == 1)
			(*this).Random();
		else if (ch == 2)
		{
			//(*this).Create(A);
			cout << "Какой стоблец матрицы выбрать для создания вектора свободных членов?" << endl;
			cout << "Введите номер столбца: "; cin >> k;
			if (k <= 0 || k>size)
			{
				cout << "ERROR!\nСтолбец может быть только положительным и/или не превышать размерность матрицы!" << endl;
				cout << "По умолчанию создан рандомный вектор." << endl;
				(*this).Random();
			}
			else
			for (int i = 0; i < size; i++)
				(*this)[i] = A.ReturnElementMatrix(i, k - 1);
		}
		else
		{
			cout << "Введено число, отличное от 1 и 2.\nПо умолчанию создан рандомный вектор." << endl;
			(*this).Random();
		}
	}

	//метод квадратного корня решения СЛАУ
	Vector SquareRootMethod(Matrix A, int size)
	{
		//ПРЯМОЙ ХОД

		Matrix D(size);
		Matrix S(size);
		//cout << "\nF O R W A R D: " << endl;
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
						if (k == 0)
							sum1 = 0;
						sum1 += D[k][k] * abs(S[k][i]) * abs(S[k][i]);
					}
					((A[i][i] - sum1)>0) ? D[i][i] = 1 : D[i][i] = -1; //2
					S[i][i] = sqrt(abs(A[i][i] - sum1));
				}
				else if (i + 1 <= j)
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

		//ОБРАТНЫЙ ХОД

		Vector x(size);
		//cout << "\nR E V E R S E: " << endl;
		sum1 = 0;
		sum2 = 0;
		Vector y(size);
		y[0] = (*this)[0] / (S[0][0] * D[0][0]);
		for (int i = 1; i<size; ++i)
		{
			sum1 = 0;
			for (int k = 0; k<i; ++k)
				sum1 += D[k][k] * S[k][i] * y[k];
			y[i] = ((*this)[i] - sum1) / (S[i][i] * D[i][i]);
		}
		x[size - 1] = y[size - 1] / S[size - 1][size - 1];
		for (int i = size - 2; i >= 0; --i)
		{
			sum2 = 0;
			for (int k = i + 1; k<size; ++k)
				sum2 += S[i][k] * x[k];
			x[i] = (y[i] - sum2) / S[i][i];
		}
		cout << "\nVector x" << endl;
		x.ShowData(); cout << endl;
		return x;
	}

	void Check(Matrix A, Vector b, int size)
	{
		Vector Result(size);
		Result = (*this).MultMatrixInVector(A);
		int flag[1] = { 0 };
		for (int i = 0; i<size; ++i)
		{
			if (abs(Result[i] - b[i])>eps)
			{
				flag[0] = 1;
				cout << "Погрешность:" << " " << abs(Result[i] - b[i]) << endl;
			}
			else
				cout << "Погрешность:" << " " << abs(Result[i] - b[i]) << endl;
		}
		if (flag[0] != 0)
			cout << "\nВывод: NO" << endl;
		else
			cout << "\nВывод: OK" << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Привет Мир!" << endl;

	//Enter dates
	int size;
	int gamma;
	cout << "Заказанная точность: " << eps << "\n" << endl;
	cout << "Матрица создается рандомно.\nВведите размер матрицы: "; cin >> size;
	if (size <= 0)
	{
		cout << "ERROR!\nРазмер должен быть только положительным." << endl;
		return 0;
	}
	cout << "Формула для создания симметричной матрицы:\nC*C + gE, где g - любое число, E - единичная матрица,\nC - любая матрица, C* - транспанированная к ней матрица.\n " << endl;
	cout << "Введите g="; cin >> gamma;

	//Determined matrix
	Matrix A(size); //matrix coefficients
	Matrix V(size);

	//Algorithm
	//A = A.Symmetric(gamma);	//create a symmetric matrix
	A.CreateMatrix();
	cout << "\nA:" << endl; A.showData();
	V = A.Jacoby();
	cout << "\nV:" << endl; V.showData();
	return 0;
};
