#include "restorant.h"
Restorant::Restorant(){
    QFile file("Database/Products.json");/*C:\Users\elvis\Desktop\P2\PROGETTO\MCBURGER\Database*/
    file.open(QIODevice::ReadOnly);
    QByteArray rawData=file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(rawData));
    read<Product,Burger>(doc.object(),"Panino",products);
    read<Product,Patatine>(doc.object(),"Patatine",products);
}
/*utility function*/
void Restorant::printproducts(){
for(auto it=products.begin();it!=products.end();it++)
   cout<<(*it)->Get_Nome()<<endl;
}
template <class P,class C>
void Restorant::readV(const QJsonArray &json, vector<P*>&v){
    for (int Index = 0; Index < json.size(); ++Index) {
        QJsonObject paninoObj = json[Index].toObject();
        P* prod=new C();prod->read(paninoObj);
        v.push_back(prod->clone());
    }
}


template<class P,class C>
void Restorant::read(const QJsonObject &json, const QString & s, vector<P*>&v){
    if (json.contains(s) && json[s].isArray()) {
        QJsonArray paninoArray = json[s].toArray();
        readV<P,C>(paninoArray,v);
    }
}

void Restorant::write(QJsonObject &json) const{

}
