#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QSplitter>
#include <QTreeWidget>
#include <QDebug>
#include <QtSql/QtSql>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try {
        MainWindow w;
        QCoreApplication::setOrganizationName("metropark");
        QCoreApplication::setOrganizationDomain("metropark.com");
        QCoreApplication::setApplicationName("pulse");
        w.show();

        return a.exec();
    }
    catch ( std::exception& e ) {
        QMessageBox::critical( NULL, "Error", e.what(), QMessageBox::Ok );
        return 1;
    }
}
