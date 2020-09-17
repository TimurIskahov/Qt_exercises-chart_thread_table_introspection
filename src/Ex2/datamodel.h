#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QList>

class CustomCell;
class CustomRow;

class DataModel: public QObject
{
public:
    DataModel(QObject* parent = nullptr);
    ~DataModel();

    const QList<CustomCell*>& getListX() const;
    const QList<CustomCell*>& getListY() const;
    const QList<CustomCell*>& getListZ() const;
    const QList<CustomRow*>& getListRow() const;

    void removeRow(int index);
    void insertRow(int index);


private:
    QList<CustomCell*> _xList;
    QList<CustomCell*> _yList;
    QList<CustomCell*> _zList;
    QList<CustomRow*> _rowList;
};

#endif // DATAMODEL_H
