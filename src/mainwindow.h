#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ThreadExercises;
class TableExercise;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ThreadExercises *ex1;
    TableExercise *ex2;
};

#endif // MAINWINDOW_H
