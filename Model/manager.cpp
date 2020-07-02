#include "manager.h"

Manager::Manager():Employee(Role::Manager)
{

}

class Manager* Manager::clone() const{
    return new Manager(*this);
}
