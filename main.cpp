#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QSplitter>
#include <QTreeWidget>
#include <QDebug>
#include <QtSql/QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QCoreApplication::setOrganizationName("metropark");
    QCoreApplication::setOrganizationDomain("metropark.com");
    QCoreApplication::setApplicationName("pulse");
    w.show();

//    QSplitter qsplitter(Qt::Vertical);
//    QTreeWidget* zone = new QTreeWidget();
//    qsplitter.addWidget(zone);
//    qsplitter.show();
    return a.exec();
}
