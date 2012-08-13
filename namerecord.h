#ifndef NAMERECORD_H
#define NAMERECORD_H
#include <QString>

class NameRecord
{
public:
    NameRecord( const QString& name, const QString& type, const QString& data );
    NameRecord( const NameRecord& rhs );
    const QString& Name();
    const QString& Type();
    const QString& Data();
private:
    QString _name;
    QString _type;
    QString _data;
};

#endif // NAMERECORD_H
