#include "datamodel.h"
#include "customcell.h"

DataModel::DataModel(QObject *parent)
    :QObject (parent)
{
    _xList.append(new CustomCell( QUuid::createUuid(), "X1"));
    _xList.append(new CustomCell( QUuid::createUuid(), "X2"));
    _xList.append(new CustomCell( QUuid::createUuid(), "X3"));
    _xList.append(new CustomCell( QUuid::createUuid(), "X4"));

    _yList.append(new CustomCell( QUuid::createUuid(), "Y1"));
    _yList.append(new CustomCell( QUuid::createUuid(), "Y2"));

    _zList.append(new CustomCell( QUuid::createUuid(), "Z1"));
    _zList.append(new CustomCell( QUuid::createUuid(), "Z2"));
    _zList.append(new CustomCell( QUuid::createUuid(), "Z3"));

    _rowList.append(new CustomRow(QUuid::createUuid(), _xList.at(0), _yList.at(0), _zList.at(0)));
    _rowList.append(new CustomRow(QUuid::createUuid(), _xList.at(0), _yList.at(1), _zList.at(0)));
    _rowList.append(new CustomRow(QUuid::createUuid(), _xList.at(0), _yList.at(1), _zList.at(1)));
    _rowList.append(new CustomRow(QUuid::createUuid(), _xList.at(1), _yList.at(1), _zList.at(1)));

}

DataModel::~DataModel()
{
    qDeleteAll(_rowList);
    qDeleteAll(_xList);
    qDeleteAll(_yList);
    qDeleteAll(_zList);
}

const QList<CustomCell *> &DataModel::getListX() const
{
    return _xList;
}

const QList<CustomCell *> &DataModel::getListY() const
{
    return _yList;
}

const QList<CustomCell *> &DataModel::getListZ() const
{
    return _zList;
}

const QList<CustomRow *> &DataModel::getListRow() const
{
    return _rowList;
}


void DataModel::removeRow(int index)
{
    delete _rowList[index];
    _rowList.removeAt(index);
}

void DataModel::insertRow(int index)
{
    _rowList.insert(index, new CustomRow(QUuid::createUuid(), _xList.at(0), _yList.at(0), _zList.at(0)));
}

