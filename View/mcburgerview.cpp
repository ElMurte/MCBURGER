#include "mcburgerview.h"
#include <Control/controller.h>

McBurgerView::McBurgerView(ControllerR *c, QWidget*parent):QWidget(parent),controller(c)
{
    connect(controller,SIGNAL(newData(const vector<Product*>&)),this, SLOT(updateFromData(const vector<Product*>&)));
}

