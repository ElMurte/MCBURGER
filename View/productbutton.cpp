#include "productbutton.h"
#include <QtDebug>
#include "Model/product.h"
#include "View/windowaddproduct.h"
ProductButton::ProductButton(const QString& cat,const QString& label,const QString& sicona, QWidget *parent) : QToolButton(parent),nome(cat){
    this->setIcon(QIcon(sicona));
    setIconSize(QSize(190,120));
    setText(label);
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(this,SIGNAL(clicked()),this,SLOT(fakehandleclick()));
}
void ProductButton::fakehandleclick(){
emit clickedCell(nome);
}
