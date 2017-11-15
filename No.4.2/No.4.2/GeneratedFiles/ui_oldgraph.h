/********************************************************************************
** Form generated from reading UI file 'oldgraph.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OLDGRAPH_H
#define UI_OLDGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OldGraph
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *OldGraph)
    {
        if (OldGraph->objectName().isEmpty())
            OldGraph->setObjectName(QStringLiteral("OldGraph"));
        OldGraph->setWindowModality(Qt::ApplicationModal);
        OldGraph->resize(528, 350);
        centralwidget = new QWidget(OldGraph);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        OldGraph->setCentralWidget(centralwidget);

        retranslateUi(OldGraph);

        QMetaObject::connectSlotsByName(OldGraph);
    } // setupUi

    void retranslateUi(QMainWindow *OldGraph)
    {
        OldGraph->setWindowTitle(QApplication::translate("OldGraph", "OldGraph", 0));
    } // retranslateUi

};

namespace Ui {
    class OldGraph: public Ui_OldGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OLDGRAPH_H
