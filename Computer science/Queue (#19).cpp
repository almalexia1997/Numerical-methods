#include <iostream>
#include <fstream>
#include <string>
usingnamespace std;
 
template<class Item>
 
class Queue
{
struct Element
{
        Item inf;
        Element *next;
        Element (Item x): inf(x), next(0)
{
}
};
    Element *head, *tail;
public:
    Queue():head(0),tail(0)
{
}
bool Empty()
{
return head==0;
}
    Item Get()
{
if(Empty())
{
return0;
}
else
{
            Element *t=head;
            Item i=t->inf;
            head = t->next;
if(head==NULL)
{
                tail=NULL;
}
delete t;
return i;
}
}
void Put(Item data)
{
        Element *t=tail;
        tail=new Element(data);
if(!head)
{
            head=tail;
 
}
else
{
            t->next=tail;
}
}
};
int main()
{
    setlocale(LC_ALL,"russian");
int n,h=0;
    Queue <string> link,knil;
    string str,rts;
    ofstream out("output.txt");
cout<<"Задача: записать слова в файл при этом продублировать однобуквенные слова"<<endl;
cout<<"Сколько слов будет в списке?\nn=";
cin>>n;
for(int i=0;i<n;++i)
{
cout<<"str=";
cin>>str;
if(str.length()==1)
            h++;
        link.Put(str);
}
if(link.Empty())
{
cout<<"Очередь пустая, T_T"<<endl;
}
else
{
while(!link.Empty())
{
            rts=link.Get();
if(rts.length()==1)
{
                knil.Put(rts);
                h++;
}
            knil.Put(rts);
}
if(h==0)
cout<<"Нет однобуквенных слов"<<endl;
else
cout<<"Все однобуквенные слова про дублировались! Поздравляю!"<<endl;
while(!knil.Empty())
{
            out<<knil.Get()<<" ";
}
}
    out.close();
return0;
}
