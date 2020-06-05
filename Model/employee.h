#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <ctime>
using std::string;using std::ctime;using std::time_t;
class Employee{
private:
string nome;
char* datainizio;
unsigned short int old;
bool inprove;
double income;
public:
 Employee(string nome=0,char* datainizio=0,unsigned short int old=0,bool inprove=false,double income=0);
 virtual ~Employee()=default;
 virtual Employee* clone()const=0;
 virtual double Get_Income()const;
};

#endif // EMPLOYEE_H
