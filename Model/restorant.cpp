#include "restorant.h"
Restorant::Restorant(){
    QFile file("Database/Products.json");/*C:\Users\elvis\Desktop\P2\PROGETTO\MCBURGER\Database*/
    file.open(QIODevice::ReadOnly);
    QByteArray rawData=file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(rawData));
    read(doc.object());
}
/*utility function*/
void Restorant::printproducts(){
for(auto it=products.begin();it!=products.end();it++)
   cout<<(*it)->Get_Nome()<<endl;
}
template <class C>
void Restorant::readV(const QJsonArray &json){
    for (int Index = 0; Index < json.size(); ++Index) {
        QJsonObject paninoObj = json[Index].toObject();
        Product* prod=new C();prod->read(paninoObj);
        products.push_back(prod->clone());
    }
}

void Restorant::read(const QJsonObject &json){/*...Query container,virtual read?*/
        if (json.contains("Panino") && json["Panino"].isArray()) {
            QJsonArray paninoArray = json["Panino"].toArray();
            readV<Burger>(paninoArray);
        }
       /* if (json.contains("Bibita") && json["Bibita"].isArray()) {
            QJsonArray bibitaArray = json["Bibita"].toArray();
            readArrey(bibitaArray);
        }*/
        if (json.contains("Patatine") && json["Patatine"].isArray()) {
            QJsonArray patatineArray = json["Patatine"].toArray();
            readV<Patatine>(patatineArray);
        }
       /* if (json.contains("Dolce") && json["Dolce"].isArray()) {
            QJsonArray dolceArray = json["Dolce"].toArray();
            readArrey(dolceArray);
        }
        if (json.contains("Caffe") && json["Caffe"].isArray()) {
            QJsonArray caffeArray = json["Caffe"].toArray();
            readArrey(caffeArray);
        }*/
}
template<class C>
void Restorant::read(const QJsonObject &json, const QString & s){
    if (json.contains(s) && json[s].isArray()) {
        QJsonArray paninoArray = json[s].toArray();
        readV<C>(paninoArray);
    }
}

void Restorant::write(QJsonObject &json) const{

}
