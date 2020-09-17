#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Ex1/threadexercises.h"
#include "Ex2/tableexercise.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    Exercise 1
    для графиков используется QtChart
    поток реализован через переопеределние метода run
    */
    ThreadExercisesWidgets widgets;
    widgets.playButton = ui->pushButton;
    widgets.pauseButton = ui->pushButton_2;
    widgets.stopButton = ui->pushButton_3;
    widgets.groupBox= ui->groupBox_2;
    ex1 = new ThreadExercises(widgets, this);

    /*
    Exercise 2
    используется qt introspection
    доплнительно добавлен combobox delegate, чтобы можно было менять значение ячейки в таблице
    */
    TableExercisesWidgets tableWidgets;
    tableWidgets.newRowButton = ui->pushButton_4;
    tableWidgets.deleteRowButton = ui->pushButton_5;
    tableWidgets.tableView = ui->tableView;
    ex2 = new TableExercise(tableWidgets, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
