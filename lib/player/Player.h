#ifndef PLAYER_H
#define PLAYER_H

#include "mbed.h"
#include "Map.h"
class Player{
private:
	int _x, _y;
	int _jumpInc;
	int _jumpValue;
public:
	Player(int x=1, int y=6);
	bool moveRight();
	bool moveLeft();
	bool jump();
	void gravity();
	void setJumpInc(int value);
	int getJumpValue();
	int getX();
	int& getY();
};


#endif 