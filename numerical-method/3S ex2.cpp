#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
 
usingnamespace std;
 
constdouble PI =3.1415926535897;
 
ofstream out1("Graph.txt");
ofstream out2("Revealstate.txt");
ofstream out3("Chebyshev.txt");
 
//Многочлен Лагранжа
longdouble Lagrange(double*chebush, double*Y, double n, double x)
{
longdouble F,res=0;
for(int i=0;i<n;i++)
{
        F=1;
for(int j=0;j<n;j++)
{
if(i!=j)
                F*=(x-chebush[j])/(chebush[i]-chebush[j]);
}
        res+=F*Y[i];
}
return res;
}
 
//Многочлен Ньютона
longdouble Newton_f(double*roots, double*y, double n, double x)
{
longdouble res=y[0],F,den;
int i,j,k;
for(i=1;i<n;i++)
{
        F=0;
for(j=0;j<=i;j++)
{//следующее слагаемое полинома
            den=1;
//считаем знаменатель разделенной разности
for(k=0;k<=i;k++)
{
if(k!=j)
                    den*=(roots[j]-roots[k]);
}
//считаем разделенную разность
            F+=y[j]/den;
}
//домножаем разделенную разность на скобки (x-x[0])...(x-x[i-1])
for(k=0;k<i;k++)
            F*=(x-roots[k]);
        res+=F;//полином
}
return res;
}
 
 
//высчитываем значение функции в равноотстоящих узлах интерполяции
void func_in_roots1(double*roots, double*y, double n)
{
for(int k=0; k<n;++k)
{
        y[k]=sqrt(abs(roots[k]));
cout<<"y="<<y[k]<<endl;
}
}
 
//высчитываем значение функции в Чебышевских узлах интерполяции
void func_in_roots2(double*chebush, double*Y, double n)
{
for(int k=0; k<n;++k)
{
        Y[k]=sqrt(abs(chebush[k]));
cout<<"Y="<<Y[k]<<endl;
}
}
 
int main()
{
//входные данные
int a=-1.0, b=1.0,k=1;
double h, n, point=500.0, L1, L2;
cout<<"a=-1"<<endl;
cout<<"b=1"<<endl;
    h=(b-a)/point;//фиксированное количество точек: 500
cout<<"n=";cin>>n;//количество интерполяционных узлов
 
double*roots =newdouble[(int)n];//список узлов интерполяции(равноотстоящих)
double xk=0;//узел интерполяции
for(int k=1.0; k<=n;++k)
{
        xk=a+(((b-a)*(k-1))/(n-1));//высчитываем равноотстоящий узел
cout<<"x"<<k<<"="<<xk<<endl;;
        roots[k-1]=xk;//записываем очередной равноотстоящий узел в список узлов
}
 
double*chebush =newdouble[(int)n];//список узлов интерполяции(чебышевских)
    xk=0;//узел интерполяции
for(int k =1.0; k <= n;++k)
{
double v, m, u;
		v =(b + a)/2.0;
		m =(b - a)/2.0;
		u =((2.0*k -1)*PI)/(2.0*n);
		xk =(v + m*cos(u));//высчитываем Чебышевский узел
cout<<"x"<< k <<"="<< xk << endl;
        chebush[k-1]=xk;//записываем очередной Чебышевский узел в список узлов
}
 
double*y =newdouble[(int)n];//значения функции в равноотстоящих узлах интерполяции
    func_in_roots1(roots,y,n);//высчитываем значение функции в равноотстоящих узлах интерполяции
 
double*Y =newdouble[(int)n];//значения функции в Чебышевских узлах интерполяции
    func_in_roots2(chebush,Y,n);//высчитываем значение функции в Чебышевских узлах интерполяции
 
 
for(double x=a; x<=b; x+=h)
{
        out1<<x<<' '<<sqrt(abs(x))<<'\n';//выводим саму функцию
        L1 = Newton_f(roots,y,n,x);
        L2 = Lagrange(chebush,Y,n,x);
        out2<<x<<' '<<L1<<'\n';//выводим многочлен Ньютона по равноотстоящим узлам
        out3<<x<<' '<<L2<<'\n';//выводим многочлен Лагранжа по Чебышевским узлам
}
cout<<"h="<<h<<endl;
return0;
}
