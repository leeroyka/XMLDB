#include "qtableview.h"

QTableView::QTableView(QObject *parent) : QAbstractTableModel (parent)
{

}
int QTableView::rowCount(const QModelIndex &parent) const
{
    return 5;

}
