#include "comboboxdelegate.h"
#include "customcell.h"
#include <QComboBox>

ComboBoxDelegate::ComboBoxDelegate(const QList<CustomCell*>& cells, QObject *parent)
    :QStyledItemDelegate(parent),
     _cells(cells)
{

}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox* combobox = new QComboBox(parent);
    combobox->setEditable(false);
    return combobox;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox* combobox = static_cast<QComboBox* >(editor);
    for(const auto& cell: _cells)
        combobox->addItem(cell->getName());

}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* combobox = static_cast<QComboBox* >(editor);
    model->setData(index, combobox->currentText());
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     editor->setGeometry(option.rect);
}
