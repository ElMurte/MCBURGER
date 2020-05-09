#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <QJsonObject>
using std::string;
enum Size{undefined,small,medium,big};
class Product{
protected:
string nome;
string description;
unsigned short calories;
float price;
public:
    Product(string="not defined",string="not defined",unsigned short=0,float=0);
    virtual ~Product()=default;
    virtual Product* clone()const=0;
    string Get_Nome()const;
    string Get_Description()const;
    unsigned short Get_Calories()const;
    float Get_Price()const;
    void Set_Nome(const string&);
    void Set_Description(const string& );
    void Set_Calories(const unsigned short&);
    void SetPrice(const float&);
    void read(const QJsonObject &json);

};

#endif // PRODUCT_H
