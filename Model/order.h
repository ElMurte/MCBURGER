#ifndef ORDER_H
#define ORDER_H
#include "Model/menu.h"
#include <vector>
using std::vector;
enum State{notsetted,payed,inpreparation,ready};

class Order{
private:
    vector<Menu*> menuord;
    vector<Product*> prdsord;
    State statetype;
    unsigned short numtav;

public:
    static unsigned int idord;
    Order(vector<Product*>&);
    double Gettotale()const;
    void addProd(Product*);
    void removeProd(Product*);
    unsigned short SetNumTav();
    void setState(State);
    void chiudiOrdine();
};
#endif // ORDER_H
