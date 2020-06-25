QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Control/controller.cpp \
    Model/burger.cpp \
    Model/cashier.cpp \
    Model/cooker.cpp \
    Model/database.cpp \
    Model/drink.cpp \
    Model/employee.cpp \
    Model/manager.cpp \
    Model/menu.cpp \
    Model/order.cpp \
    Model/patatine.cpp \
    Model/product.cpp \
    Model/restorant.cpp \
    Model/sweet.cpp \
    View/addrembuttonscart.cpp \
    View/cart.cpp \
    View/clientwindow.cpp \
    View/mcburgerview.cpp \
    View/menubutton.cpp \
    View/productbutton.cpp \
    View/windowaddproduct.cpp \
    main.cpp \

HEADERS += \
    Control/controller.h \
    Model/Dlist.h \
    Model/burger.h \
    Model/cashier.h \
    Model/cooker.h \
    Model/database.h \
    Model/drink.h \
    Model/employee.h \
    Model/manager.h \
    Model/menu.h \
    Model/order.h \
    Model/patatine.h \
    Model/product.h \
    Model/restorant.h \ \
    Model/sweet.h \
    View/addrembuttonscart.h \
    View/cart.h \
    View/clientwindow.h \
    View/mcburgerview.h \
    View/menubutton.h \
    View/productbutton.h \
    View/windowaddproduct.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DESTDIR = $$PWD
DISTFILES += \
    Database/Employees.json \
    Database/Products.json \
    Resources/images/Burger/bIg-mc.png \
    Resources/images/Burger/chicken-burger.png \
    Resources/images/Burger/hamburger.png \
    Resources/images/Caffe/cappuccino.png \
    Resources/images/Drink/coca-cola.png \
    Resources/images/Drink/fanta.png \
    Resources/images/Icons/burgericon.ico \
    Resources/images/Icons/burgericon.png \
    Resources/images/Patatine/patatine-classiche-medie.png \
    Resources/images/Sweet/croissant-vuoto.png \
    Resources/images/burgericon.png \
    Resources/style/style.css
