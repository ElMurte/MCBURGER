#include "View/uimanager.h"
#include "View/menubutton.h"
#include "Model/manager.h"
UIManager::UIManager(ControllerR *c,class Manager* man,QWidget*parent):ClientWindow(c,parent),manager(man),cucina(new UICuoco(c,manager,this))
{
    setParent(parent);
    MenuButton* cucinabtn=new MenuButton("",0,"","Resources/images/Icons/cookroom-icon.png");cucinabtn->setObjectName("btnlay");
    connect(cucinabtn,SIGNAL(clicked()),this,SLOT(showUICucina()));
    topmenuwidget->layout()->addWidget(cucinabtn);
}

void UIManager::showUICucina(){
    cucina->open();
}

UICuoco *UIManager::getcucina(){
return cucina;
}
