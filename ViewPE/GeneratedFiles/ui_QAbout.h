/********************************************************************************
** Form generated from reading UI file 'QAbout.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QABOUT_H
#define UI_QABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QAbout
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *QAbout)
    {
        if (QAbout->objectName().isEmpty())
            QAbout->setObjectName(QStringLiteral("QAbout"));
        QAbout->resize(270, 143);
        QAbout->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        widget = new QWidget(QAbout);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 30, 161, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);\n"
"font: 75 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);\n"
"font: 75 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));

        verticalLayout->addWidget(label_2);


        retranslateUi(QAbout);

        QMetaObject::connectSlotsByName(QAbout);
    } // setupUi

    void retranslateUi(QDialog *QAbout)
    {
        QAbout->setWindowTitle(QApplication::translate("QAbout", "\345\205\263\344\272\216\350\275\257\344\273\266", 0));
        label->setText(QApplication::translate("QAbout", "\344\275\234\350\200\205\357\274\232\346\235\216\351\201\223\350\207\243", 0));
        label_2->setText(QApplication::translate("QAbout", "QQ\357\274\2321304168666", 0));
    } // retranslateUi

};

namespace Ui {
    class QAbout: public Ui_QAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QABOUT_H
