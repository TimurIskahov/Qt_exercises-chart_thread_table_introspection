#include "tablemodel.h"
#include "datamodel.h"
#include "customcell.h"
#include <algorithm>
#include <QDebug>

TableModel::TableModel(DataModel *dataModel, QObject *parent)
    :QAbstractTableModel(parent),
      _dataModel(dataModel)
{
    _metaObj = CustomRow::staticMetaObject;

    //кешируем MetaProperty для READ\WRITE
    for (int i = _metaObj.propertyOffset(); i < _metaObj.propertyCount(); ++i)
    {
        if (_metaObj.property(i).type() != QVariant::Type::Uuid)
        {
            //qDebug()<< i <<_metaObj.property(i).name();
            _propertyList.append(_metaObj.property(i));
        }
    }
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
             return QVariant();
    if (orientation == Qt::Orientation::Horizontal)
    {
        // для каждой колонки берем название отображаемого ею свойства
        return QString(_propertyList.at(section).name());
    }
    else
        return QString("row%1").arg(section+1);
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _dataModel->getListRow().size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _propertyList.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role){
        case Qt::DisplayRole:
            return displayData(index);
        case Qt::TextAlignmentRole:
            return Qt::AlignCenter;
    default:
        return QVariant();
    }
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    // находим строку
    CustomRow* cmp = _dataModel->getListRow()[index.row()];
    // находим по номеру столбца свойство в модели
    QMetaProperty qmp = _propertyList.at(index.column());

    //в зависмиости от QMetaProperty берем соответствующий колонке List
    QList<CustomCell *> cells;
    const QString name(qmp.name());
    if(name.contains("x"))
        cells=_dataModel->getListX();
    if(name.contains("y"))
        cells=_dataModel->getListY();
    if(name.contains("z"))
        cells= _dataModel->getListZ();

    if(cells.empty())
        return false;

    //находим на какую ячейку из List нужно заменить свойство
    const QString valueName = value.toString();
    auto result = std::find_if(cells.begin(), cells.end(),
                               [valueName](CustomCell * cell)
                               {return cell->getName() == valueName;}
                               );
    if(result == cells.end())
        return false;

    qmp.write(cmp, QVariant::fromValue(*result));
    emit dataChanged(index, index, QVector<int>() << role);

    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;

}

bool TableModel::insertRows(int row, int count, const QModelIndex &index)
{
    beginInsertRows(QModelIndex(), row, row + count - 1);
    for (int i =0; i< count; i++)
    {
        _dataModel->insertRow(row);
    }
    endInsertRows();
}

bool TableModel::removeRows(int row, int count, const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(), row, row + count -1);
    for (int i =0; i< count; i++)
    {
        _dataModel->removeRow(row);
    }
    endRemoveRows();
    return true;
}

QVariant TableModel::displayData(const QModelIndex &index) const
{
    // находим строку
    CustomRow* cmp = _dataModel->getListRow()[index.row()];
    // находим по номеру столбца свойство в модели
    QMetaProperty qmp = _propertyList.at(index.column());
    QObject* complexObj = qvariant_cast<QObject *>(qmp.read(cmp));
    const QMetaObject* mo = complexObj->metaObject();

    //находим какое-нибудь свойство у которого есть name в названии
    for (int i = mo->propertyOffset(); i < mo->propertyCount(); i++)
    {
        if (QString(mo->property(i).name()).toLower().contains("name"))
        {
            return mo->property(i).read(complexObj);
        }
    }
    return QVariant();

}
