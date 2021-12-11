#include <iostream>
#include "stdlib.h"
#include "Point.h"
#include "Figure.h"
#include "Fiveangle.h"
#include "List.h"
#include "Item.h"
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int c = 0;
    Fiveangle tmp;
    auto *lst=new List;
    //Array vector;
    while (1) {
        cout << "1-Add fiveangle " << "2-Print list " << "3-Get Item " << "4-Insert Item via index " << "5-Print size " << "6-Delete Item via index " << "7-Remove list " << "8-Exit" << '\n';
        cin >> c;
        if (c == 1) {
            cout << "Введите координаты вершин\n";
            cin >> tmp;
            cout << tmp;
            lst->AddTail(tmp);
            //lst->Print();
        }
        if (c == 2) {
            lst->Print();
        }
        if (c == 3 ){
            Item *item=lst->GetItem(1);
            cout << item->fiveangle;
        }
        if (c == 4) {
            lst->Insert(2);
            lst->Print();
        }
        if (c == 5 ){
            cout << "size=" << lst->size << "\n";
        }
        if (c == 6){
            cout << lst->size << "\n";
            lst->Del(lst->size);
            cout << lst->size << "\n";
        }
        if (c == 7 ){
            lst->DelAll();
        }

        if (c == 8) {
            return 0;
        }
    }
    return 0;
}
