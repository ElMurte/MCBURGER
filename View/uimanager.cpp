#include "View/uimanager.h"
#include "View/menubutton.h"
#include "Model/manager.h"
#include "View/uigestioneordini.h"
#include "View/orditem.h"
#include "productbutton.h"
UIManager::UIManager(ControllerR *c,Manager* man,QWidget*parent):ClientWindow(c,man,parent),manager(man)
{
    setParent(parent);//altre azioni manager
    MenuButton* cucinabtn=new MenuButton("",0,"","Resources/images/Icons/cookroom-icon.png");cucinabtn->setObjectName("btnlay");
    connect(cucinabtn,SIGNAL(clicked()),this,SLOT(showUICucina()));
    topmenuwidget->layout()->addWidget(cucinabtn);
    connect(this,SIGNAL(getcucina(Cooker*)),controller,SLOT(CucinaAccesa(Cooker*)));
}

void UIManager::showUICucina(){

    emit getcucina(manager);
}
