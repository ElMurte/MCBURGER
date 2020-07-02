#ifndef PRODUCT_H
#define PRODUCT_H
#include <QJsonObject>
enum Size{undefined,small,medium,big};
class Product{
private:
QString nome;
QString description;
unsigned short calories;
float price;
unsigned int quantita;
QString categorie;
Size size;
QString icon;
bool disponibile;
public:
    Product( const QString& c);
    virtual ~Product()=default;
    virtual Product* clone()const=0;
    virtual void readInfoFromJson(const QJsonObject &json);
    virtual void writeInfoInJson(QJsonObject &json)const;
    /*GETTERS*/
    QString Get_Nome()const;
    QString Get_Description()const;
    QString Get_Categorie()const;
    unsigned short Get_Calories()const;
    float Get_Price()const;
    Size Get_Size()const;
    QString Get_Icon()const;
    unsigned int get_Quantita() const;
    /*SETTERS*/
    void Set_Nome(const QString&);
    void Set_Description(const QString& );
    void Set_Calories(const unsigned short&);
    void SetPrice(const float&);
    void SetCategorie(QString);
    void SetSize(Size);
    void set_Quantita(unsigned int value);
    virtual bool isEqual(Product*)const;
    bool getDisponibile() const;
    void setDisponibile(bool value);
};

#endif // PRODUCT_H
