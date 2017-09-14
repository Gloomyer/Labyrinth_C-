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

    cout << "��Ϸ��ʼ��.." << endl;
    bool first = true;
    while (!person->isFinish()) {
        if (!first) next();
        system("cls");
        map->draw();
        cout << endl << endl;
        cout << "��ǰ�Ѿ�����" << person->getModCount() << "��" << endl;
        //�ж��Ƿ������Թ���
        isFinish();
        Sleep(speed);
        first = false;
    }
}

void Game::isFinish() {
    if (map->isFinish(person->getNow())) {
        person->finish();
        cout << "��ϲ��������Թ�" << endl;
    }
}

void Game::next() {
    person->addModCout();

    //�򵥵�˵���޷�4����������ߣ� �ϡ��¡�����
    //���������ַ��� �������ַ��򣬶���һ�����ɣ��Ǿ��ǲ��ܹ��Ӹղ��߸ղ��߹��ķ���
    //Ȼ����Ǹ������ַ��������ַ��������������ߵķ���
    //������������ַ���
    //���ȸ�����һ��λ�����ж�����ʲô���������
    //���Ǽ��跽����0-3 �ֱ���� 1:��2���� 3���� 0����
    int	direction = 3;
    if (person->getNow()->getX() == person->getLast()->getX() && person->getNow()->getY() == person->getLast()->getY()) {
        //��ʼλ�� ʲôҲ����
    }
    else if (person->getNow()->getX() < person->getLast()->getX() && person->getNow()->getY() == person->getLast()->getY()) {
        //�������λ�ù����ĵ�
    }
    else if (person->getNow()->getX() == person->getLast()->getX() && person->getNow()->getY() < person->getLast()->getY()) {
        //��һ��λ���ǿ��ұߣ�������ʼ�ߵķ���Ӧ������
        direction = 2;
    }
    else if (person->getNow()->getX() > person->getLast()->getX() && person->getNow()->getY() == person->getLast()->getY()) {
        //��һ��λ�����ϱߣ�������������
        direction = 1;
    }
    else if (person->getNow()->getX() == person->getLast()->getX() && person->getNow()->getY() > person->getLast()->getY()) {
        //��һ��λ������ߣ������������±�
        direction = 0;
    }

    for (int i = 0; i < 3; i++) {
        //��������Ĺ������Ƿ������3�μ����ҵ�Ӧ���ߵ�·

        if (direction == 3) {
            //�ұ�
            if (map->isRoad(person->getNow()->getX(), person->getNow()->getY() + 1)) {
                person->getLast()->setValue(*person->getNow());
                person->getNow()->setY(person->getNow()->getY() + 1);
                break;
            }
        }
        else if (direction == 2) {
            //�ϱ�
            if (map->isRoad(person->getNow()->getX() - 1, person->getNow()->getY())) {
                person->getLast()->setValue(*person->getNow());
                person->getNow()->setX(person->getNow()->getX() - 1);
                break;
            }
        }
        else if (direction == 1) {
            //���
            if (map->isRoad(person->getNow()->getX(), person->getNow()->getY() - 1)) {
                person->getLast()->setValue(*person->getNow());
                person->getNow()->setY(person->getNow()->getY() - 1);
                break;
            }
        }
        else if (direction == 0) {
            //�±�
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