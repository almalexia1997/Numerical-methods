#include <iostream>
#include <string>
 
usingnamespace std;
int main()
{
    string str;
cout<<"Enter string"<< endl; getline(cin, str);
int ch=0;
unsignedint z=0;
bool otvet[10];
for(int i=0;i<10;i++)
{
        otvet[i]=false;
}
for(int i=0;i<(int)str.length();i++)
{
if(isdigit(str[i])&&str[i]%2!=0)
{
            otvet[str[i]-'0']=true;
}
 
}
for(int i=0;i<str.length();++i)
if(!isdigit(str[i]))z++;
for(int i=0;i<10;i++)
if(otvet[i]){cout<<i<<" ";ch++;}
if(z==str.length())cout<<"no number"<<endl;
elseif(ch==0)cout<<"все четные!"<<endl;
return0;
}
