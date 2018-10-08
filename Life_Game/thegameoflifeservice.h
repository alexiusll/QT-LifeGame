#ifndef THEGAMEOFLIFESERVICE_H
#define THEGAMEOFLIFESERVICE_H

#include"cellulararray.h"

class TheGameOfLifeService
{
public:
    TheGameOfLifeService();
    int countLiveNeighbor(CellularArray *now, int x, int y);
    CellularArray* generate(CellularArray *now);
    CellularArray* randInit(CellularArray *cellularArray);
    CellularArray* emptyInit(CellularArray *cellularArray);

private:
    int direct[3] = {-1, 0, 1}; //方向数组

};

#endif // THEGAMEOFLIFESERVICE_H
