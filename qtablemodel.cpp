#include "qtablemodel.h"
#include <QVariant>
QTableModel::QTableModel(int cCount,int rCount, QList<QString> hNames, QList<QString> hhNames)
{
    _columnCount = cCount;
    _rowCount = rCount;
    _headerNames = hNames;
    _horizontalHeaderNames = hhNames;
    //QList<QString> v;
    //values.push_back(v);
}
int QTableModel::rowCount(const QModelIndex &parent) const
{
    return _rowCount;

}
int QTableModel::columnCount(const QModelIndex &parent) const
{
    return _columnCount;
}
bool QTableModel::removeRows()
{
    beginRemoveRows(QModelIndex(),0,_rowCount-1);
          endRemoveRows();
          return true;

}
bool QTableModel::removeColumns()
{
        beginRemoveColumns(QModelIndex(),0,_columnCount-1);
        endRemoveColumns();
        return true;
}
bool QTableModel::setDat(const QList<QString> &value)
{
    //values.clear();
    values.push_back(value);
    QModelIndex startIndex=createIndex(0, 0);
    QModelIndex stopIndex=createIndex(_columnCount, _rowCount);
    emit dataChanged(startIndex, stopIndex);
}
bool QTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role==Qt::EditRole)
    {
        values[index.row()][index.column()]= value.toString();
    }
}
Qt::ItemFlags QTableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}
QVariant QTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if(index.column()<=_columnCount)
        {
           QString answer = values[index.row()].at(index.column());
           // QString answer = "test";
            return QVariant(answer);
        }
    }
    return QVariant();
}
bool QTableModel::setHeaderData ( int section, Qt::Orientation orientation, const QVariant & value, int role ) const
{

}
QVariant QTableModel::headerData( int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        QString answer = _headerNames.at(section);
        return QVariant(answer);
    }
    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {
        QString answer =_horizontalHeaderNames.at(section);
        answer = answer.remove(0,answer.lastIndexOf('/')+1);
        return QVariant(answer);
    }
    return QVariant();
}
