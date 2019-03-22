#ifndef QTABLEMODEL_H
#define QTABLEMODEL_H

#include <QObject>
#include <QList>
#include <QAbstractTableModel>
#include <QAbstractItemModel>

class QTableModel : public QAbstractTableModel
{
public:

    QTableModel(int cCount=0,int rCount=1,QList<QString> hNames = {},QList<QString> hhNames = {} );
    bool setData(const QList<QString>  &value);
    bool removeRows();
    bool removeColumns();
private:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setHeaderData ( int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::EditRole ) const;
    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const ;


    QList<QList<QString>> values;

    QList<QString> _headerNames;
    QList<QString> _horizontalHeaderNames;
    int _columnCount,_rowCount=1;
};

#endif // QTABLEMODEL_H
