#ifndef PLAYER_H
#define PLAYER_H

#include "mbed.h"

class Player{
private:
    int _x, _y;
    int _jumpValue;
    const int _maxJump=3;
public:
    Player(int x=1, int y=6);
    bool moveRight();
    bool moveLeft();
    bool jump();
    void gravity();
    void setJumpValue(int value);
    int getMaxJump();
    int getJumpValue();
    int getX();
    int getY();
    void setX(int value);
    void setY(int value);
};


#endif 