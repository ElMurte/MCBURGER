#ifndef MENU_H
#define MENU_H
#include <string>
using std::string;
#include"product.h"
#include "Dlist.h"
enum Size{undefined,small,medium,big};
class Menu{
private:
    Dlist<Product*>products;
    string nome;
    Size size;
    float price;
public:
    Menu(Product* p=0,Size=undefined);
    float Get_Menu_Price();
};

#endif // MENU_H
