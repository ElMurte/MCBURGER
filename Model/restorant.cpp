#include "restorant.h"
Restorant::Restorant(){
    QFile file("Database/Products.json");/*C:\Users\elvis\Desktop\P2\PROGETTO\MCBURGER\Database*/
    file.open(QIODevice::ReadOnly);
    QByteArray rawData=file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(rawData));
    read(doc.object());
}

void Restorant::read(const QJsonObject &json){
        QJsonArray panino; QJsonArray bibita;/*...*/
        if (json.contains("Product") && json["Product"].isArray()) {
            QJsonArray paninoArray = json["Product"].toArray();
            for (int Index = 0; Index < paninoArray.size(); ++Index) {
                QJsonObject paninoObj = paninoArray[Index].toObject();
                Product* prod=new Burger();prod->read(paninoObj);
                products.push_back(prod);
            }
        }
}

void Restorant::write(QJsonObject &json) const{

}
