#include "employee.h"

QString Employee::getNome() const
{
    return nome;
}

void Employee::setNome(const QString &value)
{
    nome = value;
}

QString Employee::getPassword() const
{
    return password;
}

void Employee::setPassword(const QString &value)
{
    password = value;
}

unsigned short Employee::getOld() const
{
    return old;
}

void Employee::setOld(unsigned short value)
{
    old = value;
}

bool Employee::getInprove() const
{
    return inprove;
}

void Employee::setInprove(bool value)
{
    inprove = value;
}

double Employee::getIncome() const
{
    return income;
}

void Employee::setIncome(double value)
{
    income = value;
}

Role Employee::getRuolo() const{
    return ruolo;
}

void Employee::setRuolo(const Role &value){
    ruolo = value;
}

Employee::Employee(Role r, QString nome, QString pass, unsigned short int old, bool inprove, double income)
    :ruolo(r),nome(nome),password(pass),old(old),inprove(inprove),income(income)
{

}
double Employee::Get_Income()const{
    return income;
}

void Employee::readInfoFromJson(const QJsonObject &json){
    ruolo=Role(qRound(json["size"].toDouble()));
    nome=json["username"].toString();
    password=json["password"].toString();
    old=json["old"].toInt();
    inprove=json["inprove"].toBool();
    income=json["income"].toInt();
}
