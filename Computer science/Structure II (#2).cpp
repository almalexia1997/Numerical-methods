#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale>
#include <vector>
usingnamespace std;
 
ifstream in("input.txt");
ofstream out("output.txt");
 
struct spisok
{
int year;
    string surname, name, patronymic, street, home, school, number;
void show();
void print();
};
void spisok::show()
{
cout<<surname<<" "<<name<<" "<<patronymic<<"; "<<year<<" года рождения; домашний адрес: "<<street<<" "<<home<<"; окончил: "<<school<<" "<<number<<" "<<endl;
}
void spisok::print()
{
    out<<surname<<" "<<name<<" "<<patronymic<<"; "<<year<<" года рождения; домашний адрес: "<<street<<" "<<home<<"; окончил: "<<school<<" "<<number<<" "<<endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    vector<spisok>student(10);
int i,j,n=0,y=0,p=0;
if(!in)cout<<"Error input"<<endl;
else{
cout<<"Список студентов группы, все они пошли в школу в 6 лет\n"<<endl;
while(in.peek()!=EOF)
{
            in>>student[n].surname;
            in>>student[n].name;
            in>>student[n].patronymic;
            in>>student[n].year;
            in>>student[n].street;
            in>>student[n].home;
            in>>student[n].school;
            in>>student[n].number;
            student[n].show();
            n++;
}
cout<<"\nВведите нынешний год: ";cin>>y;
if(!out)cout<<"Ошибка при открытии файла output,txt\n";
else{
            j=0;
for(i=0; i<n; i++)
if((student[i].year+6)==y-11)
{
for(j=i;j<n-1;j++) student[j]=student[j+1];
                    n--;i--;
}
for(i=0;i<n;i++)
{student[i].print();p++;}
if(p==0)cout<<"empty"<<endl;
}
}
    in.close();out.close();
return0;
}
