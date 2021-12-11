#include "Item.h"
#include <iostream>

Item::Item(const Fiveangle& fiveangle) {
    this->fiveangle = fiveangle;
    this->next = NULL;
    this->prev = NULL;
    std::cout << "List item1: created" << std::endl;
}

Item::Item(const Item& orig) {
    this->fiveangle = orig.fiveangle;
    this->next = orig.next;
    this->prev = orig.prev;
    std::cout << "List item2: copied" << std::endl;
}

Fiveangle Item::GetFiveangle() {
    return this->fiveangle;
}


Item* Item::SetNext(Item* next) {
    Item* old = this->next;
    this->next = next;
    return old;
}

Item* Item::GetNext() {
    return this->next;
}

Item::~Item() {
    std::cout << "List item: deleted" << std::endl;
    delete next;
}

std::ostream& operator<<(std::ostream& os, const Item& obj) {
    os << "[" << obj.fiveangle << "]" << std::endl;
    return os;
}

