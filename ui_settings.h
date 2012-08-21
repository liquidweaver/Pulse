/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Tue Aug 21 15:57:18 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_globals;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *edit_zone;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *edit_merp_host;
    QLabel *label_4;
    QLineEdit *edit_user;
    QLabel *label_5;
    QLineEdit *edit_pass;
    QLabel *label_6;
    QLineEdit *edit_db_name;
    QWidget *tab_services;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_settings;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(715, 357);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(Settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_globals = new QWidget();
        tab_globals->setObjectName(QString::fromUtf8("tab_globals"));
        verticalLayout_2 = new QVBoxLayout(tab_globals);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(tab_globals);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        edit_zone = new QLineEdit(groupBox);
        edit_zone->setObjectName(QString::fromUtf8("edit_zone"));

        formLayout->setWidget(0, QFormLayout::FieldRole, edit_zone);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_globals);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        edit_merp_host = new QLineEdit(groupBox_2);
        edit_merp_host->setObjectName(QString::fromUtf8("edit_merp_host"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, edit_merp_host);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        edit_user = new QLineEdit(groupBox_2);
        edit_user->setObjectName(QString::fromUtf8("edit_user"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, edit_user);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_5);

        edit_pass = new QLineEdit(groupBox_2);
        edit_pass->setObjectName(QString::fromUtf8("edit_pass"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, edit_pass);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        edit_db_name = new QLineEdit(groupBox_2);
        edit_db_name->setObjectName(QString::fromUtf8("edit_db_name"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, edit_db_name);


        verticalLayout_2->addWidget(groupBox_2);

        tabWidget->addTab(tab_globals, QString());
        tab_services = new QWidget();
        tab_services->setObjectName(QString::fromUtf8("tab_services"));
        verticalLayout_3 = new QVBoxLayout(tab_services);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableView = new QTableView(tab_services);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_3->addWidget(tableView);

        frame = new QFrame(tab_services);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_settings = new QPushButton(frame);
        btn_settings->setObjectName(QString::fromUtf8("btn_settings"));

        horizontalLayout->addWidget(btn_settings);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_3->addWidget(frame);

        tabWidget->addTab(tab_services, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));
        QObject::connect(btn_settings, SIGNAL(clicked()), Settings, SLOT(AddService()));
        QObject::connect(pushButton, SIGNAL(clicked()), Settings, SLOT(RemoveSelected()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Settings", "Network Discovery", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "DNS Zone", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Settings", "Hot Tickets", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "MERP host", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Settings", "User", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Settings", "Secret", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Settings", "Database", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_globals), QApplication::translate("Settings", "Globals", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Set the program by double-clicking the path and selecting the program.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">To set the arguments, use a hash sign (#) as a place holder for the FQDN.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btn_settings->setText(QApplication::translate("Settings", "Add Service", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Settings", "Remove Selected", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_services), QApplication::translate("Settings", "Services", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
