#ifndef ORDER_H
#define ORDER_H
#include "Model/menu.h"
enum Payment{notselected,carta,pagoincassa};

class Order{
private:
    Dlist<Menu*> menuord;
    Dlist<Product*> prdsord;
    Payment paytype;
    double totalbill;
    unsigned short numtav;
    unsigned int numord=0;
public:
    double Gettotale()const;
    unsigned short SetNumTav();
    Order(Menu*,Payment=notselected);
    Order(Product*,Payment=notselected);
    Order(Menu*,Product*,Payment=notselected);
    unsigned int idord;
};
#endif // ORDER_H
