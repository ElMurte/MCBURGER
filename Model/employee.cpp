#include "employee.h"

Employee::Employee(string nome,char* datainizio,unsigned short int old,bool inprove,double income):nome(nome),old(old),inprove(inprove),income(income){

}
double Employee::Get_Income()const{
    return income;
}
