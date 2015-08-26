#ifndef ENEMY_H
#define ENEMY_H

#include "mbed.h"


class Enemy{
private:
    int _loc;
    int _range;
    int _speed;
    uint16_t _color;
    bool _alive;
    bool _orientation;
public:
    Enemy(int loc, int range, int speed, uint16_t color);
    void kill();
    int getLoc();
    void setLoc(int value);
    int getRange();
    int getSpeed();
    bool getOrientation();
    void setOrientation(bool value);
    bool isOnPosition(int x, int y);
    bool isAlive();
};
#endif