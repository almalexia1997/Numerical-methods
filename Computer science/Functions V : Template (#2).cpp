#include <iostream>
#include <vector>
#include <string>
usingnamespace std;
 
template<typename item>
void creat(vector<vector<item>>&mas)
{
int n,m;
cout<<"n=";cin>>n;
	mas.resize(n);
cout<<"m=";cin>>m;
for(int i=0;i<n;++i)
{
		mas[i].resize(m);
for(int j=0;j<m;++j)
{
cout<<"mas["<<i<<"]["<<j<<"]=";
cin>>mas[i][j];
}
}
}
 
template<typename item>
 
void print(vector<vector<item>>mas)
{
for(int i=0;i<(int)mas.size();++i)
{
for(int j=0;j<(int)mas[i].size();++j)
{
cout<<mas[i][j]<<" ";
}
cout<<endl;
}
}
 
template<typename item>
void function(vector<vector<item>>&mas)
{
	item r;
cout<<"r=";cin>>r;
for(int i=0;i<(int)mas.size();++i)
{
for(int j=0;j<(int)mas[i].size();++j)
{
if(mas[i][j]<r)
			mas[i][j]=r;
}
}
}
 
int main()
{
cout<<"int"<<endl;
	vector<vector<int>> intMas;
	creat(intMas);
	function(intMas);
	print(intMas);
 
cout<<"double"<<endl;
	vector<vector<double>> doubleMas;
	creat(doubleMas);
	function(doubleMas);
	print(doubleMas);
 
cout<<"string!"<<endl;
	vector<vector<string>> stringMas;
	creat(stringMas);
	function(stringMas);
	print(stringMas);
return0;
}
