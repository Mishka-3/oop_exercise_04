#ifndef ITEM_H
#define ITEM_H

#include "Fiveangle.h"
class Item {
    //private:
public:
    Fiveangle fiveangle;
    Item* next;
    Item* prev;
public:
    Item(const Fiveangle& fiveangle);
    Item(const Item& orig);
    friend std::ostream& operator<<(std::ostream& os, const Item& obj);
    Item* SetNext(Item* next);
    Item* GetNext();
    virtual ~Item();
    Fiveangle GetFiveangle();
};
#endif  	/* ITEM_H */

#pragma once
