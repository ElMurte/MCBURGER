#include "manager.h"

Manager::Manager():Employee(Role::manager){

}

class Manager* Manager::clone() const{
    return new Manager(*this);
}
