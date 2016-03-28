#include <iostream>
#include <cmath>
#include "Matrix.cpp"
#include "Vector.cpp"

using namespace std;

/*void StraightCourse(Matrix A,Matrix S,Matrix D,int size)
{
    double sum1=0;
    double sum2=0;
    (A[0][0]>0)? D[0][0]=1 : D[0][0]=-1;
    S[0][0]=sqrt(abs(A[0][0]));
    for(int j=1;j<size;++j)
        S[0][j]=A[0][j]/S[0][0];
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
        {

            if(i==j)
            {
                for(int k=0;k<i;++k)
                    double sum1=sum1+D[k][k]*S[k][i]*S[k][i];
                ((A[i][i]-sum1)>0)? D[i][i]=1 : D[i][i]=-1;
                S[i][i]=sqrt(abs(A[i][i]-sum1));
            }
            else if(i<j)
            {
                for(int k=0;k<i;++k)
                    sum2=sum2+D[k][k]*S[k][i]*S[k][j];
                S[i][j]=(A[i][j]-sum2)/(S[i][i]*D[i][i]);
            }
            else
                S[i][j]=0;
        }
    }
}*/

void StraightCourse(Matrix A,Matrix S,Matrix D,int size)
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
                for(int k=0;k<i;++k)
                    double sum1=sum1+S[k][i]*S[k][i];
                S[i][i]=sqrt(abs(A[i][i]-sum1));
            }
            else if(i<j)
            {
                for(int k=0;k<i;++k)
                    sum2=sum2+S[k][i]*S[k][j];
                S[i][j]=(A[i][j]-sum2)/(S[i][i]);
            }
            else
                S[i][j]=0;
        }
    }
}

//

/*void Reverse(Vector b, Vector x, Matrix S, Matrix D, int size)
{
    int sum1=0;
    int sum2=0;
    Vector y(size);
    y[0]=b[0]/(S[0][0]*D[0][0]);
    for(int i=1;i<size;++i)
    {
        for(int k=0;k<=i-1;++k)
            sum1=sum1+D[k][k]*S[k][i]*y[k];
        y[i]=(b[i]-sum1)/(S[i][i]*D[i][i]);
    }
    x[size-1]=y[size-1]/S[size-1][size-1];
    for(int i=size;i>=0;--i)
    {
        for(int k=size;k>i;--k)
            sum2=sum2+S[i][k]*x[k];
        x[i]=(y[i]-sum2)/S[i][i];
    }
}*/

void Reverse(Vector b, Vector x, Matrix S, Matrix D, int size)
{
    int sum1=0;
    int sum2=0;
    Vector y(size);
    y[0]=b[0]/(S[0][0]);
    for(int i=1;i<size;++i)
    {
        for(int k=0;k<i;++k)
            sum1=sum1+S[k][i]*y[k];
        y[i]=(b[i]-sum1)/(S[i][i]);
    }
    x[size-1]=y[size-1]/S[size-1][size-1];
    for(int i=size-2;i>=0;--i)
    {
        for(int k=size-1;k>i;--k)
            sum2=sum2+S[i][k]*x[k];
        x[i]=(y[i]-sum2)/S[i][i];
    }
}

int main()
{
    int size;
    cout<<"size=";cin>>size;
    Matrix A(size); //matrix coefficients
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
        {
            cout<<"A["<<i+1<<"]["<<j+1<<"]=";
            cin>>A[i][j];
        }
    Vector b(size); //We create a vector of free terms
    for (int i=0;i<size;++i)
    {
        cout<<"b["<<i+1<<"]=";
        cin>>b[i];
    }

    Matrix S(size); //matrix decomposition
    Matrix St(size);//transposed matrix decomposition
    Matrix D(size); //diagonal matrix
    StraightCourse(A,S,D,size); //create matrix decomposition
    St.Inverse(size,S); //create transposed matrix decomposition
    cout<<"\nMatrix A"<<endl;
    A.showData();
    cout<<"\nVector b"<<endl;
    b.ShowData();
    cout<<"\nMatrix S"<<endl;
    S.showData();
    cout<<"\nMatrix St"<<endl;
    St.showData();

    Vector x(size); //unknown vector
    Reverse(b,x,S,D,size);
    cout<<"\nVector x"<<endl;
    x.ShowData();
};


