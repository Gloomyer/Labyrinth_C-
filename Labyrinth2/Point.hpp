#pragma once

class Point {
public:
    int x;
    int y;
public:
    
    Point(int m_x = 0, int m_y = 0) : x(m_x), y(m_y) {
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setValue(Point &p) {
        this->x = p.getX();
        this->y = p.getY();
    }
};