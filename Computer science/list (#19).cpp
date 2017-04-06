#include <iostream>
#include <vector>
#include <string>
#include <fstream>
usingnamespace std;
 
template<class Item>
 
class list
{
struct Element
{
		Item inf;
		Element *next;
		Element(Item x):inf(x), next(0)
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
void Insert(int index, Item data)//осуществляет вставку элемента со значением data в позицию index
{
if((index<1)||(index>size +1))
{
	 Error();
}
else
{
		  Element *newPtr =new Element(data);//создаем новый элемент
		  size = GetLength()+1;//увеличиваем размерность спика
if(index ==1)//если вставку производим в позицию 1
{
			  newPtr->next = head;//то указатель устанавливаем на голову
			  head = newPtr;//голова равна добавленному элементу
}
else//иначе
{
			  Element *prev = Find(index -1);//указатель на предшествующий элемент
			  newPtr->next = prev->next;//устанавливаем указатель на следующий за предшествующим
			  prev->next = newPtr;//устанавливаем указатель предыдущего на новый элемент
}
if(index==size)
		  	tail=newPtr;
}
}
void Insertback(Item data)
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
void doubleSingle()
{
for(Element *cur=head; cur!=NULL; cur=cur->next)
{
if(cur->inf.length()==1)
{
				 Element *newPtr =new Element(cur->inf);
				 newPtr->next=cur->next;
				 cur->next=newPtr;
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
	string str, rts;
	ofstream out("output.txt");
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
		 link.Insertback(str);
}
if(link.Empty())
{
cout<<"список пустой"<< endl;
}
else
{
	link.doubleSingle();
if(h ==0)
cout<<"\nНет однобуквенных слов"<< endl;
else
cout<<"\nВсе однобуквенные слова про дублировались! Поздравляю!"<< endl;
for(int i =1; i <= link.GetLength();++i)
		out << link.Get(i)<<" ";
}
	out.close();
return0;
}
