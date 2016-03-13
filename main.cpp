#include <iostream>
#include <cmath>
#include "Matrix.cpp"
#include "Vector.cpp"

using namespace std;

void StraightCourse(Matrix A,Matrix S,int size)
{
    double sum1=0;
    double sum2=0;
    S[0][0]=sqrt(abs(A[0][0]));
    for(int j=1;j<size;++j)
        S[0][j]=A[0][j]/S[0][0];
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
        {
            if(i==j)
            {
                for(int k=0;k<=i-1;++k)
                    double sum1=sum1+S[k][i]*S[k][i];
                S[i][i]=sqrt(abs(A[i][i]-sum1));
            }
            else if(i<j)
            {
                for(int k=0;k<=i-1;++k)
                    sum2=sum2+S[k][i]*S[k][j];
                S[i][j]=(A[i][j]-sum2)/S[i][i];
            }
            else if(i>j)
                S[i][j]=0;
        }
    }
}

void Reverse(Vector b, Vector x, Matrix S, int size)
{
    int sum1=0;
    int sum2=0;
    Vector y(size);
    y[0]=b[0]/S[0][0];
    for(int i=1;i<size;++i)
    {
        for(int k=0;k<=i-1;++k)
            sum1=sum1+S[k][i]*y[k];
        y[i]=(b[i]-sum1)/S[i][i];
    }
    x[size-1]=y[size-1]/S[size-1][size-1];
    for(int i=size;i>=0;--i)
    {
        for(int k=size;k>=i+1;--k)
            sum2=sum2+S[i][k]*x[k];
        x[i]=(y[i]-sum2)/S[i][i];
    }
}

int main()
{
    int size;
    cout<<"size=";cin>>size;
    Matrix A(size); //создаем матрицу
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
        {
            cout<<"A["<<i+1<<"]["<<j+1<<"]=";
            cin>>A[i][j];
        }
    Vector b(size); //создаем вектор свободных членов
    for (int i=0;i<size;++i)
    {
        cout<<"b["<<i+1<<"]=";
        cin>>b[i];
    }

    Matrix S(size); //создаем матрицу для разложения Холецкого
    Matrix St(size);
    StraightCourse(A,S,size); //прямой ход
    St.Inverse(size,S);

    Vector x(size); //искомый вектор
    Reverse(b,x,S,size); //обратный ход

    A.showData();
    cout<<endl;
    Matrix At(size);
    At.Inverse(size,A);
    At.showData();
    cout<<endl;
    S.showData();
    cout<<endl;
    St.showData();
    cout<<endl;
    x.ShowData();
    return 0;
};


