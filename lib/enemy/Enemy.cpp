#include "Enemy.h"
#include "mbed.h"

Enemy::Enemy(int loc, int range, int speed, uint16_t color):_loc(loc),_range(range),_speed(speed),_color(color),_orientation(false){}

int Enemy::getLoc(){
    return _loc;
}

void Enemy::setLoc(int value){
    _loc=value;
}

int Enemy::getRange(){
    return _range;
}

bool Enemy::getOrientation(){
    return _orientation;
}

void Enemy::setOrientation(bool value){
    _orientation=value;
}
int Enemy::getSpeed(){
    return _speed;
}

void Enemy::kill(){
    _alive=false;
}

bool Enemy::isAlive(){
    return _alive;
}