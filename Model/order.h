#ifndef ORDER_H
#define ORDER_H
#include "Model/menu.h"
enum State{notsetted,payed,inpreparation,ready};

class Order{
private:
    Dlist<Menu*> menuord;
    Dlist<Product*> prdsord;
    State paytype;
    double totalbill;
    unsigned short numtav;
    static unsigned int idord;
public:
    double Gettotale()const;
    unsigned short SetNumTav();
    Order(State=notsetted);
};
#endif // ORDER_H
