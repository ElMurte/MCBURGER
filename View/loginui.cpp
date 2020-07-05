#include "loginui.h"
#include "Control/controller.h"
#include <QPushButton>
LoginUI::LoginUI(ControllerR*cc, QWidget *parent)
    : QDialog(parent),controller(cc),usertext(new QLabel("username:")),username(new QLineEdit(this)),userpass(new QLabel("password:")),password(new QLineEdit(this)),loginbtn(new QPushButton("LOGIN",this))
{
setLayout(new QVBoxLayout);setObjectName("loginw");
layout()->addWidget(usertext);
layout()->addWidget(username);
layout()->addWidget(userpass);
layout()->addWidget(password);
layout()->addWidget(loginbtn);
connect(loginbtn,SIGNAL(clicked()),this,SLOT(CheckLog()));
connect(this,SIGNAL(Checklogin(LoginUI*,QString,QString)),controller,SLOT(Checklogin(LoginUI*,QString,QString)));
show();
}

void LoginUI::CheckLog(){
emit Checklogin(this,username->text(),password->text());
}
