#ifndef ORDER_H
#define ORDER_H
#include "Model/menu.h"
#include <vector>
using std::vector;
enum State{inpreparation,ready};

class Order{
private:
    vector<Menu*> menuord;
    vector<Product*> prdsord;
    State statetype;
    unsigned short numordine;

public:
    unsigned int Get_NumOrder();
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
