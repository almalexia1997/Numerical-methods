#include <iostream>
#include <vector>
#include <algorithm>
usingnamespace std;
 
int x;
 
bool Pred(int a)
{
if(a%10==x)
returntrue;
else
returnfalse;
}
 
int main()
{
	setlocale(LC_ALL,"russian");
int n,a;
cout<<"x=";
cin>>x;
cout<<"n=";
cin>>n;
	vector<int>sequence;
for(int i=0;i<n;++i)
{
cout<<"Введите элемент №"<<i<<endl;
cin>>a;
		sequence.push_back(a);
}
	vector <int>::iterator iEnd=remove_if(sequence.begin(),sequence.end(),Pred);
	sequence.erase(iEnd,sequence.end());
for(vector <int>::iterator iter=sequence.begin();iter<sequence.end();iter++)
cout<<*iter<<" ";
return0;
}
