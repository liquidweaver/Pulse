#include "settingsmodel.h"
#include "service.h"
#include <stdexcept>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDir>
#include "metrosettings.h"
//When subclassing QAbstractTableModel, you must implement rowCount(), columnCount(), and data().
// Default implementations of the index() and parent() functions are provided by QAbstractTableModel. Well behaved models will also implement headerData().

//Editable models need to implement setData(), and implement flags() to return a value containing Qt::ItemIsEditable.
#define SM_NAME 0
#define SM_ARGS 1
#define SM_PROGRAM 2
ServicesModel::ServicesModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

void ServicesModel::LoadServices() {
    MetroSettings settings;

    int size = settings.beginReadArray( "services" );
    for (int i=0; i < size; i++ ) {
        Service srv;

        settings.setArrayIndex(i);
        srv.name = settings.value("name").toString();
        srv.program_path = settings.value("program_path").toString();
        srv.argument_string = settings.value("argument_string").toString();
        m_services.append(srv);
    }
    settings.endArray();
}

void ServicesModel::SaveServices() {
    MetroSettings settings;
    settings.beginWriteArray("services");
    int i = 0;
    for ( QList<Service>::const_iterator svc_it = m_services.begin();
          svc_it != m_services.end(); svc_it++ ) {
        const Service& svc = *svc_it;
        settings.setArrayIndex(i);
        settings.setValue("name", svc.name );
        settings.setValue("program_path", svc.program_path );
        settings.setValue("argument_string", svc.argument_string );
        i++;
    }

    settings.endArray();

}

int ServicesModel::rowCount(const QModelIndex &parent) const{
    return m_services.count();
}

int ServicesModel::columnCount(const QModelIndex &parent) const{
    return 3;
}

QVariant ServicesModel::data(const QModelIndex &index, int role ) const{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    } else if ( Qt::DisplayRole == role || Qt::EditRole == role ) {
        QString data;
        const Service &srv = m_services[index.row()];
        const int &col = index.column();
        if ( SM_NAME == col )
                data = srv.name;
        else if ( SM_ARGS == col )
                data = srv.argument_string;
        else if ( SM_PROGRAM == col )
                data = ( Qt::DisplayRole == role )
                        ? QDir::toNativeSeparators( srv.program_path )
                        : QDir::fromNativeSeparators( srv.program_path );
        else
                throw std::logic_error( "ServicesModel::data Invalid column" );
        return data;
    }
    return QVariant();
}

QVariant ServicesModel::headerData( int section, Qt::Orientation orientation, int role ) const{
    if ( Qt::DisplayRole == role && Qt::Horizontal == orientation ) {
        switch ( section ) {
            case SM_NAME:
                return "Service";
            case SM_ARGS:
                return "Arguments";
            case SM_PROGRAM:
                return "Program";
        }
    }
    if ( Qt::DisplayRole == role && Qt::Vertical == orientation )
        return section;
    return QVariant();
}

bool ServicesModel::setData(const QModelIndex &index, const QVariant &value, int role ){
    QString refined_value;
    if ( value.isNull() )
        return false;
    if ( Qt::DisplayRole == role )
        refined_value = QDir::toNativeSeparators(value.toString());
    else if ( Qt::EditRole == role )
        refined_value = QDir::fromNativeSeparators(value.toString());

    Service& srv = m_services[index.row()];
    if ( SM_PROGRAM == index.column() )
        srv.program_path = refined_value;
    else if ( SM_ARGS == index.column() )
        srv.argument_string = refined_value;
    else if ( SM_NAME == index.column() )
        srv.name = refined_value;

    emit ServicesModel::dataChanged( index, index );

    return true;
}

Qt::ItemFlags ServicesModel::flags(const QModelIndex &index ) const{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if ( SM_NAME == index.column() || SM_ARGS == index.column() )
        flags |= Qt::ItemIsEditable;
    else if ( SM_PROGRAM == index.column() )
        flags |= Qt::ItemIsEnabled;

    return flags;
}

bool ServicesModel::insertRows ( int row, int count, const QModelIndex & parent) {
    emit beginInsertRows(parent, m_services.count(), m_services.count());
    Service svc;
    svc.name = "NEW";
    while ( count-- > 0 )
        m_services.append( svc );
    emit endInsertRows();

    return true;
}

bool ServicesModel::removeRows ( int row, int count, const QModelIndex & parent ) {
    emit beginRemoveRows( parent, row, row + count - 1);
    while ( count-- > 0 ) {
        m_services.removeAt( row );
    }
    emit endRemoveRows();

    return true;
}

void ServicesModel::SetFilePath( QModelIndex index ) {
    if ( SM_PROGRAM != index.column() )
        return;
    QModelIndex NameIndex = createIndex( index.row(), SM_NAME );
    QString fileName = QFileDialog::getOpenFileName( NULL, tr("Where is the program to handle the %0 protocol?").arg(data(NameIndex).toString()),
                                                    QDesktopServices::storageLocation( QDesktopServices::ApplicationsLocation ),
                                                    tr("Program (*.exe)"));
    if (!fileName.isNull() ) {
        setData( index, fileName );
    }
}
