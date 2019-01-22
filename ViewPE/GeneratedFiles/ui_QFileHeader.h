/********************************************************************************
** Form generated from reading UI file 'QFileHeader.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFILEHEADER_H
#define UI_QFILEHEADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFileHeader
{
public:
    QFrame *frame;
    QLabel *label_14;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *NumberOfSecEdit;
    QLineEdit *SizeOpEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *TimeDateEdit;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_7;
    QLineEdit *CharacterEdit;
    QLineEdit *PointerEdit;
    QLineEdit *machineEdit;
    QLabel *label_12;
    QLabel *label;
    QLabel *label_13;
    QLabel *label_8;
    QLabel *label_6;
    QLineEdit *NumberOfSymEdit;

    void setupUi(QWidget *QFileHeader)
    {
        if (QFileHeader->objectName().isEmpty())
            QFileHeader->setObjectName(QStringLiteral("QFileHeader"));
        QFileHeader->resize(498, 179);
        frame = new QFrame(QFileHeader);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 481, 161));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 130, 141, 16));
        label_14->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(300, 110, 131, 16));
        label_11->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 50, 131, 16));
        label_5->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 141, 16));
        label_4->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        NumberOfSecEdit = new QLineEdit(frame);
        NumberOfSecEdit->setObjectName(QStringLiteral("NumberOfSecEdit"));
        NumberOfSecEdit->setGeometry(QRect(190, 30, 101, 20));
        NumberOfSecEdit->setReadOnly(true);
        SizeOpEdit = new QLineEdit(frame);
        SizeOpEdit->setObjectName(QStringLiteral("SizeOpEdit"));
        SizeOpEdit->setGeometry(QRect(190, 110, 101, 20));
        SizeOpEdit->setReadOnly(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 10, 131, 16));
        label_2->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 30, 131, 16));
        label_3->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        TimeDateEdit = new QLineEdit(frame);
        TimeDateEdit->setObjectName(QStringLiteral("TimeDateEdit"));
        TimeDateEdit->setGeometry(QRect(190, 50, 101, 20));
        TimeDateEdit->setReadOnly(true);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(300, 90, 171, 16));
        label_9->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 70, 171, 16));
        label_10->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 110, 171, 16));
        label_7->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        CharacterEdit = new QLineEdit(frame);
        CharacterEdit->setObjectName(QStringLiteral("CharacterEdit"));
        CharacterEdit->setGeometry(QRect(190, 130, 101, 20));
        CharacterEdit->setReadOnly(true);
        PointerEdit = new QLineEdit(frame);
        PointerEdit->setObjectName(QStringLiteral("PointerEdit"));
        PointerEdit->setGeometry(QRect(190, 70, 101, 20));
        PointerEdit->setReadOnly(true);
        machineEdit = new QLineEdit(frame);
        machineEdit->setObjectName(QStringLiteral("machineEdit"));
        machineEdit->setGeometry(QRect(190, 10, 101, 20));
        machineEdit->setReadOnly(true);
        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 90, 151, 16));
        label_12->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 91, 16));
        label->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(300, 130, 131, 16));
        label_13->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(300, 70, 161, 16));
        label_8->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 50, 131, 16));
        label_6->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        NumberOfSymEdit = new QLineEdit(frame);
        NumberOfSymEdit->setObjectName(QStringLiteral("NumberOfSymEdit"));
        NumberOfSymEdit->setGeometry(QRect(190, 90, 101, 20));
        NumberOfSymEdit->setReadOnly(true);

        retranslateUi(QFileHeader);

        QMetaObject::connectSlotsByName(QFileHeader);
    } // setupUi

    void retranslateUi(QWidget *QFileHeader)
    {
        QFileHeader->setWindowTitle(QApplication::translate("QFileHeader", "[ IMAGE_FILE_HEADER (\346\230\240\345\203\217\346\226\207\344\273\266\345\244\264) ] ", 0));
        label_14->setText(QApplication::translate("QFileHeader", "Characteristics\357\274\232", 0));
        label_11->setText(QApplication::translate("QFileHeader", "02h  [\345\217\257\351\200\211\345\244\264\345\244\247\345\260\217]*", 0));
        label_5->setText(QApplication::translate("QFileHeader", "04h  [\346\227\266\351\227\264\346\210\263]", 0));
        label_4->setText(QApplication::translate("QFileHeader", "NumberOfSections\357\274\232", 0));
        label_2->setText(QApplication::translate("QFileHeader", "02h  [\350\277\220\350\241\214\345\271\263\345\217\260]*", 0));
        label_3->setText(QApplication::translate("QFileHeader", "02h  [\345\214\272\346\256\265\346\225\260\347\233\256]*", 0));
        label_9->setText(QApplication::translate("QFileHeader", "04h  [COFF table size]", 0));
        label_10->setText(QApplication::translate("QFileHeader", "PointerToSymbolTable\357\274\232", 0));
        label_7->setText(QApplication::translate("QFileHeader", "SizeOfOptionalHeader\357\274\232", 0));
        label_12->setText(QApplication::translate("QFileHeader", "NumberOfSymbols\357\274\232", 0));
        label->setText(QApplication::translate("QFileHeader", "Machine\357\274\232", 0));
        label_13->setText(QApplication::translate("QFileHeader", "02h  [\347\211\271\345\276\201/\347\211\271\346\200\247]*", 0));
        label_8->setText(QApplication::translate("QFileHeader", "04h  [Pointer to COFF]", 0));
        label_6->setText(QApplication::translate("QFileHeader", "TimeDateStamp\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class QFileHeader: public Ui_QFileHeader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFILEHEADER_H
