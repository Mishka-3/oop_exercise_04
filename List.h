#include <iostream>
#include "Fiveangle.h"
#include <ctime>
#include "Item.h"

class List {
public:
    int size;
    Item *head;
    Item *tail;
public:
    List();
    List(const List& orig);
    ~List();

    void DelAll();
    void Del(size_t index);
    void Insert(int pos);
    void AddHead(Fiveangle& fiveangle);

    void AddTail(Fiveangle& fiveangle);
    Item* GetItem(int pos);
    void Print();
};
