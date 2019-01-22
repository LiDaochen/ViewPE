/********************************************************************************
** Form generated from reading UI file 'QImport.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIMPORT_H
#define UI_QIMPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QImport
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QTreeWidget *treeWidget_2;

    void setupUi(QWidget *QImport)
    {
        if (QImport->objectName().isEmpty())
            QImport->setObjectName(QStringLiteral("QImport"));
        QImport->resize(632, 381);
        verticalLayout = new QVBoxLayout(QImport);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(QImport);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        treeWidget_2 = new QTreeWidget(QImport);
        treeWidget_2->setObjectName(QStringLiteral("treeWidget_2"));

        verticalLayout->addWidget(treeWidget_2);


        retranslateUi(QImport);

        QMetaObject::connectSlotsByName(QImport);
    } // setupUi

    void retranslateUi(QWidget *QImport)
    {
        QImport->setWindowTitle(QApplication::translate("QImport", "[ Import Descriptor (\345\257\274\345\205\245\350\241\250) ]", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("QImport", "FirstThunk", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("QImport", "Name(RVA)", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("QImport", "ForwarderChain", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("QImport", "TimeDateStamp", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("QImport", "OriginalFirstThunk", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("QImport", "DLL Name", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_2->headerItem();
        ___qtreewidgetitem1->setText(4, QApplication::translate("QImport", "API Name", 0));
        ___qtreewidgetitem1->setText(3, QApplication::translate("QImport", "Hint", 0));
        ___qtreewidgetitem1->setText(2, QApplication::translate("QImport", "Thunk Value", 0));
        ___qtreewidgetitem1->setText(1, QApplication::translate("QImport", "Thunk Offset", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("QImport", "Thunk RVA", 0));
    } // retranslateUi

};

namespace Ui {
    class QImport: public Ui_QImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIMPORT_H
