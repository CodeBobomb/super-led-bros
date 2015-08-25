#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Enemy.h"
#include "Player.h"

class Game{
private:
	Map* _map;
	Player* _player;
	vector<Enemy*> _enemies;
	Ticker* _eventTicker;
	Timer* t1,t2;
	char readFromSerial();
	char performPlayerAction();
	void refreshState();
	void playerGravity();
public: 
	Game();
	void startGame();
};

#endif GAME_H