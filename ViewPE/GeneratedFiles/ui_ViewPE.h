/********************************************************************************
** Form generated from reading UI file 'ViewPE.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPE_H
#define UI_VIEWPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewPEClass
{
public:
    QAction *actionAbout;
    QAction *actionOpenFile;
    QAction *actionQuit;
    QAction *actionDosHeader;
    QAction *actionFileHeader;
    QAction *actionOptionalHeader;
    QAction *actionDataDirectory;
    QAction *actionSectionHeader;
    QAction *actionImportDescriptor;
    QAction *actionToolBar;
    QAction *actionStatusBar;
    QAction *actionOpenMainDlg;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *FileAlignment;
    QLineEdit *OEP;
    QLineEdit *SizeOfOptionalHeader;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *ImageBase;
    QLabel *label_4;
    QLineEdit *NumberOfSections;
    QLineEdit *SectionAlignment;
    QLabel *label;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_V;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViewPEClass)
    {
        if (ViewPEClass->objectName().isEmpty())
            ViewPEClass->setObjectName(QStringLiteral("ViewPEClass"));
        ViewPEClass->resize(667, 400);
        ViewPEClass->setStyleSheet(QStringLiteral(""));
        actionAbout = new QAction(ViewPEClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/Resources/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon);
        actionOpenFile = new QAction(ViewPEClass);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/menu/Resources/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon1);
        actionQuit = new QAction(ViewPEClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/menu/Resources/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon2);
        actionDosHeader = new QAction(ViewPEClass);
        actionDosHeader->setObjectName(QStringLiteral("actionDosHeader"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/menu/Resources/DosHeader.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDosHeader->setIcon(icon3);
        actionFileHeader = new QAction(ViewPEClass);
        actionFileHeader->setObjectName(QStringLiteral("actionFileHeader"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/menu/Resources/fileheader.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileHeader->setIcon(icon4);
        actionOptionalHeader = new QAction(ViewPEClass);
        actionOptionalHeader->setObjectName(QStringLiteral("actionOptionalHeader"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/menu/Resources/OptionalHeader.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptionalHeader->setIcon(icon5);
        actionDataDirectory = new QAction(ViewPEClass);
        actionDataDirectory->setObjectName(QStringLiteral("actionDataDirectory"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/menu/Resources/Table.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDataDirectory->setIcon(icon6);
        actionSectionHeader = new QAction(ViewPEClass);
        actionSectionHeader->setObjectName(QStringLiteral("actionSectionHeader"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/menu/Resources/section.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSectionHeader->setIcon(icon7);
        actionImportDescriptor = new QAction(ViewPEClass);
        actionImportDescriptor->setObjectName(QStringLiteral("actionImportDescriptor"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/menu/Resources/Import.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImportDescriptor->setIcon(icon8);
        actionToolBar = new QAction(ViewPEClass);
        actionToolBar->setObjectName(QStringLiteral("actionToolBar"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/menu/Resources/duihao.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToolBar->setIcon(icon9);
        actionStatusBar = new QAction(ViewPEClass);
        actionStatusBar->setObjectName(QStringLiteral("actionStatusBar"));
        actionStatusBar->setIcon(icon9);
        actionOpenMainDlg = new QAction(ViewPEClass);
        actionOpenMainDlg->setObjectName(QStringLiteral("actionOpenMainDlg"));
        centralWidget = new QWidget(ViewPEClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 271, 291));
        groupBox->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"color: rgb(255, 0, 0);"));
        FileAlignment = new QLineEdit(groupBox);
        FileAlignment->setObjectName(QStringLiteral("FileAlignment"));
        FileAlignment->setGeometry(QRect(140, 150, 113, 20));
        FileAlignment->setReadOnly(true);
        OEP = new QLineEdit(groupBox);
        OEP->setObjectName(QStringLiteral("OEP"));
        OEP->setGeometry(QRect(140, 90, 113, 20));
        OEP->setReadOnly(true);
        SizeOfOptionalHeader = new QLineEdit(groupBox);
        SizeOfOptionalHeader->setObjectName(QStringLiteral("SizeOfOptionalHeader"));
        SizeOfOptionalHeader->setGeometry(QRect(140, 180, 113, 20));
        SizeOfOptionalHeader->setReadOnly(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 180, 111, 21));
        label_2->setStyleSheet(QLatin1String("font: 63 14pt \"Bahnschrift SemiBold Condensed\";\n"
"color: rgb(0, 0, 255);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 111, 21));
        label_3->setStyleSheet(QLatin1String("font: 63 14pt \"Bahnschrift SemiBold Condensed\";\n"
"color: rgb(0, 0, 255);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 120, 131, 21));
        label_5->setStyleSheet(QLatin1String("font: 63 14pt \"Bahnschrift SemiBold Condensed\";\n"
"color: rgb(0, 0, 255);"));
        ImageBase = new QLineEdit(groupBox);
        ImageBase->setObjectName(QStringLiteral("ImageBase"));
        ImageBase->setGeometry(QRect(140, 60, 113, 20));
        ImageBase->setReadOnly(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 131, 21));
        label_4->setStyleSheet(QLatin1String("font: 63 14pt \"Bahnschrift SemiBold Condensed\";\n"
"color: rgb(0, 0, 255);"));
        NumberOfSections = new QLineEdit(groupBox);
        NumberOfSections->setObjectName(QStringLiteral("NumberOfSections"));
        NumberOfSections->setGeometry(QRect(140, 210, 113, 20));
        NumberOfSections->setReadOnly(true);
        SectionAlignment = new QLineEdit(groupBox);
        SectionAlignment->setObjectName(QStringLiteral("SectionAlignment"));
        SectionAlignment->setGeometry(QRect(140, 120, 113, 20));
        SectionAlignment->setReadOnly(true);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 210, 91, 21));
        label->setStyleSheet(QLatin1String("font: 63 14pt \"Bahnschrift SemiBold Condensed\";\n"
"color: rgb(0, 0, 255);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 150, 131, 21));
        label_6->setStyleSheet(QLatin1String("font: 63 14pt \"Bahnschrift SemiBold Condensed\";\n"
"color: rgb(0, 0, 255);"));
        ViewPEClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewPEClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 667, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QStringLiteral("menu_V"));
        ViewPEClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViewPEClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ViewPEClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ViewPEClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ViewPEClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionOpenFile);
        menu->addAction(actionQuit);
        menu_2->addAction(actionAbout);
        menu_V->addAction(actionToolBar);
        menu_V->addAction(actionStatusBar);
        mainToolBar->addAction(actionOpenFile);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDosHeader);
        mainToolBar->addAction(actionFileHeader);
        mainToolBar->addAction(actionOptionalHeader);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDataDirectory);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSectionHeader);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionImportDescriptor);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();

        retranslateUi(ViewPEClass);

        QMetaObject::connectSlotsByName(ViewPEClass);
    } // setupUi

    void retranslateUi(QMainWindow *ViewPEClass)
    {
        ViewPEClass->setWindowTitle(QApplication::translate("ViewPEClass", "ViewPE", 0));
        actionAbout->setText(QApplication::translate("ViewPEClass", "\345\205\263\344\272\216ViewPE", 0));
        actionOpenFile->setText(QApplication::translate("ViewPEClass", "\346\211\223\345\274\200(O)...     Ctrl+O", 0));
        actionQuit->setText(QApplication::translate("ViewPEClass", "\351\200\200\345\207\272(Q)", 0));
        actionDosHeader->setText(QApplication::translate("ViewPEClass", "IMAGE_DOS_HEADER(DOS\346\226\207\344\273\266\345\244\264)", 0));
        actionFileHeader->setText(QApplication::translate("ViewPEClass", "IMAGE_FILE_HEADER(\346\230\240\345\203\217\346\226\207\344\273\266\345\244\264)", 0));
        actionOptionalHeader->setText(QApplication::translate("ViewPEClass", "IMAGE_OPTIONAL_HEADER(\345\217\257\351\200\211\346\230\240\345\203\217\345\244\264)", 0));
        actionDataDirectory->setText(QApplication::translate("ViewPEClass", "IMAGE_DATA_DIRECTORY(\346\225\260\346\215\256\347\233\256\345\275\225\350\241\250)", 0));
        actionSectionHeader->setText(QApplication::translate("ViewPEClass", "IMAGE_SECTION_HEADER(\345\214\272\346\256\265\350\241\250", 0));
        actionImportDescriptor->setText(QApplication::translate("ViewPEClass", "IMAGE_IMPORT_DESCRIPTOR(\345\257\274\345\205\245\350\241\250)", 0));
        actionToolBar->setText(QApplication::translate("ViewPEClass", "\345\267\245\345\205\267\346\240\217(T)", 0));
        actionStatusBar->setText(QApplication::translate("ViewPEClass", "\347\212\266\346\200\201\346\240\217(S)", 0));
        actionOpenMainDlg->setText(QApplication::translate("ViewPEClass", "\346\211\223\345\274\200\344\270\273\351\235\242\346\235\277", 0));
        groupBox->setTitle(QApplication::translate("ViewPEClass", "\351\207\215\350\246\201\346\225\260\346\215\256", 0));
        label_2->setText(QApplication::translate("ViewPEClass", "\346\211\251\345\261\225\345\244\264\345\244\247\345\260\217\357\274\232", 0));
        label_3->setText(QApplication::translate("ViewPEClass", "\347\250\213\345\272\217\345\205\245\345\217\243\347\202\271\357\274\232", 0));
        label_5->setText(QApplication::translate("ViewPEClass", "\345\206\205\345\255\230\345\257\271\351\275\220\347\262\222\345\272\246\357\274\232", 0));
        label_4->setText(QApplication::translate("ViewPEClass", "\351\273\230\350\256\244\345\212\240\350\275\275\345\237\272\345\235\200\357\274\232", 0));
        label->setText(QApplication::translate("ViewPEClass", "\345\214\272\346\256\265\346\225\260\351\207\217\357\274\232", 0));
        label_6->setText(QApplication::translate("ViewPEClass", "\346\226\207\344\273\266\345\257\271\351\275\220\347\262\222\345\272\246\357\274\232", 0));
        menu->setTitle(QApplication::translate("ViewPEClass", "\346\226\207\344\273\266(F)", 0));
        menu_2->setTitle(QApplication::translate("ViewPEClass", "\345\270\256\345\212\251(H)", 0));
        menu_V->setTitle(QApplication::translate("ViewPEClass", "\346\237\245\347\234\213(V)", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewPEClass: public Ui_ViewPEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPE_H
