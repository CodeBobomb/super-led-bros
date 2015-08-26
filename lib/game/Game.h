#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Enemy.h"
#include "Player.h"
#include "mbed.h"
#include "RGBMatrix.h"
#include <vector>

class Game{
private:
    Map* _map;
    Player* _player;
    vector<Enemy*> _enemies;
    Ticker* _eventTicker;
    Timer* t1,t2;
    RGBMatrix* _rgb;
    bool _changed;
    char readFromSerial();
    void performPlayerAction();
    void enemyWalk(Enemy* enemy);
    void refreshState();
    void playerJump();
    void playerGravity();
public: 
    Game(PinName mosi, PinName miso, PinName sclk, PinName chip, PinName tx=USBTX, PinName rx=USBRX);
    ~Game();
    void startGame();
};

#endif