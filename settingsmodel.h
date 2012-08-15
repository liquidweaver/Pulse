#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include <QAbstractTableModel>
#include "service.h"
class QModelIndex;
class QVariant;

class ServicesModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ServicesModel(QObject *parent = 0);
public:
  void LoadServices();

  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole ) const;
  QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
  bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole );
  Qt::ItemFlags flags(const QModelIndex &index ) const;
  bool insertRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
  bool removeRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
  void SaveServices();
signals:
    
public slots:
  void SetFilePath( QModelIndex );
private:
  QList<Service> m_services;

    
};

#endif // SETTINGSMODEL_H
