#include "loginui.h"
#include "Control/controller.h"
#include <QPushButton>
LoginUI::LoginUI(ControllerR*cc, QWidget *parent)
    : QDialog(parent),controller(cc),username(new QLineEdit("username",this)),password(new QLineEdit("password",this)),loginbtn(new QPushButton("LOGIN",this))
{
setLayout(new QVBoxLayout);
layout()->addWidget(username);
layout()->addWidget(password);
layout()->addWidget(loginbtn);
connect(loginbtn,SIGNAL(clicked()),this,SLOT(CheckLog()));
connect(loginbtn,SIGNAL(Checklogin(QString,QString)),controller,SLOT(Checklogin(QString,QString)));
show();
}

void LoginUI::CheckLog(){
emit Checklogin(username->text(),password->text());
}
