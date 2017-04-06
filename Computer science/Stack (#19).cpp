#include <iostream>
#include <fstream>
#include <string>
usingnamespace std;
 
template<class Item>
class Stack
{
struct Element
{
        Item inf;
        Element *next;
        Element (Item x, Element *p):inf(x),next(p)
{
}
};
    Element *head;
public:
    Stack(): head(0)
{
}
bool Empty()
{
return head==0;
}
    Item Pop()
{
if(Empty())
{
return0;
}
        Element *r=head;
        Item i=r->inf;
        head = r->next;
delete r;
return i;
}
void Push(Item data)
{
        head=new Element(data,head);
}
    Item Top()
{
if(Empty())
{
return0;
}
else
{
return head->inf;
}
}
};
 
int main()
{
    setlocale(LC_ALL,"russian");
int n,i=0,h=0;
    Stack <string> link,knil;
    string str,rts;
    ofstream out("output.txt");
cout<<"Задача: записать слова в файл при этом продублировать однобуквенные слова"<<endl;
cout<<"Сколько слов будет в списке?\nn=";
cin>>n;
while(i<n)
{
cout<<"str=";
cin>>str;
        link.Push(str);
++i;
}
if(link.Empty())
{
cout<<"Стек пустой"<<endl;
}
else
{
while(!link.Empty())
{
            rts=link.Pop();
if(rts.length()==1)
{
                knil.Push(rts);
                h++;
}
            knil.Push(rts);
}
if(h==0)
cout<<"Нет однобуквенных слов"<<endl;
else
cout<<"Все однобуквенные слова продублировались! Поздравляю!"<<endl;
while(!knil.Empty())
{
            out<<knil.Pop()<<" ";
}
}
    out.close();
return0;
}
