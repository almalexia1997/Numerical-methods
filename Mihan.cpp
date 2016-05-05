#include<iostream.h>

#include<math.h>

int maximal(int n,double R0[]);

void main(){

int i,j,n,f,k,iter;

double S,det;

cout<<"Введите размерность матрицы(матрица должна быть квадратной)= ";cin>>n;

double *x=new double [n];

double **b=new double *[n];

for(i=0;i<n;i++)

b[i]=new double[n+1];

double **a=new double *[n];

for(i=0;i<n;i++)

a[i]=new double[n+1];

cout<<"Введите количество итераций:";

cin>>iter;

cout<<"Введите расширенную матрицу:n";

for(i=0;i<n;i++){

for(j=0;j<=n;j++)

cin>>b[i][j];

}

cout<<"Подготавливаю матрицу к релаксации...n";

for(i=0;i<n;i++){

for(j=0;j<n;j++)

a[i][j]=-b[i][j]/b[i][i];

a[i][n]=b[i][n]/b[i][i];

}

for(i=0;i<n;i++){

for(j=0;j<n+1;j++)

cout<<" "<<a[i][j]<<" || ";

cout<<"n";

}

double *x0=new double [n];

for(i=0;i<n;i++)

x[i]=0.0;

double *R0=new double [n];

cout<<"Введите значения начальных приближений:n";

for(i=0;i<n;i++)

cin>>x0[i];

S=0.0;

for(i=0;i<n;i++){

for(j=0;j<n;j++)

S=S+a[i][j]*x0[i];

}

for(i=0;i<n;i++){

R0[i]=a[i][n]-x0[i]+S;

cout<<"R("<<i<<")="<<R0[i]<<" | ";

}

f=maximal(n,R0);

det=R0[f];

for(k=0;k<iter;k++){

cout<<"det{"<<k<<"}="<<det<<"n";

for(i=0;i<n;i++){

if(i!=f) R0[i]=R0[i]+a[i][f]*det;

else R0[i]=R0[i]-det;

}

for(i=0;i<n;i++)

cout<<"R["<<i+1<<"]="<<R0[i]<<" ";

x[f]=x[f]+det;

f=maximal(n,R0);

det=R0[f];

}

cout<<"n";

for(i=0;i<n;i++)

cout<<"X{"<<i+1<<"}="<<x[i]<<"n";

delete []x;

delete []R0;

delete []x0;

delete []a;

}

int maximal(int n, double R0[]){

int i,f;

f=0.0;

for(i=0;i<n-1;i++){

if(R0[i+1]>R0[i]) f=i+1;

}

return f;

}
