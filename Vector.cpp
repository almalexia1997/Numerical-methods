
using namespace std;

class Vector
{
private:
    int sizeV;
    double *V;
public:
    Vector(int sizeV);
    Vector MultMatrixInVector(Matrix A); //умножение матрицы на векто
    ~Vector();
};


Vector::Vector(int sizeV) : sizeV(sizeV)
{
	sizeV = sizeV;
    V = new double [sizeV];
    for(int i = 0; i < sizeV; i++)
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
    Vector result(sizeV); //создали vector result
    for(int i=0;i<sizeV;i++) //перемещаемся по столбцам матрицы result
        for(int j=0;j<sizeV;j++) //индекс который меняется при умножении
            result.V[i]= result.V[i] + A.Ret(i,j) * V[j];
    return result;
}
