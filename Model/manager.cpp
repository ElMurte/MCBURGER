#include "manager.h"

Manager::Manager()
{

}

Manager *Manager::clone() const{
    return new Manager(*this);
}
