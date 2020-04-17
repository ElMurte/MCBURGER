#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using std::string;

class Product
{
private:
string nome;
string description;
float price;
public:
    Product();
    virtual Product* clone()const=0;
    string Get_Nome()const;
    string Get_Description()const;
    float Get_Price()const;
};

#endif // PRODUCT_H
