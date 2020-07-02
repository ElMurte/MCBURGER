#ifndef MENU_H
#define MENU_H
#include <vector>
using std::vector;
#include"product.h"
class Menu{
private:
    vector<Product*>products;
    QString nome;
    Size size;
    float price;
public:
    Menu(Product* p=0,Size=undefined);
    float Get_Price();
    void Set_Price();
    Menu *clone()const;
};

#endif // MENU_H
