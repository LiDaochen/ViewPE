/********************************************************************************
** Form generated from reading UI file 'QDosHeader.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDOSHEADER_H
#define UI_QDOSHEADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_QDosHeader
{
public:
    QFrame *frame;
    QLabel *label_8;
    QLineEdit *e_lfarlcEdit;
    QLabel *label_17;
    QLabel *label_20;
    QLineEdit *e_lfanewEdit;
    QLabel *label_2;
    QLabel *label_21;
    QLabel *label_33;
    QLabel *label_4;
    QLineEdit *e_magicEdit;
    QLabel *label_23;
    QLabel *label_36;
    QLineEdit *e_oemidEdit;
    QLabel *label_19;
    QLineEdit *e_oeminfoEdit;
    QLabel *label_31;
    QLabel *label_34;
    QLineEdit *e_ssEdit;
    QLineEdit *e_res4Edit;
    QLabel *label_26;
    QLabel *label_11;
    QLabel *label_24;
    QLabel *label_7;
    QLabel *label_28;
    QLabel *label_35;
    QLabel *label_3;
    QLineEdit *e_cparhdrEdit;
    QLabel *label_27;
    QLineEdit *e_crlcEdit;
    QLabel *label_16;
    QLineEdit *e_csEdit;
    QLabel *label_29;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_22;
    QLineEdit *e_csumEdit;
    QLabel *label_14;
    QLabel *label;
    QLineEdit *e_cblpEdit;
    QLabel *label_30;
    QLineEdit *e_minallocEdit;
    QLabel *label_5;
    QLineEdit *e_res2Edit;
    QLineEdit *e_spEdit;
    QLabel *label_38;
    QLabel *label_15;
    QLineEdit *e_maxallocEdit;
    QLabel *label_9;
    QLabel *label_25;
    QLabel *label_37;
    QLineEdit *e_cpEdit;
    QLabel *label_10;
    QLabel *label_18;
    QLineEdit *e_ipEdit;
    QLineEdit *e_ovnoEdit;
    QLabel *label_32;

    void setupUi(QDialog *QDosHeader)
    {
        if (QDosHeader->objectName().isEmpty())
            QDosHeader->setObjectName(QStringLiteral("QDosHeader"));
        QDosHeader->resize(517, 420);
        frame = new QFrame(QDosHeader);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 501, 401));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(10);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 150, 71, 16));
        label_8->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_lfarlcEdit = new QLineEdit(frame);
        e_lfarlcEdit->setObjectName(QStringLiteral("e_lfarlcEdit"));
        e_lfarlcEdit->setGeometry(QRect(100, 250, 121, 20));
        e_lfarlcEdit->setReadOnly(true);
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 370, 71, 16));
        label_17->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_20 = new QLabel(frame);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(230, 10, 191, 16));
        label_20->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        e_lfanewEdit = new QLineEdit(frame);
        e_lfanewEdit->setObjectName(QStringLiteral("e_lfanewEdit"));
        e_lfanewEdit->setGeometry(QRect(100, 370, 121, 20));
        e_lfanewEdit->setReadOnly(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 71, 16));
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_21 = new QLabel(frame);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(230, 30, 211, 16));
        label_21->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_33 = new QLabel(frame);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(230, 170, 201, 16));
        label_33->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 71, 16));
        label_4->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_magicEdit = new QLineEdit(frame);
        e_magicEdit->setObjectName(QStringLiteral("e_magicEdit"));
        e_magicEdit->setGeometry(QRect(100, 10, 121, 20));
        e_magicEdit->setReadOnly(true);
        label_23 = new QLabel(frame);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(230, 70, 171, 16));
        label_23->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_36 = new QLabel(frame);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(230, 370, 191, 16));
        label_36->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        e_oemidEdit = new QLineEdit(frame);
        e_oemidEdit->setObjectName(QStringLiteral("e_oemidEdit"));
        e_oemidEdit->setGeometry(QRect(100, 310, 121, 20));
        e_oemidEdit->setReadOnly(true);
        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 310, 71, 16));
        label_19->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_oeminfoEdit = new QLineEdit(frame);
        e_oeminfoEdit->setObjectName(QStringLiteral("e_oeminfoEdit"));
        e_oeminfoEdit->setGeometry(QRect(100, 330, 121, 20));
        e_oeminfoEdit->setReadOnly(true);
        label_31 = new QLabel(frame);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(230, 190, 161, 16));
        label_31->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_34 = new QLabel(frame);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(230, 270, 201, 16));
        label_34->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        e_ssEdit = new QLineEdit(frame);
        e_ssEdit->setObjectName(QStringLiteral("e_ssEdit"));
        e_ssEdit->setGeometry(QRect(100, 150, 121, 20));
        e_ssEdit->setReadOnly(true);
        e_res4Edit = new QLineEdit(frame);
        e_res4Edit->setObjectName(QStringLiteral("e_res4Edit"));
        e_res4Edit->setGeometry(QRect(100, 290, 121, 20));
        e_res4Edit->setReadOnly(true);
        label_26 = new QLabel(frame);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(230, 130, 221, 16));
        label_26->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 210, 71, 16));
        label_11->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(230, 90, 181, 16));
        label_24->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 130, 91, 16));
        label_7->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_28 = new QLabel(frame);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(230, 310, 181, 16));
        label_28->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_35 = new QLabel(frame);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(230, 250, 171, 16));
        label_35->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 71, 16));
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_cparhdrEdit = new QLineEdit(frame);
        e_cparhdrEdit->setObjectName(QStringLiteral("e_cparhdrEdit"));
        e_cparhdrEdit->setGeometry(QRect(100, 90, 121, 20));
        e_cparhdrEdit->setReadOnly(true);
        label_27 = new QLabel(frame);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(230, 150, 191, 16));
        label_27->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        e_crlcEdit = new QLineEdit(frame);
        e_crlcEdit->setObjectName(QStringLiteral("e_crlcEdit"));
        e_crlcEdit->setGeometry(QRect(100, 70, 121, 20));
        e_crlcEdit->setReadOnly(true);
        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 330, 81, 16));
        label_16->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_csEdit = new QLineEdit(frame);
        e_csEdit->setObjectName(QStringLiteral("e_csEdit"));
        e_csEdit->setGeometry(QRect(100, 230, 121, 20));
        e_csEdit->setReadOnly(true);
        label_29 = new QLabel(frame);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(230, 290, 191, 16));
        label_29->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 110, 91, 16));
        label_6->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 250, 71, 16));
        label_13->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 230, 71, 16));
        label_12->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_22 = new QLabel(frame);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(230, 50, 171, 16));
        label_22->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        e_csumEdit = new QLineEdit(frame);
        e_csumEdit->setObjectName(QStringLiteral("e_csumEdit"));
        e_csumEdit->setGeometry(QRect(100, 190, 121, 20));
        e_csumEdit->setReadOnly(true);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 290, 71, 16));
        label_14->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 71, 16));
        label->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_cblpEdit = new QLineEdit(frame);
        e_cblpEdit->setObjectName(QStringLiteral("e_cblpEdit"));
        e_cblpEdit->setGeometry(QRect(100, 30, 121, 20));
        e_cblpEdit->setReadOnly(true);
        label_30 = new QLabel(frame);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(230, 210, 181, 16));
        label_30->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        e_minallocEdit = new QLineEdit(frame);
        e_minallocEdit->setObjectName(QStringLiteral("e_minallocEdit"));
        e_minallocEdit->setGeometry(QRect(100, 110, 121, 20));
        e_minallocEdit->setReadOnly(true);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 90, 81, 16));
        label_5->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_res2Edit = new QLineEdit(frame);
        e_res2Edit->setObjectName(QStringLiteral("e_res2Edit"));
        e_res2Edit->setGeometry(QRect(100, 350, 181, 20));
        e_res2Edit->setReadOnly(true);
        e_spEdit = new QLineEdit(frame);
        e_spEdit->setObjectName(QStringLiteral("e_spEdit"));
        e_spEdit->setGeometry(QRect(100, 170, 121, 20));
        e_spEdit->setReadOnly(true);
        label_38 = new QLabel(frame);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(300, 350, 201, 16));
        label_38->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 270, 71, 16));
        label_15->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_maxallocEdit = new QLineEdit(frame);
        e_maxallocEdit->setObjectName(QStringLiteral("e_maxallocEdit"));
        e_maxallocEdit->setGeometry(QRect(100, 130, 121, 20));
        e_maxallocEdit->setReadOnly(true);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 170, 71, 16));
        label_9->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_25 = new QLabel(frame);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(230, 110, 211, 16));
        label_25->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        label_37 = new QLabel(frame);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(230, 330, 211, 16));
        label_37->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));
        e_cpEdit = new QLineEdit(frame);
        e_cpEdit->setObjectName(QStringLiteral("e_cpEdit"));
        e_cpEdit->setGeometry(QRect(100, 50, 121, 20));
        e_cpEdit->setReadOnly(true);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 190, 71, 16));
        label_10->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 350, 81, 16));
        label_18->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        e_ipEdit = new QLineEdit(frame);
        e_ipEdit->setObjectName(QStringLiteral("e_ipEdit"));
        e_ipEdit->setGeometry(QRect(100, 210, 121, 20));
        e_ipEdit->setReadOnly(true);
        e_ovnoEdit = new QLineEdit(frame);
        e_ovnoEdit->setObjectName(QStringLiteral("e_ovnoEdit"));
        e_ovnoEdit->setGeometry(QRect(100, 270, 121, 20));
        e_ovnoEdit->setReadOnly(true);
        label_32 = new QLabel(frame);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(230, 230, 191, 16));
        label_32->setStyleSheet(QLatin1String("font: 12pt \"Roboto\";\n"
"color: rgb(255, 0, 255);"));

        retranslateUi(QDosHeader);

        QMetaObject::connectSlotsByName(QDosHeader);
    } // setupUi

    void retranslateUi(QDialog *QDosHeader)
    {
        QDosHeader->setWindowTitle(QApplication::translate("QDosHeader", "[ IMAGE_DOS_HEADER (DOS\346\226\207\344\273\266\345\244\264) ] ", 0));
        label_8->setText(QApplication::translate("QDosHeader", "e_ss\357\274\232", 0));
        label_17->setText(QApplication::translate("QDosHeader", "e_lfanew\357\274\232", 0));
        label_20->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [\342\200\234MZ\342\200\235\345\244\264]*", 0));
        label_2->setText(QApplication::translate("QDosHeader", "e_cblp\357\274\232", 0));
        label_21->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Bytes on last page]", 0));
        label_33->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Initial SP value]", 0));
        label_4->setText(QApplication::translate("QDosHeader", "e_crlc\357\274\232", 0));
        label_23->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Relocations]", 0));
        label_36->setText(QApplication::translate("QDosHeader", "\357\274\21004h\357\274\211  [PE NT\345\244\264\345\234\260\345\235\200]*", 0));
        label_19->setText(QApplication::translate("QDosHeader", "e_oemid\357\274\232", 0));
        label_31->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Checksum]", 0));
        label_34->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Overlay number]", 0));
        label_26->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Maximum memory]", 0));
        label_11->setText(QApplication::translate("QDosHeader", "e_ip\357\274\232", 0));
        label_24->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Size of header]", 0));
        label_7->setText(QApplication::translate("QDosHeader", "e_maxalloc\357\274\232", 0));
        label_28->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [OEM identifier]", 0));
        label_35->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Table offset]", 0));
        label_3->setText(QApplication::translate("QDosHeader", "e_cp\357\274\232", 0));
        label_27->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Initial SS value]", 0));
        label_16->setText(QApplication::translate("QDosHeader", "e_oeminfo\357\274\232", 0));
        label_29->setText(QApplication::translate("QDosHeader", "\357\274\21008h\357\274\211  [Reserved words]", 0));
        label_6->setText(QApplication::translate("QDosHeader", "e_minalloc\357\274\232", 0));
        label_13->setText(QApplication::translate("QDosHeader", "e_lfarlc\357\274\232", 0));
        label_12->setText(QApplication::translate("QDosHeader", "e_cs\357\274\232", 0));
        label_22->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Pages in file]", 0));
        label_14->setText(QApplication::translate("QDosHeader", "e_res[4]\357\274\232", 0));
        label->setText(QApplication::translate("QDosHeader", "e_magic\357\274\232", 0));
        label_30->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Initial IP value]", 0));
        label_5->setText(QApplication::translate("QDosHeader", "e_cparhdr\357\274\232", 0));
        label_38->setText(QApplication::translate("QDosHeader", "\357\274\21014h\357\274\211  [Reserved words]", 0));
        label_15->setText(QApplication::translate("QDosHeader", "e_ovno\357\274\232", 0));
        label_9->setText(QApplication::translate("QDosHeader", "e_sp\357\274\232", 0));
        label_25->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Minimum memory]", 0));
        label_37->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [OEM information]", 0));
        label_10->setText(QApplication::translate("QDosHeader", "e_csum\357\274\232", 0));
        label_18->setText(QApplication::translate("QDosHeader", "e_res2[10]\357\274\232", 0));
        label_32->setText(QApplication::translate("QDosHeader", "\357\274\21002h\357\274\211  [Initial CS value]", 0));
    } // retranslateUi

};

namespace Ui {
    class QDosHeader: public Ui_QDosHeader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDOSHEADER_H
