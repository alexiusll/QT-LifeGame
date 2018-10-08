#include "cellulararray.h"

CellularArray::CellularArray()
{

}

CellularArray::CellularArray(int row, int col)
{
        this->row = row;
        this->col = col;
        cells = new int *[row];
        for(int i= 0;i<row;i++)
        {
            cells[i] = new int[col];
        }
        for(int i = 0;i<row;i++)
            for(int j = 0;j<col;j++)
              cells[i][j] = 0;
}

void CellularArray::resetCell(int row, int col)
{
    this->row = row;
    this->col = col;
    cells = new int *[row];
    for(int i= 0;i<row;i++)
    {
        cells[i] = new int[col];
    }
    for(int i = 0;i<row;i++)
        for(int j = 0;j<col;j++)
          cells[i][j] = 0;
}

int CellularArray::getCell(int x, int y)
{
        if (x < 0 || row <= x || y < 0 || col <= y) {
            return -1;
        }
        return cells[x][y];
}

bool CellularArray::setCell(int x, int y, int cell)
{
        if (x < 0 || row <= x || y < 0 || col <= y) {
            return false;
        }
        cells[x][y] = cell;
        return true;
}

int CellularArray::getRow()
{
    return row;
}

int CellularArray::getCol()
{
    return col;
}

