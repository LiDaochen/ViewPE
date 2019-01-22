/********************************************************************************
** Form generated from reading UI file 'QDataDirectory.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDATADIRECTORY_H
#define UI_QDATADIRECTORY_H

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

class Ui_QDataDirectory
{
public:
    QFrame *frame;
    QLineEdit *RVAImportAddressTable;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *RVACopyright;
    QLabel *label_4;
    QLineEdit *RVADelayLoadImportDescriptors;
    QLineEdit *RVAImport;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_16;
    QLineEdit *SizeReserved;
    QLabel *label_18;
    QLabel *label_15;
    QLineEdit *RVAException;
    QLabel *label_7;
    QLineEdit *SizeGlobalPtr;
    QLineEdit *SizeResource;
    QLineEdit *RVASecurity;
    QLabel *label_2;
    QLineEdit *SizeBoundImportDirectory;
    QLineEdit *RVABaseRelocationTable;
    QLineEdit *SizeExport;
    QLineEdit *SizeDelayLoadImportDescriptors;
    QLineEdit *SizeTLSDirectory;
    QLineEdit *SizeSecurity;
    QLabel *label_14;
    QLabel *label_17;
    QLineEdit *RVALoadConfigurationDirectory;
    QLineEdit *RVABoundImportDirectory;
    QLineEdit *SizeImport;
    QLineEdit *RVACOMRuntimedescriptor;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_13;
    QLineEdit *SizeBaseRelocationTable;
    QLineEdit *SizeException;
    QLineEdit *RVAReserved;
    QLineEdit *SizeImportAddressTable;
    QLineEdit *SizeCopyright;
    QLineEdit *RVAGlobalPtr;
    QLineEdit *SizeCOMRuntimedescriptor;
    QLabel *label;
    QLineEdit *RVAExport;
    QLineEdit *RVADebugDirectory;
    QLabel *label_11;
    QLineEdit *RVAResource;
    QLineEdit *SizeDebugDirectory;
    QLineEdit *SizeLoadConfigurationDirectory;
    QLineEdit *RVATLSDirectory;
    QLabel *label_5;

    void setupUi(QWidget *QDataDirectory)
    {
        if (QDataDirectory->objectName().isEmpty())
            QDataDirectory->setObjectName(QStringLiteral("QDataDirectory"));
        QDataDirectory->resize(450, 401);
        QDataDirectory->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
";\n"
"font: 12pt \"Roboto\";"));
        frame = new QFrame(QDataDirectory);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 431, 381));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        RVAImportAddressTable = new QLineEdit(frame);
        RVAImportAddressTable->setObjectName(QStringLiteral("RVAImportAddressTable"));
        RVAImportAddressTable->setGeometry(QRect(130, 280, 113, 20));
        RVAImportAddressTable->setReadOnly(true);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 160, 71, 21));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 140, 71, 21));
        RVACopyright = new QLineEdit(frame);
        RVACopyright->setObjectName(QStringLiteral("RVACopyright"));
        RVACopyright->setGeometry(QRect(130, 180, 113, 20));
        RVACopyright->setReadOnly(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 60, 71, 21));
        RVADelayLoadImportDescriptors = new QLineEdit(frame);
        RVADelayLoadImportDescriptors->setObjectName(QStringLiteral("RVADelayLoadImportDescriptors"));
        RVADelayLoadImportDescriptors->setGeometry(QRect(130, 300, 113, 20));
        RVADelayLoadImportDescriptors->setReadOnly(true);
        RVAImport = new QLineEdit(frame);
        RVAImport->setObjectName(QStringLiteral("RVAImport"));
        RVAImport->setGeometry(QRect(130, 60, 113, 20));
        RVAImport->setReadOnly(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 10, 41, 21));
        label_3->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 100, 71, 21));
        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(50, 280, 71, 21));
        SizeReserved = new QLineEdit(frame);
        SizeReserved->setObjectName(QStringLiteral("SizeReserved"));
        SizeReserved->setGeometry(QRect(260, 340, 113, 20));
        SizeReserved->setReadOnly(true);
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(50, 220, 71, 21));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(50, 320, 71, 21));
        RVAException = new QLineEdit(frame);
        RVAException->setObjectName(QStringLiteral("RVAException"));
        RVAException->setGeometry(QRect(130, 100, 113, 20));
        RVAException->setReadOnly(true);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 180, 71, 21));
        SizeGlobalPtr = new QLineEdit(frame);
        SizeGlobalPtr->setObjectName(QStringLiteral("SizeGlobalPtr"));
        SizeGlobalPtr->setGeometry(QRect(260, 200, 113, 20));
        SizeGlobalPtr->setReadOnly(true);
        SizeResource = new QLineEdit(frame);
        SizeResource->setObjectName(QStringLiteral("SizeResource"));
        SizeResource->setGeometry(QRect(260, 80, 113, 20));
        SizeResource->setReadOnly(true);
        RVASecurity = new QLineEdit(frame);
        RVASecurity->setObjectName(QStringLiteral("RVASecurity"));
        RVASecurity->setGeometry(QRect(130, 120, 113, 20));
        RVASecurity->setReadOnly(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 10, 41, 21));
        label_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        SizeBoundImportDirectory = new QLineEdit(frame);
        SizeBoundImportDirectory->setObjectName(QStringLiteral("SizeBoundImportDirectory"));
        SizeBoundImportDirectory->setGeometry(QRect(260, 260, 113, 20));
        SizeBoundImportDirectory->setReadOnly(true);
        RVABaseRelocationTable = new QLineEdit(frame);
        RVABaseRelocationTable->setObjectName(QStringLiteral("RVABaseRelocationTable"));
        RVABaseRelocationTable->setGeometry(QRect(130, 140, 113, 20));
        RVABaseRelocationTable->setReadOnly(true);
        SizeExport = new QLineEdit(frame);
        SizeExport->setObjectName(QStringLiteral("SizeExport"));
        SizeExport->setGeometry(QRect(260, 40, 113, 20));
        SizeExport->setReadOnly(true);
        SizeDelayLoadImportDescriptors = new QLineEdit(frame);
        SizeDelayLoadImportDescriptors->setObjectName(QStringLiteral("SizeDelayLoadImportDescriptors"));
        SizeDelayLoadImportDescriptors->setGeometry(QRect(260, 300, 113, 20));
        SizeDelayLoadImportDescriptors->setReadOnly(true);
        SizeTLSDirectory = new QLineEdit(frame);
        SizeTLSDirectory->setObjectName(QStringLiteral("SizeTLSDirectory"));
        SizeTLSDirectory->setGeometry(QRect(260, 220, 113, 20));
        SizeTLSDirectory->setReadOnly(true);
        SizeSecurity = new QLineEdit(frame);
        SizeSecurity->setObjectName(QStringLiteral("SizeSecurity"));
        SizeSecurity->setGeometry(QRect(260, 120, 113, 20));
        SizeSecurity->setReadOnly(true);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(50, 340, 71, 21));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(50, 260, 71, 21));
        RVALoadConfigurationDirectory = new QLineEdit(frame);
        RVALoadConfigurationDirectory->setObjectName(QStringLiteral("RVALoadConfigurationDirectory"));
        RVALoadConfigurationDirectory->setGeometry(QRect(130, 240, 113, 20));
        RVALoadConfigurationDirectory->setReadOnly(true);
        RVABoundImportDirectory = new QLineEdit(frame);
        RVABoundImportDirectory->setObjectName(QStringLiteral("RVABoundImportDirectory"));
        RVABoundImportDirectory->setGeometry(QRect(130, 260, 113, 20));
        RVABoundImportDirectory->setReadOnly(true);
        SizeImport = new QLineEdit(frame);
        SizeImport->setObjectName(QStringLiteral("SizeImport"));
        SizeImport->setGeometry(QRect(260, 60, 113, 20));
        SizeImport->setReadOnly(true);
        RVACOMRuntimedescriptor = new QLineEdit(frame);
        RVACOMRuntimedescriptor->setObjectName(QStringLiteral("RVACOMRuntimedescriptor"));
        RVACOMRuntimedescriptor->setGeometry(QRect(130, 320, 113, 20));
        RVACOMRuntimedescriptor->setReadOnly(true);
        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(50, 240, 71, 21));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 120, 71, 21));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(50, 300, 71, 21));
        SizeBaseRelocationTable = new QLineEdit(frame);
        SizeBaseRelocationTable->setObjectName(QStringLiteral("SizeBaseRelocationTable"));
        SizeBaseRelocationTable->setGeometry(QRect(260, 140, 113, 20));
        SizeBaseRelocationTable->setReadOnly(true);
        SizeException = new QLineEdit(frame);
        SizeException->setObjectName(QStringLiteral("SizeException"));
        SizeException->setGeometry(QRect(260, 100, 113, 20));
        SizeException->setReadOnly(true);
        RVAReserved = new QLineEdit(frame);
        RVAReserved->setObjectName(QStringLiteral("RVAReserved"));
        RVAReserved->setGeometry(QRect(130, 340, 113, 20));
        RVAReserved->setReadOnly(true);
        SizeImportAddressTable = new QLineEdit(frame);
        SizeImportAddressTable->setObjectName(QStringLiteral("SizeImportAddressTable"));
        SizeImportAddressTable->setGeometry(QRect(260, 280, 113, 20));
        SizeImportAddressTable->setReadOnly(true);
        SizeCopyright = new QLineEdit(frame);
        SizeCopyright->setObjectName(QStringLiteral("SizeCopyright"));
        SizeCopyright->setGeometry(QRect(260, 180, 113, 20));
        SizeCopyright->setReadOnly(true);
        RVAGlobalPtr = new QLineEdit(frame);
        RVAGlobalPtr->setObjectName(QStringLiteral("RVAGlobalPtr"));
        RVAGlobalPtr->setGeometry(QRect(130, 200, 113, 20));
        RVAGlobalPtr->setReadOnly(true);
        SizeCOMRuntimedescriptor = new QLineEdit(frame);
        SizeCOMRuntimedescriptor->setObjectName(QStringLiteral("SizeCOMRuntimedescriptor"));
        SizeCOMRuntimedescriptor->setGeometry(QRect(260, 320, 113, 20));
        SizeCOMRuntimedescriptor->setReadOnly(true);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 71, 21));
        RVAExport = new QLineEdit(frame);
        RVAExport->setObjectName(QStringLiteral("RVAExport"));
        RVAExport->setGeometry(QRect(130, 40, 113, 20));
        RVAExport->setReadOnly(true);
        RVADebugDirectory = new QLineEdit(frame);
        RVADebugDirectory->setObjectName(QStringLiteral("RVADebugDirectory"));
        RVADebugDirectory->setGeometry(QRect(130, 160, 113, 20));
        RVADebugDirectory->setReadOnly(true);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(50, 200, 71, 21));
        RVAResource = new QLineEdit(frame);
        RVAResource->setObjectName(QStringLiteral("RVAResource"));
        RVAResource->setGeometry(QRect(130, 80, 113, 20));
        RVAResource->setReadOnly(true);
        SizeDebugDirectory = new QLineEdit(frame);
        SizeDebugDirectory->setObjectName(QStringLiteral("SizeDebugDirectory"));
        SizeDebugDirectory->setGeometry(QRect(260, 160, 113, 20));
        SizeDebugDirectory->setReadOnly(true);
        SizeLoadConfigurationDirectory = new QLineEdit(frame);
        SizeLoadConfigurationDirectory->setObjectName(QStringLiteral("SizeLoadConfigurationDirectory"));
        SizeLoadConfigurationDirectory->setGeometry(QRect(260, 240, 113, 20));
        SizeLoadConfigurationDirectory->setReadOnly(true);
        RVATLSDirectory = new QLineEdit(frame);
        RVATLSDirectory->setObjectName(QStringLiteral("RVATLSDirectory"));
        RVATLSDirectory->setGeometry(QRect(130, 220, 113, 20));
        RVATLSDirectory->setReadOnly(true);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 80, 71, 21));

        retranslateUi(QDataDirectory);

        QMetaObject::connectSlotsByName(QDataDirectory);
    } // setupUi

    void retranslateUi(QWidget *QDataDirectory)
    {
        QDataDirectory->setWindowTitle(QApplication::translate("QDataDirectory", "[ IMAGE_DATA_DIRECTORY (\346\225\260\346\215\256\347\233\256\345\275\225\350\241\250) ]", 0));
        label_9->setText(QApplication::translate("QDataDirectory", "\350\260\203\350\257\225\344\277\241\346\201\257\357\274\232", 0));
        label_10->setText(QApplication::translate("QDataDirectory", "\351\207\215\345\256\232\344\275\215\350\241\250\357\274\232", 0));
        label_4->setText(QApplication::translate("QDataDirectory", "\345\257\274\345\205\245\350\241\250\357\274\232", 0));
        label_3->setText(QApplication::translate("QDataDirectory", "\345\244\247\345\260\217", 0));
        label_6->setText(QApplication::translate("QDataDirectory", "\345\274\202\345\270\270\350\241\250\357\274\232", 0));
        label_16->setText(QApplication::translate("QDataDirectory", "IAT\350\241\250\357\274\232", 0));
        label_18->setText(QApplication::translate("QDataDirectory", "TLS\350\241\250\357\274\232", 0));
        label_15->setText(QApplication::translate("QDataDirectory", "COM\357\274\232", 0));
        label_7->setText(QApplication::translate("QDataDirectory", "\347\211\210\346\235\203\344\277\241\346\201\257\357\274\232", 0));
        label_2->setText(QApplication::translate("QDataDirectory", "RVA", 0));
        label_14->setText(QApplication::translate("QDataDirectory", "\344\277\235\347\225\231\357\274\232", 0));
        label_17->setText(QApplication::translate("QDataDirectory", "\347\273\221\345\256\232\345\257\274\345\205\245\357\274\232", 0));
        label_12->setText(QApplication::translate("QDataDirectory", "\345\212\240\350\275\275\351\205\215\347\275\256\357\274\232", 0));
        label_8->setText(QApplication::translate("QDataDirectory", "\345\256\211\345\205\250\350\257\201\344\271\246\357\274\232", 0));
        label_13->setText(QApplication::translate("QDataDirectory", "\345\273\266\350\277\237\345\257\274\345\205\245\357\274\232", 0));
        label->setText(QApplication::translate("QDataDirectory", "\345\257\274\345\207\272\350\241\250\357\274\232", 0));
        label_11->setText(QApplication::translate("QDataDirectory", "\345\205\250\345\261\200PTR\357\274\232", 0));
        label_5->setText(QApplication::translate("QDataDirectory", "\350\265\204\346\272\220\350\241\250\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class QDataDirectory: public Ui_QDataDirectory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDATADIRECTORY_H
