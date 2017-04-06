#include <iostream>
#include <string>
usingnamespace std;
int main()
{
int ch=0;//флажок для оповещения
	string str, str1, str2;
	string::size_type pos =0;
cout<<"str="; getline(cin, str);//вводим строку
cout<<"str1="; getline(cin, str1);//вводим построку str1
cout<<"str2="; getline(cin, str2);//вводим построку str2
	string::size_type len1 = str1.length();
	string::size_type len2 = str2.length();
	string::size_type a = str.find(str1);//первое вхождение подстроки str1
if(len1==0)//если строки нет
{
cout<<"Ничего не найдено"<<endl;//сообщаем об этом
return0;
}
while(a != string::npos)//пока находятся новые вхождения подстроки str1
{
		str.replace(a, len1, str2);//заменяем подстроку str1 подстрокой str2
		ch++;//флажок что предыдущее действие выполнилось
		pos = a + len2;//ищем новою позицию с которйо будем искать новое вхожденеи подстроки str1
		a = str.find(str1, pos);//ищем новое вхожденеи подстркои str1
}
if(ch==0)//если флажок не изменился
cout<<"Строка не изменилась"<<endl<<str<<endl;//сообщаем об этом
else//иначе
cout<<"str="<< str << endl<<ch<<endl;//выводим результат
	string::size_type len = str.length();//длина строки
cout<< len<<endl;//и вывод ее на экран
return0;
}
