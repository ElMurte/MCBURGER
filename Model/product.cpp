#include "product.h"

unsigned int Product::get_Quantita() const{
    return quantita;
}

void Product::set_Quantita(unsigned int value){
    quantita = value;
}

bool Product::getDisponibile() const
{
    return disponibile;
}

void Product::setDisponibile(bool value)
{
    disponibile = value;
}

Product::Product(const QString &c):categorie(c){
    quantita=1;
}

bool Product::operator==(const Product &p){
    return(nome==p.nome && p.size==size && p.calories==calories && p.price==price);
}
QString Product::Get_Nome() const{
    return nome;
}

QString Product::Get_Description()const{
    return description;
}

unsigned short Product::Get_Calories() const{
    return calories;
}

float Product::Get_Price()const{
    return price;
}

Size Product::Get_Size() const{
    return size;
}

QString Product::Get_Icon() const{
    return icon;
}

void Product::Set_Nome(const QString& s){
    nome=s;
}

void Product::Set_Description(const QString& dsc){
    description=dsc;
}

void Product::Set_Calories(const unsigned short & calor){
    calories=calor;
}

void Product::SetPrice(const float & prc){
    price=prc;
}

void Product::SetSize(Size s)
{
    size=s;
}

QString Product::Get_Categorie() const
{
    return categorie;
}

void Product::readInfoFromJson(const QJsonObject &json){
        nome=json["name"].toString().toUtf8();
        description=json["description"].toString().toUtf8();
        calories=json["calories"].toDouble();
        price=json["price"].toDouble();
        categorie=json["categories"].toString().toLower();
        size=Size(qRound(json["size"].toDouble()));
        icon=json["icon"].toString();
        disponibile=json["disponibile"].toBool();
}

void Product::writeInfoInJson(QJsonObject &json) const{
        QString n(*(nome.begin())); QString d(*(description.begin()));
        json["name"]=n;
        json["description"]=d;
        json["calories"]=calories;
        json["price"]=price;
        json["categories"]=categorie;
        json["size"]=size;
}

