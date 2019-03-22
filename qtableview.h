#ifndef QTABLEVIEW_H
#define QTABLEVIEW_H

#include <QObject>
#include <QAbstractTableModel>
class QTableView : public QAbstractTableModel
{
public:
    QTableView(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    int _columns=0;

};

#endif // QTABLEVIEW_H
