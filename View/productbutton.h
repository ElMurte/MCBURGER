#ifndef PRODUCTBUTTON_H
#define PRODUCTBUTTON_H
#include <QAbstractButton>
#include <QToolButton>
class ProductButton : public QToolButton{
Q_OBJECT
signals:
void clickedCell(const QString&);
void clickedCell(const int&);
private:
    QString nome;
private slots:
void fakehandleclick();
public:
    ProductButton(const QString&,const QString& label,const QString& sicona, QWidget *parent=0);
};

#endif // PRODUCTBUTTON_H
