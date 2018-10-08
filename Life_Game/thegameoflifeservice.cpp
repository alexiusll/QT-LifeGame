#include "thegameoflifeservice.h"
#include "cellulararray.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <QtGlobal>
#include <QTime>
TheGameOfLifeService::TheGameOfLifeService()
{

}

/**
     * 给定阵列和坐标,计算坐标点的邻居存活数量
     * @param now 细胞阵列
     * @param x 横坐标
     * @param y 纵坐标
     * @return
     */
int TheGameOfLifeService::countLiveNeighbor(CellularArray *now, int x, int y)
{
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
             if (CellularArray::LIVE== now->getCell(x + direct[i], y + direct[j]))
              {
                  ++count;
              }
          }
      }
    //删掉自己,不计算细胞自己是否活着
     if (CellularArray::LIVE == now->getCell(x, y))
     {
          --count;
     }
     return count;
}

/**
    * 给定细胞阵列,生成下一代的细胞阵列
    * @param now 细胞阵列
    * @return
    */
CellularArray* TheGameOfLifeService::generate(CellularArray *now) {
       if (NULL == now) {
           return NULL;
       }
       //细胞周围存活的细胞数量
       int liveCount;
       CellularArray *next = new CellularArray(now->getRow(), now->getCol());
       for (int i = 0; i < next->getRow(); ++i) {
           for (int j = 0; j < next->getCol(); ++j) {
               liveCount = this->countLiveNeighbor(now, i, j);
               if (CellularArray::LIVE == now->getCell(i, j) && (liveCount < 2 || liveCount > 3))
               { //人口过少,人口过多
                   next->setCell(i, j, CellularArray::DEAD);
               }
               else if (CellularArray::LIVE == now->getCell(i, j) && (2 <= liveCount && liveCount <= 3))
               { //正常
                   next->setCell(i, j, CellularArray::LIVE);
               }
               else if (CellularArray::DEAD == now->getCell(i, j) && (3 == liveCount))
               { //繁殖
                   next->setCell(i, j, CellularArray::LIVE);
               }
           }
       }
       return next;
}

/**
     * 给定细胞阵列,产生随机结果
     * @param cellularArray 细胞阵列
     * @return
     */
CellularArray* TheGameOfLifeService::randInit(CellularArray* cellularArray) {
        if (NULL == cellularArray) return NULL;
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int value;
        for (int i = 0; i < cellularArray->getRow(); i++) {
            for (int j = 0; j < cellularArray->getCol(); j++) {
                value = qrand()%2; //生成0~1随机数
                cellularArray->setCell(i, j, value);
            }
        }
        return cellularArray;
}


CellularArray* TheGameOfLifeService::emptyInit(CellularArray* cellularArray) {
        if (NULL == cellularArray) return NULL;
        for (int i = 0; i < cellularArray->getRow(); ++i) {
            for (int j = 0; j < cellularArray->getCol(); ++j) {
                cellularArray->setCell(i, j, CellularArray::DEAD);
            }
        }
        return cellularArray;
}

