#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <cellulararray.h>
#include <thegameoflifeservice.h>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_reproduction_clicked();
    void on_cell_reset_clicked();
    void on_Random_initialization_clicked();
    void on_Algebra_reset_clicked();


    void on_auto_reproduction_clicked();

    void on_reproductio_end_clicked();

    void on_table_cellClicked(int row, int column);

private:
    void Initialize();
    void changColor(int row,int col,int color);
    void draw(CellularArray *cellularArray);
    Ui::MainWindow *ui;
    QTableWidgetItem item[20][20];
    TheGameOfLifeService service;
    CellularArray *cellularArray = new CellularArray(20,20);
    QTimer *timer = new QTimer(this);
};

#endif // MAINWINDOW_H
