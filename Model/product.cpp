#include "product.h"

Product::Product(){}

std::string Product::Get_Nome() const{
return nome;
}

std::string Product::Get_Description()const{
    return description;
}

unsigned short Product::Get_Calories() const{
    return calories;
}

float Product::Get_Price()const{
    return price;
}

void Product::Set_Nome(const string& s){
    nome=s;
}

void Product::Set_Description(const string& dsc){
    description=dsc;
}

void Product::Set_Calories(const unsigned short & calor){
    calories=calor;
}

void Product::SetPrice(const float & prc){
    price=prc;
}

