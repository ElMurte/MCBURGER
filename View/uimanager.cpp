#include "View/uimanager.h"
#include "View/menubutton.h"

UIManager::UIManager(ControllerR *c,QWidget*parent):ClientWindow(c,parent),cucina(new UICuoco(c,this))
{
    setParent(parent);
    MenuButton* cucinabtn=new MenuButton("",0,"","Resources/images/Icons/cookroom-icon.png");
    connect(cucinabtn,SIGNAL(clicked()),this,SLOT(showUICucina()));
    topmenuwidget->layout()->addWidget(cucinabtn);
}

void UIManager::showUICucina(){
    cucina->open();
}

UICuoco *UIManager::getcucina(){
return cucina;
}
