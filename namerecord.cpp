#include "namerecord.h"
#include <QString>

NameRecord::NameRecord( const QString& name, const QString& type, const QString& data )
    : _name(name), _type(type),  _data(data)
{ }

NameRecord::NameRecord(const NameRecord &rhs)
    : _name(rhs._name), _type( rhs._type ), _data( rhs._data )
{ }

const QString& NameRecord::Name() {
    return _name;
}

const QString& NameRecord::Type() {
    return _type;
}

const QString& NameRecord::Data() {
    return _data;
}
