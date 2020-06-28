#include "uigestioneordini.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
UIGestioneOrdini::UIGestioneOrdini(QWidget*parent):QDialog(parent),inprep(new QWidget(this)),pronti(new QWidget(this)){
setLayout(new QHBoxLayout);
inprep->setLayout(new QVBoxLayout);
pronti->setLayout(new QVBoxLayout);
inprep->layout()->addWidget(new QLabel("IN PREPARAZIONE"));
pronti->layout()->addWidget(new QLabel("PRONTI"));
layout()->addWidget(inprep);
layout()->addWidget(pronti);
//itemtabella con bottoni
QFile file("Resources/style/style.css");
file.open(QFile::ReadOnly);
QString filesheet=QLatin1String(file.readAll());
setStyleSheet(filesheet);
}
void UIGestioneOrdini::showGestOrd(){
    open();
}

void UIGestioneOrdini::addorder(unsigned int i){
    inprep->layout()->addWidget(new Orditem(i));
}


