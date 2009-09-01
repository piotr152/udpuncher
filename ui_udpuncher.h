/********************************************************************************
** Form generated from reading ui file 'udpuncher.ui'
**
** Created: Tue Sep 1 02:11:32 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_UDPUNCHER_H
#define UI_UDPUNCHER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_udpuncherClass
{
public:
    QAction *action_Close;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_IP;
    QLabel *label_2;
    QLineEdit *lineEdit_Port;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Connect;
    QLineEdit *lineEdit_Message;
    QTextEdit *textEdit_Output;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *udpuncherClass)
    {
        if (udpuncherClass->objectName().isEmpty())
            udpuncherClass->setObjectName(QString::fromUtf8("udpuncherClass"));
        udpuncherClass->resize(800, 600);
        action_Close = new QAction(udpuncherClass);
        action_Close->setObjectName(QString::fromUtf8("action_Close"));
        centralwidget = new QWidget(udpuncherClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_IP = new QLineEdit(centralwidget);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));

        horizontalLayout->addWidget(lineEdit_IP);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_Port = new QLineEdit(centralwidget);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));

        horizontalLayout->addWidget(lineEdit_Port);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Connect = new QPushButton(centralwidget);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));

        horizontalLayout->addWidget(pushButton_Connect);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit_Message = new QLineEdit(centralwidget);
        lineEdit_Message->setObjectName(QString::fromUtf8("lineEdit_Message"));

        verticalLayout->addWidget(lineEdit_Message);

        textEdit_Output = new QTextEdit(centralwidget);
        textEdit_Output->setObjectName(QString::fromUtf8("textEdit_Output"));

        verticalLayout->addWidget(textEdit_Output);

        udpuncherClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(udpuncherClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        udpuncherClass->setMenuBar(menubar);
        statusbar = new QStatusBar(udpuncherClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        udpuncherClass->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Close);

        retranslateUi(udpuncherClass);
        QObject::connect(action_Close, SIGNAL(activated()), udpuncherClass, SLOT(close()));

        QMetaObject::connectSlotsByName(udpuncherClass);
    } // setupUi

    void retranslateUi(QMainWindow *udpuncherClass)
    {
        udpuncherClass->setWindowTitle(QApplication::translate("udpuncherClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_Close->setText(QApplication::translate("udpuncherClass", "&Close", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("udpuncherClass", "IP:", 0, QApplication::UnicodeUTF8));
        lineEdit_IP->setInputMask(QApplication::translate("udpuncherClass", "000.000.000.000;_", 0, QApplication::UnicodeUTF8));
        lineEdit_IP->setText(QApplication::translate("udpuncherClass", "127.000.000.001", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("udpuncherClass", "Port:", 0, QApplication::UnicodeUTF8));
        lineEdit_Port->setInputMask(QApplication::translate("udpuncherClass", "00000; ", 0, QApplication::UnicodeUTF8));
        lineEdit_Port->setText(QApplication::translate("udpuncherClass", "2341", 0, QApplication::UnicodeUTF8));
        pushButton_Connect->setText(QApplication::translate("udpuncherClass", "Send", 0, QApplication::UnicodeUTF8));
        lineEdit_Message->setText(QApplication::translate("udpuncherClass", "Hello World!", 0, QApplication::UnicodeUTF8));
        textEdit_Output->setHtml(QApplication::translate("udpuncherClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("udpuncherClass", "&File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class udpuncherClass: public Ui_udpuncherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPUNCHER_H
