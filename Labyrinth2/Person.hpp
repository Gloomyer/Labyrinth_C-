#pragma once

#include "Point.hpp"


class Person {

private:
    char person = 'T';
    Point *location;
    Point *lastLocation;
    int modCount;
    bool person_finish;

public:
    Person(int x, int y) {
        location = new Point(x, y);
        lastLocation = new Point(x, y);
        modCount = 0;
        person_finish = false;
    }

    ~Person() {
        delete location;
        delete lastLocation;
    }

    bool isFinish() {
        return person_finish;
    }

    void finish() {
        person_finish = true;
    }

    int getModCount() {
        return modCount;
    }

    bool isPersonLocation(int x, int y) {
        Point p(x, y);
        return isPersonLocation(p);
    }

    bool isPersonLocation(Point &p) {
        return p.getX() == location->getX() && p.getY() == location->getY();
    }

    char getChar() {
        return person;
    }

    void addModCout() {
        modCount++;
    }

    Point* getNow() {
        return location;
    }

    Point* getLast() {
        return lastLocation;
    }
};