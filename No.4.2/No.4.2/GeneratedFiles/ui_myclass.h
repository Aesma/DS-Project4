/********************************************************************************
** Form generated from reading UI file 'myclass.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLASS_H
#define UI_MYCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MyClassClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *currentButton;
    QPushButton *doButton;
    QPushButton *newButton;

    void setupUi(QDialog *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QStringLiteral("MyClassClass"));
        MyClassClass->resize(222, 118);
        gridLayout = new QGridLayout(MyClassClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        currentButton = new QPushButton(MyClassClass);
        currentButton->setObjectName(QStringLiteral("currentButton"));

        verticalLayout->addWidget(currentButton);

        doButton = new QPushButton(MyClassClass);
        doButton->setObjectName(QStringLiteral("doButton"));

        verticalLayout->addWidget(doButton);

        newButton = new QPushButton(MyClassClass);
        newButton->setObjectName(QStringLiteral("newButton"));

        verticalLayout->addWidget(newButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MyClassClass);

        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QDialog *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "MyClass", 0));
        currentButton->setText(QApplication::translate("MyClassClass", "\346\211\223\345\274\200\345\210\235\345\247\213\345\233\276", 0));
        doButton->setText(QApplication::translate("MyClassClass", "\345\244\204\347\220\206\351\201\223\350\267\257", 0));
        newButton->setText(QApplication::translate("MyClassClass", "\346\211\223\345\274\200\346\226\260\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H
