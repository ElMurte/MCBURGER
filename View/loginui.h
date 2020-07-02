#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>
class ControllerR;
#include <QLineEdit>
class LoginUI : public QDialog{
    Q_OBJECT
private:
ControllerR*controller;
QLineEdit*username;
QLineEdit*password;
QPushButton*loginbtn;
public:
    explicit LoginUI(ControllerR*,QWidget *parent = nullptr);
public slots:
void CheckLog();
signals:
void Checklogin(QString,QString);
};

#endif // LOGINUI_H
