#pragma once

#include "Map.hpp"
#include "Person.hpp"

class Game {
private:
    Map *map;
    Person *person;
    long speed;
public:
    Game();
    ~Game();
    void start();
    void next();
    void isFinish();
};