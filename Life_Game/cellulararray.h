#ifndef CELLULARARRAY_H
#define CELLULARARRAY_H

class CellularArray
{
public:
    CellularArray();
    CellularArray(int row, int col);
    int getCell(int x, int y);
    bool setCell(int x, int y, int cell);
    bool equals();
    enum cellState{DEAD,LIVE};
    int getRow();
    int getCol();
    void resetCell(int row, int col);

private:
    int **cells;
    int row;
    int col;

};
#endif // CELLULARARRAY_H
