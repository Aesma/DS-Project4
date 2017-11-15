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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClassClass
{
public:
    QGridLayout *gridLayout_6;
    QGroupBox *firstBox;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *vertexLine;
    QPushButton *vertexButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ver2Line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *ver3Line;
    QPushButton *edgeButton;
    QPushButton *showButton;
    QGroupBox *secondBox;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *begVerLine;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *dfsButton;
    QPushButton *bfsButton;
    QLineEdit *searchLine;

    void setupUi(QWidget *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QStringLiteral("MyClassClass"));
        MyClassClass->resize(300, 347);
        gridLayout_6 = new QGridLayout(MyClassClass);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        firstBox = new QGroupBox(MyClassClass);
        firstBox->setObjectName(QStringLiteral("firstBox"));
        gridLayout_4 = new QGridLayout(firstBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(firstBox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label);

        vertexLine = new QLineEdit(groupBox);
        vertexLine->setObjectName(QStringLiteral("vertexLine"));
        vertexLine->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(vertexLine);

        vertexButton = new QPushButton(groupBox);
        vertexButton->setObjectName(QStringLiteral("vertexButton"));

        horizontalLayout->addWidget(vertexButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(firstBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label_2);

        ver2Line = new QLineEdit(groupBox_2);
        ver2Line->setObjectName(QStringLiteral("ver2Line"));
        ver2Line->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(ver2Line);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_3);

        ver3Line = new QLineEdit(groupBox_2);
        ver3Line->setObjectName(QStringLiteral("ver3Line"));
        ver3Line->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(ver3Line);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        edgeButton = new QPushButton(groupBox_2);
        edgeButton->setObjectName(QStringLiteral("edgeButton"));

        gridLayout_2->addWidget(edgeButton, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        showButton = new QPushButton(firstBox);
        showButton->setObjectName(QStringLiteral("showButton"));

        gridLayout_4->addWidget(showButton, 2, 0, 1, 1);


        gridLayout_6->addWidget(firstBox, 0, 0, 1, 1);

        secondBox = new QGroupBox(MyClassClass);
        secondBox->setObjectName(QStringLiteral("secondBox"));
        gridLayout_5 = new QGridLayout(secondBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(secondBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        begVerLine = new QLineEdit(secondBox);
        begVerLine->setObjectName(QStringLiteral("begVerLine"));

        horizontalLayout_4->addWidget(begVerLine);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        dfsButton = new QPushButton(secondBox);
        dfsButton->setObjectName(QStringLiteral("dfsButton"));

        horizontalLayout_5->addWidget(dfsButton);

        bfsButton = new QPushButton(secondBox);
        bfsButton->setObjectName(QStringLiteral("bfsButton"));

        horizontalLayout_5->addWidget(bfsButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        searchLine = new QLineEdit(secondBox);
        searchLine->setObjectName(QStringLiteral("searchLine"));

        verticalLayout_2->addWidget(searchLine);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_6->addWidget(secondBox, 1, 0, 1, 1);


        retranslateUi(MyClassClass);

        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QWidget *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "MyClass", 0));
        firstBox->setTitle(QApplication::translate("MyClassClass", "\346\236\204\351\200\240", 0));
        groupBox->setTitle(QApplication::translate("MyClassClass", "\346\217\222\345\205\245\351\241\266\347\202\271", 0));
        label->setText(QApplication::translate("MyClassClass", "\351\241\266\347\202\271", 0));
        vertexButton->setText(QApplication::translate("MyClassClass", "\346\217\222\345\205\245\351\241\266\347\202\271", 0));
        groupBox_2->setTitle(QApplication::translate("MyClassClass", "\346\217\222\345\205\245\350\276\271", 0));
        label_2->setText(QApplication::translate("MyClassClass", "\351\241\266\347\202\2711", 0));
        label_3->setText(QApplication::translate("MyClassClass", "\351\241\266\347\202\2712", 0));
        edgeButton->setText(QApplication::translate("MyClassClass", "\346\217\222\345\205\245\350\276\271", 0));
        showButton->setText(QApplication::translate("MyClassClass", "\346\230\276\347\244\272\351\202\273\346\216\245\350\241\250", 0));
        secondBox->setTitle(QApplication::translate("MyClassClass", "\351\201\215\345\216\206", 0));
        label_4->setText(QApplication::translate("MyClassClass", "\350\265\267\345\247\213\350\212\202\347\202\271", 0));
        dfsButton->setText(QApplication::translate("MyClassClass", "DFS", 0));
        bfsButton->setText(QApplication::translate("MyClassClass", "BFS", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H
