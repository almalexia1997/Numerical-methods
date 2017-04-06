#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
usingnamespace std;
int main()
{
int x;
	ifstream in("f.txt");
	ofstream out("g.txt");
	ofstream out2("h.txt");
while(!in.eof())
{
		in>>x;
if(x<0)out<<setw(5)<<x;elseif(x>0) out2<<setw(5)<<x;
}
return0;
}
