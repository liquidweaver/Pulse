/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Mon Aug 13 11:55:01 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *edit_zone;
    QLabel *label_2;
    QLineEdit *edit_merp_host;
    QTextEdit *txt_config_path;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(400, 300);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(Settings);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        edit_zone = new QLineEdit(frame);
        edit_zone->setObjectName(QString::fromUtf8("edit_zone"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, edit_zone);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        edit_merp_host = new QLineEdit(frame);
        edit_merp_host->setObjectName(QString::fromUtf8("edit_merp_host"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, edit_merp_host);


        verticalLayout->addWidget(frame);

        txt_config_path = new QTextEdit(Settings);
        txt_config_path->setObjectName(QString::fromUtf8("txt_config_path"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txt_config_path->sizePolicy().hasHeightForWidth());
        txt_config_path->setSizePolicy(sizePolicy1);
        txt_config_path->setMaximumSize(QSize(16777215, 64));
        txt_config_path->setStyleSheet(QString::fromUtf8("background-image: url(:/ico/PNG/64/Gnome-Document-Properties-64.png);\n"
"background-repeat:no-repeat;\n"
"background-attachment:fixed;\n"
"background-position:bottom right; \n"
""));
        txt_config_path->setFrameShape(QFrame::NoFrame);
        txt_config_path->setReadOnly(true);

        verticalLayout->addWidget(txt_config_path);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "DNS Zone", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "MERP host", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
