#include "customcell.h"

CustomCell::CustomCell(const QUuid& id,const QString& name, QObject *parent)
    :QObject(parent),
      _id(id),
      _name(name)
{

}

QUuid CustomCell::getId() const
{
    return _id;
}

QString CustomCell::getName() const
{
    return _name;
}

void CustomCell::setId(const QUuid& id)
{
    _id = id;
}

void CustomCell::setName(const QString& name)
{
    _name = name;
}


CustomRow::CustomRow(const QUuid &id, CustomCell *xCell, CustomCell *yCell, CustomCell *zCell, QObject *parent)
    :QObject(parent),
     _id(id),
     _xCell(xCell),
     _yCell(yCell),
     _zCell(zCell)
{

}

QUuid CustomRow::getId() const
{
    return _id;
}

CustomCell *CustomRow::getCellX()
{
    return _xCell;
}

CustomCell *CustomRow::getCellY()
{
    return _yCell;
}

CustomCell *CustomRow::getCellZ()
{
    return _zCell;
}

void CustomRow::setId(const QUuid &id)
{
    _id = id;
}

void CustomRow::setCellX(CustomCell *xCell)
{
    _xCell = xCell;
}

void CustomRow::setCellY(CustomCell *yCell)
{
    _yCell = yCell;
}

void CustomRow::setCellZ(CustomCell *zCell)
{
    _zCell = zCell;
}
