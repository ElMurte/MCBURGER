#include "database.h"
QJsonObject Database::JsonreadFile(const QString &qs)
{
    QFile f(qs);f.open(QIODevice::ReadOnly);QByteArray rawData=f.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(rawData));
    return QJsonObject (doc.object());
}
QString Database::dirproducts="Database/Products.json";
QString Database::diremployees="Database/Employees.json";
QJsonObject Database::docprod=JsonreadFile(dirproducts);
QJsonObject Database::docempl=JsonreadFile(diremployees);


void Database::write(QJsonObject &json) const{

}


