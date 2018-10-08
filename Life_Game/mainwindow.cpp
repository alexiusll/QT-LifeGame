#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "thegameoflifeservice.h"
#include "cellulararray.h"
#include <QTimer>
#include <sstream>
#include <QColor>
#include <QBrush>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>

bool isEnd = true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CellularArray cells;
    Initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    for(int i = 0;i < 20;i ++)
    {
        for(int j = 0;j<20;j++)
        {
            ui->table->setItem(i,j,&item[i][j]);
        }
    }
}

void MainWindow::on_reproduction_clicked()
{
   cellularArray = service.generate(cellularArray);
   draw(cellularArray);
   ui->Algebra_input->setText(QString::number(ui->Algebra_input->text().toInt(0)+1, 10));
}

void MainWindow::on_cell_reset_clicked()
{
  service.emptyInit(cellularArray);
  draw(cellularArray);
}

void MainWindow::on_Random_initialization_clicked()
{
  service.emptyInit(cellularArray);

  int row = ui->length_input->text().toInt(0);
  int col = ui->width_input->text().toInt(0);
  cellularArray->resetCell(row,col);
  service.randInit(cellularArray);
  draw(cellularArray);
  ui->Algebra_input->setText("0");
}

void MainWindow::on_Algebra_reset_clicked()
{
  ui->Algebra_input->setText("0");
}

void MainWindow::draw(CellularArray *cellularArray)
{
   int row = cellularArray->getRow();
   int col = cellularArray->getCol();
   for(int i = 0;i < row; i++)
       for(int j = 0;j < col;j++)
       {
           if(cellularArray->getCell(i,j) == CellularArray::LIVE){
               changColor(i,j,1);
           }
           else
           {
               changColor(i,j,0);
           }
       }

}

void MainWindow::changColor(int row,int col,int color)
{
    if(color == 1){
        item[row][col].setBackground(QColor(0,0,0));
    }
    else
    {
        item[row][col].setBackground(QColor(255,255,255));
    }
}


void MainWindow::on_auto_reproduction_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(on_reproduction_clicked()));
    timer->start(ui->time_input->text().toInt(0));
}

void MainWindow::on_reproductio_end_clicked()
{
   timer->stop();
}


void MainWindow::on_table_cellClicked(int row, int column)
{
    if(cellularArray->getCell(row,column) == CellularArray::LIVE)
    {
        cellularArray->setCell(row,column,CellularArray::DEAD);
    }else{
        cellularArray->setCell(row,column,CellularArray::LIVE);
    }

    draw(cellularArray);
}
