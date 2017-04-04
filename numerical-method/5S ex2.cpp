// Юсупов Р. Зад.№ 15. RK2
#include <cmath>
#include <iostream>
#include<iomanip>

using namespace std;

const int m=4,p=2; // ??    число ур. и поряд.метода        
double norma (int m, double y1[],double y2[])
{
    double sum=0;
    for(int i=0; i<m; i++)
        sum+=pow(y1[i]-y2[i],2);
    return sqrt(sum);
}

void fun(double u[m], double x, double f[m]) {
    f[0]=u[1]; // функция правой части ОДУ
    f[1]=u[2];
    f[2]=u[3];
    f[3]=-5.*u[3]-u[2]-120.*u[1]-650.*u[0]+exp(5*x-5)*(11.5*sin(x)+4.9*cos(x));
}
void FormRK(double y0[m], double x, double h, double y[m])
{
    double f[m];
    fun(y0, x, f);
    for(int i=0;i<m;++i)// формулы мет. эйлера на шаге h
        y[i]=y0[i]+h*f[i];  
}

void FormRK2(double y0[], double x, double h, double y[]){
    double f[m],k1[m],k2[m],r[m];
    fun(y0,x,f);
    for(int i=0;i<m;++i){
        k1[i]=h*f[i];
        r[i]=y0[i]+k1[i];
    }
    fun(r,x+h,f);
    for(int i=0;i<m;++i){
        k2[i]=h*f[i];
        y[i]=y0[i]+0.5*(k1[i]+k2[i]);
    }
}

void shag(double y[m],double x,double &h, double eps,double &el)//vybor shaga ??
{// ф-я алгор. автомат.выбора шага h𝒌
    double yh[m],yhh[m];
    for(;;)
    {
        FormRK2(y,x,h,yh);
        FormRK2(y,x,h/2,yhh);
        FormRK2(yhh,x+h/2,h/2,yhh);   //  ??   h/x
        el=norma(m,yhh,yh)/(pow(2.,p)-1);
        if(el>=eps){h/=2;}
        else if(el<eps/pow(2,(p+1))) {h*=2;break;}
        else break;
    }
    }
//=================================================================//===========

void MetRK(double y[m], double x, double xN, double h, double eps)
{
    double el; // погрешность решения на шаге
    cout<<setw(10)<<"x"<<setw(10)<<"y[0]"<<setw(10) //заголовки таблицы
    <<"y[1]"<<setw(10)<<"y[2]"<<setw(10)<< "y[3]"<<setw(10)<<"h"<<
    setw(10)<<"el"<<endl;
    cout<<fixed<<setw(10)<<setprecision(4)<<x<<setw(10)<<y[0]<<setw(10)<<y[1]<<
    setw(10)<<y[2]<<setw(10)<< y[3]<<setw(10)<<h<<setw(10)<<el<<endl;
    for(;;)
    {
        shag(y,x,h,eps,el); //cout<<fixed<<setw(10)<<setprecision(4)<<h<<endl;
        if((xN-x)<=h) {h=xN-x;} //уточн.  перем.шага перед конц.отрезка арг.ум
        FormRK2(y, x, h, y);
        x += h;
        cout<<fixed<<setw(10)<<setprecision(4)<<x<<setw(10)<<y[0]<<setw(10)<<
        y[1]<<setw(10)<<y[2]<<setw(10)<<y[3]<<setw(10)<<h<<setw(10)<<el<<endl;
        if(x==xN) break;  
    }
    cout<<fixed<<"\n \t eps="<<eps<<endl;
    cout<<fixed<<" \t h="<<h<<endl;
}

//=================================================================///==========

int main() {
    //int N=11.; //количество шагов
     double eps = 0.005;//h; //погрешность
    double x0 = 0 ,xN = 1, h=pow(eps,1./p); // начальные значения и шаг
    cout<<"\th="<<h<<endl;
    double y0[m]={-1,1,-2,6}; //значения начальных условий  
    MetRK(y0, x0, xN, h, eps); // получение решения
    return 0;
} 
