#include <iostream>

#include "List.h"

using namespace std;

int main()
{
    List* list = new List();

    list->add(10);
    list->add(20);
    list->add(3);

    cout << list->get(0) << endl;
    cout << list->get(1) << endl;
    cout << list->get(2) << endl;

    cout << endl;

    cout << list->contains(10) << endl;
    cout << list->contains(1) << endl;
    cout << list->contains(3) << endl;

    //list->remove(20);
    list->removeById(0);

    cout << endl;

    cout << list->get(0) << endl;
    cout << list->get(1) << endl;

}
