#include "Game.h"
#include <iostream>
#include <windows.h>

using namespace std;

Game::Game() {
    map = new Map;
    Point p;
    map->getEntrance(&p);
    person = new Person(p.getX(), p.getY());
    speed = 1000;
    map->setPlayer(person);
}

Game::~Game() {
    delete map;
    delete person;
}


void Game::start() {

    cout << "游戏开始了.." << endl;
    bool first = true;
    while (!person->isFinish()) {
        if (!first) next();
        system("cls");
        map->draw();
        cout << endl << endl;
        cout << "当前已经走了" << person->getModCount() << "步" << endl;
        //判断是否走完迷宫了
        isFinish();
        Sleep(speed);
        first = false;
    }
}

void Game::isFinish() {
    if (map->isFinish(person->getNow())) {
        person->finish();
        cout << "恭喜你完成了迷宫" << endl;
    }
}

void Game::next() {
    person->addModCout();

    //简单地说，无非4个方向可以走， 上、下、左、右
    //不管是右手法则 还是左手法则，都有一个规律，那就是不能够从刚才走刚才走过的方向。
    //然后就是根据右手法则还是左手法则来决定优先走的方向
    //我这里就做右手法则
    //首先根据上一个位置来判断我是什么方向过来的
    //我们假设方向用0-3 分别代表 1:左，2：上 3：右 0：下
    int	direction = 3;
    if (person->getNow()->getX() == person->getLast()->getX() && person->getNow()->getY() == person->getLast()->getY()) {
        //起始位置 什么也不做
    }
    else if (person->getNow()->getX() < person->getLast()->getX() && person->getNow()->getY() == person->getLast()->getY()) {
        //从下面的位置过来的的
    }
    else if (person->getNow()->getX() == person->getLast()->getX() && person->getNow()->getY() < person->getLast()->getY()) {
        //上一个位置是靠右边，所以起始走的方向应该是上
        direction = 2;
    }
    else if (person->getNow()->getX() > person->getLast()->getX() && person->getNow()->getY() == person->getLast()->getY()) {
        //上一个位置是上边，所以优先走左
        direction = 1;
    }
    else if (person->getNow()->getX() == person->getLast()->getX() && person->getNow()->getY() > person->getLast()->getY()) {
        //上一个位置是左边，所有优先走下边
        direction = 0;
    }

    for (int i = 0; i < 3; i++) {
        //根据上面的规则我们发现最多3次即可找到应该走的路

        if (direction == 3) {
            //右边
            if (map->isRoad(person->getNow()->getX(), person->getNow()->getY() + 1)) {
                person->getLast()->setValue(*person->getNow());
                person->getNow()->setY(person->getNow()->getY() + 1);
                break;
            }
        }
        else if (direction == 2) {
            //上边
            if (map->isRoad(person->getNow()->getX() - 1, person->getNow()->getY())) {
                person->getLast()->setValue(*person->getNow());
                person->getNow()->setX(person->getNow()->getX() - 1);
                break;
            }
        }
        else if (direction == 1) {
            //左边
            if (map->isRoad(person->getNow()->getX(), person->getNow()->getY() - 1)) {
                person->getLast()->setValue(*person->getNow());
                person->getNow()->setY(person->getNow()->getY() - 1);
                break;
            }
        }
        else if (direction == 0) {
            //下边
            if (map->isRoad(person->getNow()->getX() + 1, person->getNow()->getY())) {
                person->getLast()->setValue(*person->getNow());
                person->getNow()->setX(person->getNow()->getX() + 1);
                break;
            }
        }

        direction--;
        if (direction == -1)  direction = 3;
    }
}


int main() {
    Game g;
    g.start();
    system("pause");
}