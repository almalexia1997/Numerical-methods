#include <iostream>
#include <vector>
#include <string>
#include <fstream>
usingnamespace std;
 
ofstream out("output.txt");
 
template<class Item>
 
class list
{
struct Element
{
		  Item inf;
		  Element *next;
		  Element *prev;
		  Element(Item x):inf(x), next(0), prev(0)
{
}
};
	 Element *head;//указатель на начало списка
	 Element *tail;
int size;//количество элементов в нем
 
//возвращает указатель на элемент списка с номером index
	 Element *Find(int index)
{
if((index<1)||(index>size))//если индекс элемента списка находится вне диапазона
{
returnNULL;//возвращаем NULL
}
else//иначе
{
			  Element *cur = head;//устанавливаем указатель на начало списка
for(int i =1; i<index;++i)//и перемещаемся по списку
{
			 	cur = cur->next;//на элемент с номером index
}
return cur;//возвращаем указатель на требуемый элемент
}
}
public:
	 list():head(0), tail(0), size(0)//конструктор класса
{
}
	 ~list()//деструктор
{
while(!Empty())//пока список не пуст
{
		 	Remove(1);//удаляем первый элемент
}
}
 
bool Empty()//проверка пустоты
{
return head ==0;
}
 
int GetLength()//возвращает количество элементов в списке
{
return size;
}
	 Item Get(int index)//возвращает значение списка по его номеру
{
if((index<1)||(index>size))
{
return0;
}
else
{
			  Element *r = Find(index);
			  Item i = r->inf;
return i;
}
}
 
int Error()
{
return0;
}
 
void InsertLeft(Item data)
{
		 Element *newPtr =new Element(data);//создаем новый элемент
		 size = GetLength()+1;//увеличиваем размерность спика
if(Empty())
{
		 	head=tail=newPtr;
}
else
{
		 	tail->prev=newPtr;
}
}
 
void InsertRight(Item data)
{
		 Element *newPtr =new Element(data);//создаем новый элемент
		 size = GetLength()+1;//увеличиваем размерность спика
if(Empty())
{
		 	head=tail=newPtr;
}
else
{
			 tail->next=newPtr;
			 newPtr->prev=tail;
			 tail=newPtr;
}
}
 
void Remove(int index)//осуществляем удаление элемента из списка с номером index
{
if((index<1)||(index>size))
{
		 		Error();
}
else
{
			  Element *cur;//объявляем вспомогательный указатель
--size;//уменьшаем размерность списка
if(index ==1)//если удаляемый элемент первый
{
				  cur = head;//устанавливаем указатель на голову
				  head = head->next;//устанавливаем голову на второй элемент
}
else//иначе
{
				  Element *prev = Find(index -1);//объявляем указатель на предшествующий элемент
				  cur = prev->next;//устанавливаем указатель на удаляемый
				  prev->next = cur->next;//предшествующий устанавливаем на следующий за удаляемым
}
			  cur->next =NULL;//устанавливаем пустой указатель
delete cur;//удаляем сам указатель
}
}
 
void Print()
{
for(Element *cur=head; cur!=NULL; cur=cur->next)
{
		 	out<<cur->inf<<" ";
}
		 out<<endl;
}
 
void PrintBack()
{
for(Element *cur=tail; cur!=NULL; cur=cur->prev)
{
		 	out<<cur->inf<<" ";
}
		 out<<endl;
}
 
void doubleSingle()
{
for(Element *cur=head; cur!=NULL; cur=cur->next)
{
if(cur->inf.length()==1)
{
				 Element *newPtr =new Element(cur->inf);
				 newPtr->next=cur->next;
				 cur->next=newPtr;
				 newPtr->next->prev=newPtr;
				 newPtr->prev=cur;
				 cur=cur->next;
				 size++;
}
}
}
};
 
int main()
{
	setlocale(LC_ALL, "russian");
int n, h =0;
	list <string> link;
	string str;
cout<<"Задача: записать слова в файл при этом продублировать однобуквенные слова"<< endl;
cout<<"Сколько слов будет в списке?\nn=";
cin>> n;
for(int i =0; i<n;++i)
{
cout<<"str=";
cin>> str;
if(str.length()==1)
{
		 	h++;
}
		 link.InsertRight(str);
}
if(link.Empty())
{
cout<<"список пустой"<< endl;
}
else
{
		 link.doubleSingle(); //здесь крашится на последнем однобуквенном слове. надо исправить
if(h ==0)
cout<<"\nНет однобуквенных слов"<< endl;
else
cout<<"\nВсе однобуквенные слова про дублировались! Поздравляю!"<< endl;
		 link.Print();
		 link.PrintBack();
}
	out.close();
return0;
}
