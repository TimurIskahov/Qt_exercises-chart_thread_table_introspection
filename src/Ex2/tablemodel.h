#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QMetaProperty>

class DataModel;

class TableModel: public QAbstractTableModel
{
public:
    TableModel(DataModel* dataModel, QObject *parent = nullptr);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool insertRows(int row, int count, const QModelIndex &index) override;
    bool removeRows(int row, int count, const QModelIndex &index) override;

private:
    DataModel* _dataModel;
    QList<QMetaProperty> _propertyList;
    QMetaObject _metaObj;

    QVariant displayData(const QModelIndex &index) const;
};

#endif // TABLEMODEL_H
