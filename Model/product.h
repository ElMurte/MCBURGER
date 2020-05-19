#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <QJsonObject>
using std::string;
enum Size{undefined,small,medium,big};
class Product{
private:
string nome;
string description;
unsigned short calories;
float price;
QString categorie;
public:
    Product( const QString& c);
    virtual ~Product()=default;
    virtual Product* clone()const=0;
    virtual void readInfoFromJson(const QJsonObject &json);
    /*GETTERS*/
    string Get_Nome()const;
    string Get_Description()const;
    QString Get_Categorie()const;
    unsigned short Get_Calories()const;
    float Get_Price()const;
    Size Get_Size()const;
    /*SETTERS*/
    void Set_Nome(const string&);
    void Set_Description(const string& );
    void Set_Calories(const unsigned short&);
    void SetPrice(const float&);
    void SetCategorie(QString);
    void SetSize(Size);


};

#endif // PRODUCT_H
