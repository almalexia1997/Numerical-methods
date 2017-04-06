#include <fstream>
#include <iostream>
#include <string>
usingnamespace std;
int main()
{
int k =0,p=0,o=0,i=0;
string str, otvet;
ifstream in("ruslan.txt");
while(getline(in, str))
{
i++;
if(str.length()==0)p++;
elseif(str.length()==1)o++;
elseif(str[0]==str[str.length()-1]&& str.length()!=0)k++;
 
}
if(i==0)cout<<"файл пуст"<<endl;else{
cout<<"Количество повторяющихся строк="<<k<<endl;
cout<<"Количество пустых строк="<<p<<endl;
cout<<"Количество односимвольных строк="<<o<<endl;}
in.close();
return0;
}
