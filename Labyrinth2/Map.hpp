#pragma once

#include "Person.hpp"
#include "Point.hpp"
#include <iostream>

class Map {
private:
    char wall = '*';//墙的字符
    char road = ' ';//路的字符
    const int x = 8;
    const int y = 9;
    Person *player = NULL;//玩家
    //地图
    char map[8][9] = {
        {wall, wall, wall, wall, wall, wall, wall, road, wall},
        {wall, wall, wall, road, road, road, road, road, wall},
        {wall, wall, wall, road, wall, road, wall, wall, wall},
        {wall, wall, wall, road, wall, road, wall, wall, wall},
        {wall, road, road, road, wall, road, road, road, wall},
        {wall, road, wall, wall, wall, wall, wall, road, wall},
        {wall, road, road, road, road, road, road, road, wall},
        {wall, wall, wall, road, wall, wall, wall, wall, wall}
    };
public:
    void setPlayer(Person *p) {
        if (player != NULL) {
            std::cout << "已经存在一个玩家了!" << std::endl;
            return;
        }
        player = p;
    }

    bool isRoad(int x, int y) {
        Point p(x, y);
        return isRoad(p);
    }

    bool isRoad(Point &p) {
        return map[p.getX()][p.getY()] == road;
    }

    //获取迷宫的入口坐标
    void getEntrance(Point *p) {
        p->setX(7);
        p->setY(3);
    }

    //绘制出当前实际地图与玩家情况
    void draw() {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
               
                //是否是玩家位置
                if (player->isPersonLocation(i, j)) {
                    std::cout << player->getChar();
                } else {
                    std::cout << map[i][j];
                }
            }
            std::cout << std::endl;
        }
    }
    
    bool isFinish(Point *p) {
        return p->getX() == 0 && p->getY() == 7;
    }
};