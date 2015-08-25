#include "Enemy.h"
#include "mbed.h"

Enemy::Enemy(int loc, int range, int speed, uint16_t color):_loc(loc),_range(range),_speed(speed),_color(color){}

int Enemy::getLoc(){
	return _loc;
}

int Enemy::getRange(){
	return _range;
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