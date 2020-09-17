#ifndef TABLEEXERCISE_H
#define TABLEEXERCISE_H

#include <QObject>
#include <QPushButton>
#include <QTableView>

class DataModel;
class TableModel;


struct TableExercisesWidgets
{
    QPushButton* newRowButton = nullptr;
    QPushButton* deleteRowButton = nullptr;
    QTableView* tableView = nullptr;
};

class TableExercise : public QObject
{
    Q_OBJECT
public:
    explicit TableExercise(TableExercisesWidgets widgets, QObject *parent = nullptr);


private:
   TableModel* _tableModel;
   QTableView* _tableView;

   bool isRowSelected() const;

private slots:
    void newRow();
    void deleteRow();
};

#endif // TABLEEXERCISE_H
