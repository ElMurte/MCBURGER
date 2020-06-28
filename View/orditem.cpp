#include "orditem.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
Orditem::Orditem(unsigned int idord,QWidget*parent):QWidget(parent),nord(idord){//controller?
setLayout(new QHBoxLayout);setObjectName("orditem");
layout()->addWidget(new QLabel(QString::number(idord)));
QPushButton*showord=new QPushButton("show");showord->setObjectName("ordbtn");
QPushButton*confirmord=new QPushButton("confirm");confirmord->setObjectName("ordbtn");
QPushButton*cancelord=new QPushButton("cancel");cancelord->setObjectName("ordbtn");
layout()->addWidget(showord);
layout()->addWidget(confirmord);
layout()->addWidget(cancelord);
}
