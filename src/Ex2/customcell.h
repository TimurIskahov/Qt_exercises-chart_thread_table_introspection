#ifndef CUSTOMCELL_H
#define CUSTOMCELL_H

#include <QObject>
#include <QUuid>

class CustomCell : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUuid id READ getId WRITE setId)
    Q_PROPERTY(QString name READ getName WRITE setName)

public:
    explicit CustomCell(const QUuid& id,const QString& name, QObject *parent = nullptr);

    QUuid getId() const;
    QString getName() const;

    void setId(const QUuid& id);
    void setName(const QString& name);


private:
    QUuid _id;
    QString _name;
};

class CustomRow: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUuid Id READ getId WRITE setId)
    Q_PROPERTY(CustomCell* x READ getCellX WRITE setCellX)
    Q_PROPERTY(CustomCell* y READ getCellY WRITE setCellY)
    Q_PROPERTY(CustomCell* z READ getCellZ WRITE setCellZ)

public:
    explicit CustomRow(const QUuid& id, CustomCell* xCell, CustomCell* yCell, CustomCell* zCell, QObject *parent = nullptr);


    QUuid getId() const;
    CustomCell* getCellX();
    CustomCell* getCellY();
    CustomCell* getCellZ();

    void setId(const QUuid& id);
    void setCellX(CustomCell* xCell);
    void setCellY(CustomCell* yCell);
    void setCellZ(CustomCell* zCell);

private:
    QUuid _id;
    CustomCell* _xCell;
    CustomCell* _yCell;
    CustomCell* _zCell;
};

#endif // CUSTOMCELL_H
