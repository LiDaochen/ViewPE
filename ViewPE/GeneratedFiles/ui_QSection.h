/********************************************************************************
** Form generated from reading UI file 'QSection.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSECTION_H
#define UI_QSECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSection
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *QSection)
    {
        if (QSection->objectName().isEmpty())
            QSection->setObjectName(QStringLiteral("QSection"));
        QSection->resize(624, 242);
        verticalLayout = new QVBoxLayout(QSection);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(QSection);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        retranslateUi(QSection);

        QMetaObject::connectSlotsByName(QSection);
    } // setupUi

    void retranslateUi(QWidget *QSection)
    {
        QSection->setWindowTitle(QApplication::translate("QSection", "[ Section table (\345\214\272\346\256\265\350\241\250) ]", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("QSection", "\346\240\207\345\277\227", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("QSection", "R.\346\226\207\344\273\266\344\270\255\345\244\247\345\260\217", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("QSection", "R.\346\226\207\344\273\266\344\270\255\345\201\217\347\247\273", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("QSection", "V.\345\206\205\345\255\230\344\270\255\345\244\247\345\260\217", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("QSection", "V.\345\206\205\345\255\230\344\270\255\345\201\217\347\247\273", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("QSection", "\345\220\215\347\247\260", 0));
    } // retranslateUi

};

namespace Ui {
    class QSection: public Ui_QSection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSECTION_H
