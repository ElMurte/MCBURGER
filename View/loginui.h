#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>
class ControllerR;
#include <QLineEdit>
#include <QLabel>
class LoginUI : public QDialog{
    Q_OBJECT
private:
ControllerR*controller;
QLabel* usertext;
QLineEdit*username;
QLabel* userpass;
QLineEdit*password;
QPushButton*loginbtn;
public:
    explicit LoginUI(ControllerR*,QWidget *parent = nullptr);
public slots:
void CheckLog();
signals:
void Checklogin(LoginUI*,QString,QString);
};

#endif // LOGINUI_H
