#ifndef ENEMY_H
#define ENEMY_H

#include "mbed.h"


class Enemy{
private:
	int _loc;
	int _range:
	int _speed;
	uint16_t _color;
	bool _alive;
public:
	Enemy(int loc, int range, int speed, uint16_t color);
	void kill();
	int getLoc();
	int getRange();
	int getSpeed();
	bool isOnPosition(int x, int y);
	bool isAlive();
};

#endif ENEMY_H