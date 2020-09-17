#include "tableexercise.h"
#include <QtDebug>
#include <QHeaderView>
#include "datamodel.h"
#include "comboboxdelegate.h"
#include "tablemodel.h"

TableExercise::TableExercise(TableExercisesWidgets widgets, QObject *parent)
    :QObject(parent)
{

    DataModel* dataModel = new DataModel(this);
    _tableModel = new TableModel(dataModel, this);

    ComboBoxDelegate* delegateX = new ComboBoxDelegate(dataModel->getListX(), this);
    ComboBoxDelegate* delegateY = new ComboBoxDelegate(dataModel->getListY(), this);
    ComboBoxDelegate* delegateZ = new ComboBoxDelegate(dataModel->getListZ(), this);

    _tableView = widgets.tableView;

    _tableView->setModel(_tableModel);
    _tableView->setItemDelegateForColumn(0, delegateX);
    _tableView->setItemDelegateForColumn(1, delegateY);
    _tableView->setItemDelegateForColumn(2, delegateZ);
    _tableView->resizeColumnsToContents();

    _tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    connect(widgets.newRowButton, &QPushButton::clicked, this, &TableExercise::newRow);
    connect(widgets.deleteRowButton, &QPushButton::clicked, this, &TableExercise::deleteRow);

}

bool TableExercise::isRowSelected() const
{
    return _tableView->currentIndex().isValid();
}

void TableExercise::newRow()
{
    //если есть выделенная строка добавим после неё новую строку,
    //если нет добавим последнюю строку
    const int row = isRowSelected() ? _tableView->currentIndex().row() + 1 : _tableModel->rowCount();

    _tableModel->insertRow(row);
    qDebug()<<"newRow";
}

void TableExercise::deleteRow()
{
    //есть ли строки для удаления?
    if(_tableModel->rowCount() == 0)
        return;

    //если есть выделенная строка удалим её,
    //если нет удалим последнюю строку
     const int row = isRowSelected() ? _tableView->currentIndex().row() : _tableModel->rowCount() - 1;

    _tableModel->removeRow(row);
    qDebug()<<"deleteRow";
}
