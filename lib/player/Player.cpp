#include "mbed.h"
#include "Player.h"


Player::Player(int x, int y):_x(x),_y(y),_jumpValue(3){

}

bool Player::moveRight(){
    return _x++;
}

bool Player::moveLeft(){
    return _x--;
}

bool Player::jump(){
    if(_y-_jumpValue<0 || _jumpValue!=0)
        return false;
    _jumpValue=_maxJump;
    return true;
}

int Player::getJumpValue(){
    return _jumpValue;
}

void Player::setJumpValue(int value){
    if(value<=0) return;
    _jumpValue=value;
}

int Player::getMaxJump(){
    return _maxJump;
}

void Player::setX(int value){
    _x=value;
}

void Player::setY(int value){
    _y=value;
}

int Player::getX(){
    return _x;
}

int Player::getY(){
    return _y;
}