#include <iostream>
#include <cmath>
#include "Matrix.cpp"
#include "Vector.cpp"

using namespace std;

void StraightCourse(Matrix A,Matrix S,int size)
{
    double sum1=0;
    double sum2=0;
    S[0][0]=sqrt(A[0][0]);
    for(int j=1;j<size;++j)
        S[0][j]=A[1][j]/S[1][1];
    for(int i=0;i<size;++i)
    {
        if(0<i<size)
        {
            for(int k=0;k<=i-1;++k)
                double sum1=sum1+S[k][i]*S[k][i];
            S[i][i]=sqrt(A[i][i]-sum1);
        }
        for(int j=0;j<size;++j)
        {
            if(i<j)
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

int main()
{
    int size;
    cout<<"size=";cin>>size;
    Matrix A(size);
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
        {
            cout<<"A["<<i<<"]["<<j<<"]=";
            cin>>A[i][j];
        }
    Matrix S(size);
    Matrix St(size);
    StraightCourse(A,S,size);
    St.Inverse(size,S);

    A.showData();
    cout<<endl;
    Matrix At(size);
    At.Inverse(size,A);
    At.showData();

    cout<<endl;
    S.showData();
    cout<<endl;
    St.showData();
    return 0;
};


