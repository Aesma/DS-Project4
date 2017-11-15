/********************************************************************************
** Form generated from reading UI file 'newgraph.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGRAPH_H
#define UI_NEWGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newGraph
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *newGraph)
    {
        if (newGraph->objectName().isEmpty())
            newGraph->setObjectName(QStringLiteral("newGraph"));
        newGraph->setWindowModality(Qt::ApplicationModal);
        newGraph->resize(560, 377);
        centralwidget = new QWidget(newGraph);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        newGraph->setCentralWidget(centralwidget);

        retranslateUi(newGraph);

        QMetaObject::connectSlotsByName(newGraph);
    } // setupUi

    void retranslateUi(QMainWindow *newGraph)
    {
        newGraph->setWindowTitle(QApplication::translate("newGraph", "NewGraph", 0));
    } // retranslateUi

};

namespace Ui {
    class newGraph: public Ui_newGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGRAPH_H
