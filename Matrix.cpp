
using namespace std;

class Matrix //класс матрицы
{
private:
    int size;//переменная для размера матрицы
    double **A; //здесь храниться матрица
public:
    Matrix(int size); //конструктор матрицы
    Matrix MultMatrix(Matrix B); //умножение матриц    
    Matrix SumMatrix(Matrix B); //сложение матриц
    Matrix SubMatrix(Matrix B); //вычитание матриц
    Matrix Inverse(int size, Matrix B); //транспонированная матрица
    void showData();         //вывод данных массива на экран
    ~Matrix(); //деструктор матрицы
    double Ret(int i,int j);
    
//*********************************************************************

    double *operator [](int i) //взять элемент матрицы
    {
        return A[i];
    }
    Matrix& operator=( Matrix &B ) //перегрузка оператора присваивания
    {
        for(int i=0;i<size; ++i)
            delete[] A[i];
        delete[] A;
        size = B.size;
        A=new double *[size];
        for(int i = 0; i < size; ++i)
        {
            A[i]=new double [size];
            for (int j = 0; j < size; ++j)
                A[i][j] = B.A[i][j];
        }
        return *this;
    }
};


Matrix::Matrix(int size) : size(size)
{
    //создаем матрицу
    A=new double *[size];
    for(int i = 0; i < size; ++i)
    {
        A[i]=new double [size];
        for (int j = 0; j < size; ++j)
            A[i][j] = 0;
    }
}

Matrix Matrix::MultMatrix(Matrix B) //умножение матриц
{
    Matrix result(size); //создали матрицу result
    for(int k=0; k<size;k++) //перемещаемся по строкам матрицы result
        for(int i=0;i<size;i++) //перемещаемся по столбцам матрицы result
            for(int j=0;j<size;j++) //индекс который меняется при умножении
                result.A[k][i]= result.A[k][i] + A[k][j] * B.A[j][i];
    return result;
}

Matrix Matrix::SumMatrix(Matrix B) //сложение матриц
{
    Matrix result(size);
    for(int i=0; i<size;i++)
        for(int j=0;j<size;j++)
            result.A[i][j] = A[i][j] + B.A[i][j];
    return result;
}
Matrix Matrix::SubMatrix(Matrix B) //вычитание матриц
{
    Matrix result(size);
    for(int i=0; i<size;i++)
        for(int j=0;j<size;j++)
            result.A[i][j] = A[i][j] - B.A[i][j];
    return result;
}
Matrix Matrix::Inverse(int size, Matrix A) //транспонированная матрица
{
    for(int i=0; i<size;i++)
        for(int j=0;j<size;j++)
            (*this).A[i][j] = A.A[j][i];
}

void Matrix::showData()         //вывод данных массива на экран
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size ; ++j)
            cout << A[i][j] << "  ";
        cout << endl;
    }
}
Matrix::~Matrix()
{
    for(int i=0;i<size; ++i)
        delete[] A[i];
    delete[] A;
};

double Matrix::Ret(int i,int j)
{
    return A[i][j];
}


