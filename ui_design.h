/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGN_H
#define UI_DESIGN_H

#include <iostream>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

using namespace std;

class ui_design : public QDialog 
{
     Q_OBJECT
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    QString input;

public slots:

    void file_entered()
    {
          input = lineEdit->text();
    }

public:
    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(303, 480);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 112));
        QFont font;
        font.setFamily(QStringLiteral("ADELE"));
        textEdit->setFont(font);

        verticalLayout->addWidget(textEdit);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setPixmap(QPixmap("download.jpg"));
        label_3->setScaledContents(true);

        verticalLayout->addWidget(label_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 2);

        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 2);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);

        gridLayout->addWidget(lineEdit, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(comboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(Dialog);
        QObject::connect(pushButton, SIGNAL(pressed()), Dialog, SLOT(accept()));
        QObject::connect(comboBox, SIGNAL(activated(QString)), checkBox, SLOT(toggle()));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), lineEdit, SLOT(setEnabled(bool)));
        QObject::connect(lineEdit,SIGNAL(textChanged(const QString&)),this,SLOT(file_entered()));
        QObject::connect(checkBox, SIGNAL(clicked()), Dialog, SLOT(accept()));
        
        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        textEdit->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'ADELE'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Helvetica'; font-size:20pt; font-weight:600; text-decoration: underline; color:#000000;\">VIT SUPERMART</span></p></body></html>", 0));
        label_3->setText(QString());
        label->setText(QApplication::translate("Dialog", "<html><head/><body><p align=\"center\">input method</p></body></html>", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "capture image ", 0)
         << QApplication::translate("Dialog", "select image", 0)
        );
        checkBox->setText(QApplication::translate("Dialog", "choose image", 0));
        lineEdit->setText(QApplication::translate("Dialog", "enter filename..", 0));
        lineEdit->setPlaceholderText(QApplication::translate("Dialog", "choose location", 0));
        pushButton->setText(QApplication::translate("Dialog", "close", 0));
    } // retranslateUi

    
};

namespace Ui {
    class Dialog: public ui_design {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGN_H
