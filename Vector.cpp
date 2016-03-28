
using namespace std;

class Vector
{
private:
    int size;
    double *V;
public:
    Vector(int size);
    Vector MultMatrixInVector(Matrix A); //умножение матрицы на векто
    ~Vector();
    double &operator[](int j) //перегрузка []
    {
        return V[j];
    }
    Vector operator= ( const Vector &obj ) {
        //копируем obj
        for ( int i = 0; i < size; i++ ) {
            V[i] = obj.V[i];
        }
        return *this;
    }
    void ShowData();
    void Random();
};


Vector::Vector(int size) : size(size)
{
	size = size;
    V = new double [size];
    for(int i = 0; i < size; i++)
    {
        V[i] = 0;
    }
}
Vector::~Vector()
{
    delete[] V;
};

Vector Vector::MultMatrixInVector(Matrix A)
{
    Vector result(size); //создали vector result
    for(int i=0;i<size;i++) //перемещаемся по столбцам матрицы result
        for(int j=0;j<size;j++) //индекс который меняется при умножении
            result.V[i]= result.V[i] + A.ReturnElementMatrix(i,j) * V[j];
    return result;
}

void Vector::ShowData()
{
	for(int i=0;i<size;++i)
		cout<<V[i]<<"\n";
}

void Vector::Random()
{
    srand(time(NULL)); // Инициализируем генератор случайных чисел.
    // А дальше работа как с обычным массивом.
    for (int i = 0; i < size; i++)        
    	(*this).V[i] = rand() % 10; // Каждый элемент случайному числу от 0 до 9
}
