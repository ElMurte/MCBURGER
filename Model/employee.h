#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <ctime>
#include <QJsonObject>
enum Role{cooker,cashier,manager};
class Employee{
private:
Role ruolo;
QString nome;
QString password;
unsigned short int old;
bool inprove;
double income;
public:
 Employee(Role r,QString nome="",QString password="",unsigned short int old=0,bool inprove=false,double income=0);
 virtual ~Employee()=default;
 virtual Employee* clone()const=0;
 virtual double Get_Income()const;
 virtual void readInfoFromJson(const QJsonObject &json);
 QString getNome() const;
 void setNome(const QString &value);
 QString getPassword() const;
 void setPassword(const QString &value);
 unsigned short getOld() const;
 void setOld(unsigned short value);
 bool getInprove() const;
 void setInprove(bool value);
 double getIncome() const;
 void setIncome(double value);
};

#endif // EMPLOYEE_H
