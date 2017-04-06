#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
usingnamespace std;
 
int main()
{
	setlocale(LC_ALL,"russian");
int x,n;
cout<<"n=";
cin>>n;
	vector<int>sequence(n);
for(int i=0;i<n;++i)
{
cout<<"Введите элемент №"<<i<<endl;
cin>>sequence[i];
//sequence.push_back(x);
}
for(int i=0; i<(int)sequence.size();++i)
cout<<sequence[i]<<" ";
int sum=accumulate(sequence.begin(),sequence.end(),0);
cout<<"\n"<<sum<<endl;
if(sequence.empty())
cout<<"Empty"<<endl;
elseif(abs(sum)>9&&abs(sum)<100)
{
cout<<"Двузначное число"<<endl;
}
else
cout<<"Не двузначное число"<<endl;
return0;
}
