#include "mbed.h"
#include "Player.h"
#include "Map.h"

Player::Player(int x, int y):_x(x),_y(y),_jumpValue(3),{

}

bool Player::moveRight(){
	if(_map.reachedEnd())
		return false;
	return _x++;
}

bool Player::moveLeft(){
	if(_map.reachedEnd(false))
		return false;
	return _x--;
}

bool Player::jump(){
	if(_y-_jumpInc<0 || _jumpValue!=0)
		return false:
	_jumpValue=_jumpInc;
	return true;
}

int& Player::getJumpValue(){
	return _jumpValue;
}

void Player::setJumpInc(int value){
	if(value<=0) return;
	_jumpInc=value;
}