#include <iostream>
#include <fstream>
usingnamespace std;
 
int main()
{
	ofstream out("binary.dat", ios::binary);
int n;
cout<<"До какой степени вы хотите считать?\nn=";
cin>>n;
int t=1;
for(int i=0;i<=n;++i)
{
		out.write((char*)&t,sizeof(int));
		t*=3;
 
}
	out.close();
	ifstream in("binary.dat",ios::binary);
 
cout<<endl;
int s=0;
while(in.peek()!=EOF)
{
cout<<"степень:"<<s<<"\t";
		s+=2;
		in.read((char*)&t,sizeof(int));
cout<<"число: "<<t<<endl;
if(in.peek()!=EOF) in.seekg(sizeof(int),ios::cur);
}
	in.close();
return0;
}
