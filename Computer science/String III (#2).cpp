#include <iostream>
#include <string>
usingnamespace std;
int main()
{
int ch =1;
	string str, slovo, slovo3, slovo10;
	string::size_type k =0, pos =0, len =0, max =0;
	string razdel =",.:;!? ";
cout<<"Enter string"<< endl;
	getline(cin, str);
for(unsignedint i =0; i < str.length();++i) str[i]=tolower(str[i]);
	k = str.find_first_of(razdel, pos);
	slovo10 ="";
while(k != string::npos)
{
		slovo = str.substr(pos, k - pos);
		string::size_type len = slovo.length();
if(ispunct(str[k]))
			pos = k +2;
else pos = k +1;
		k = str.find_first_of(razdel, pos);
if(len > max)
{
			max = len;
			slovo10 = slovo +" ";
			ch =1;
}
elseif(len == max)
{
 
if(slovo10.find(slovo)== string::npos)
{
				slovo10 = slovo10 + slovo +' '; ch++;
}
}
}
cout<<"\n#"<< slovo10 << endl;
cout<< endl;
if(max ==0)
{
cout<<"pusto"<< endl;
}
else{
cout<< max << endl;
cout<< ch << endl;
}
return0;
}
