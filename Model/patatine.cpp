#include "patatine.h"

Patatine::Patatine(Size s):size(s){}
Patatine* Patatine::clone() const{//ovverride from Product
return new Patatine(*this);
}
