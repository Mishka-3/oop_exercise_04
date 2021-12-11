#include "iostream"
#include "stdlib.h"
#include "List.h"
#include "Point.h"
#include "Figure.h"
#include "Fiveangle.h"
#include "Item.h"

using namespace std;

List::List()
{
      head= NULL;
      tail= NULL;
      size=0;
      std::cout << "List1 created" << std::endl;
}
List::List(const List& orig) {
      size= orig.size;
      head= orig.head;
      tail= orig.tail;
      std::cout << "List2 created" << std::endl;
}
List::~List()
{
   // Удаляем все элементы
   DelAll();
}


void List::DelAll()
{
   // Пока остаются элементы, удаляем по одному с головы
   while(size != 0)
      Del(1);
}


void List::Del(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
       cout << "Input position: ";
       cin >> pos;
   }
   // Позиция от 1 до size?
   if(pos < 1 || pos > size)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }

   // Счетчик
   int i = 1;

   Item * Del = head;

   while(i < pos)
   {
      // Доходим до элемента,
      // который удаляется
      Del = Del->next;
      i++;
   }

   // Доходим до элемента,
   // который предшествует удаляемому
   Item * PrevDel = Del->prev;
   // Доходим до элемента, который следует за удаляемым
   Item * AfterDel = Del->next;

   // Если удаляем не голову
   if(PrevDel != 0 && size != 1)
      PrevDel->next = AfterDel;
   // Если удаляем не хвост
    if(AfterDel != 0 && size != 1)
      AfterDel->prev = PrevDel;

   // Удаляются крайние?
   if(pos == 1)
       head = AfterDel;
   if(pos == size)
       tail = PrevDel;

   // Удаление элемента
   delete Del;

   size--;
}

void List::AddHead(Fiveangle& fiveangle)
{
   // новый элемент
   Item * temp = new Item(fiveangle);

   // Предыдущего нет
   temp->prev = 0;
   // Заполняем данные
   temp->fiveangle = fiveangle;
   // Следующий - бывшая голова
   temp->next = head;

   // Если элементы есть?
   if(head != 0)
      head->prev = temp;

   // Если элемент первый, то он одновременно и голова и хвост
   if(size == 0)
      head = tail = temp;
   else
      // иначе новый элемент - головной
      head = temp;

   size++;
}

void List::AddTail(Fiveangle& fiveangle)
{
   // Создаем новый элемент
   Item * temp = new Item(fiveangle);
   // Следующего нет
   temp->next = NULL;
   // Заполняем данные
   temp->fiveangle = fiveangle;
   // Предыдущий - бывший хвост
   temp->prev = tail;

   // Если элементы есть?
   if(tail != NULL)
      tail->next = temp;

   // Если элемент первый, то он одновременно и голова и хвост
   if(size == 0)
      head = tail = temp;
   else
      // иначе новый элемент - хвостовой
   tail = temp;

   size++;

   cout << "size=" << size << "\n";
}

void List::Insert(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
      cout << "Input position: ";
      cin >> pos;
   }

  // Позиция от 1 до Count?
   if(pos < 1 || pos > size + 1)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }

   // Если вставка в конец списка
   if(pos == size + 1)
   {
      Fiveangle tmp;
      cout << "Введите координаты вершин\n";
      cin >> tmp;
      // Добавление в конец списка
      AddTail(tmp);
      return;
   }
   else if(pos == 1)
   {
      // Вставляемые данные
       Fiveangle tmp;
       cout << "Введите координаты вершин\n";
       cin >> tmp;
      // Добавление в начало списка
      AddHead(tmp);
      return;
   }

   // Счетчик
   int i = 1;

   // Отсчитываем от головы n - 1 элементов
   Item * Ins = head;

   while(i < pos)
   {
      // Доходим до элемента,
      // перед которым вставляемся
      Ins = Ins->next;
      i++;
   }

   // Доходим до элемента,
   // который предшествует
   Item * PrevIns = Ins->prev;

   // Создаем новый элемент

   // Вставляемые данные
    Fiveangle tmp;
    cout << "Введите координаты вершин\n";
    cin >> tmp;
    Item * temp = new Item(tmp);


   // настройка связей
   if(PrevIns != 0 && size != 1)
      PrevIns->next = temp;

   temp->next = Ins;
   temp->prev = PrevIns;
   Ins->prev = temp;

   size++;
}


void List::Print()
{
   // Если в списке присутствуют элементы, то пробегаем по нему
   // и печатаем элементы, начиная с головного
   if(size != 0)
   {
      Item * temp = head;
      while(temp->next != 0)
      {
          cout << temp->fiveangle;
          temp = temp->next;
      }

      cout << temp->fiveangle << "\n";
   }
}

/*std::ostream& operator<<(std::ostream& os, const List& list) {

    Item *item = list.head;
    while(item!=NULL)
    {
        os << item->fiveangle;
        item = item->GetNext();
    }
    return os;
}*/
std::ostream& operator<<(std::ostream& os, const List& list) {
    Item* item = list.head;
    while (item != NULL)
    {
        os << *item;
        item = item->GetNext();
    }
    return os;
}

/*ostream& operator<<(ostream& os, const List& list) {
    os.precision(3);
    Item* item = list.head;
    auto s = new double[list.size];
    for (int i = 0; i < list.size; ++i) {
        s[i] = item->GetFiveangle().get_Area();
        item = item->GetNext();
    }
    for (int i = (int) list.size - 1; i >= 0; --i) {
        os << "=> " << s[i] << " ";
    }
    return os;
}*/

Item* List::GetItem(int pos)
{
   Item *temp = head;

   // Позиция от 1 до size?
   if(pos < 1 || pos > size)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return 0;
   }

   int i = 1;
   // Ищем нужный нам элемент
   while(i < pos && temp != 0)
   {
      temp = temp->next;
      i++;
   }

   if(temp == 0)
      return 0;
   else
      return temp;
}

