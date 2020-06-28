#ifndef ORDITEM_H
#define ORDITEM_H

#include <QWidget>

class Orditem:public QWidget{
    Q_OBJECT
private:
    unsigned int nord;
public:
    Orditem(unsigned int idord,QWidget*parent=nullptr);
};

#endif // ORDITEM_H
