#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class CustomCell;

class ComboBoxDelegate: public QStyledItemDelegate
{
public:
    ComboBoxDelegate(const QList<CustomCell*>& cells, QObject* parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    QList<CustomCell*> _cells;
};

#endif // COMBOBOXDELEGATE_H
