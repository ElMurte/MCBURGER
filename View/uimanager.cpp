#include "View/uimanager.h"
#include "View/menubutton.h"
#include "Model/manager.h"
#include "View/uigestioneordini.h"
#include "View/orditem.h"
#include "productbutton.h"
#include <QtDebug>
UIManager::UIManager(ControllerR *c,Manager* man,QWidget*parent):ClientWindow(c,man,parent),manager(man)
{
    setParent(parent);//altre azioni manager
    MenuButton* cucinabtn=new MenuButton("",0,"","Resources/images/Icons/cookroom-icon.png");cucinabtn->setObjectName("btnlay");
    connect(cucinabtn,SIGNAL(clicked()),this,SLOT(showUICucina()));
    topmenuwidget->layout()->addWidget(cucinabtn);

   /* QList<ProductButton*>ql = UI->parent()->findChildren<ProductButton*>("productbutton");
    for(auto it=ql.begin();it!=ql.end();it++)
        connect((*it),SIGNAL(rightClicked()),(*it),SLOT(onrightClick()));*/
}

void UIManager::showUICucina(){
    cucina->open();
}

UICuoco *UIManager::getcucina(){
return cucina;
}
