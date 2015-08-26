#include "Map.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "mbed.h"
#include "RGBMatrix.h"


Game::Game(PinName mosi, PinName miso, PinName sclk, PinName chip, PinName tx, PinName rx){
    _rgb=new RGBMatrix(mosi,miso,sclk,chip,tx,rx);
    _map=new Map();
   // _map->getTempMap();
    _player=new Player();
    _eventTicker=new Ticker();
    _changed=false;
}

Game::~Game(){
    delete _rgb;
    delete _map;
    delete _player;
    delete _eventTicker;
}

void Game::startGame(){
    _eventTicker->attach(this,&Game::refreshState,0.1);
    
}
void Game::refreshState(){
    printf("I'm here");
    performPlayerAction();
    _rgb->setDisplay(_map->getMapBlock());
    int playerX=_player->getX()-_map->getPos();
    int playerY=_player->getY();
    _rgb->setPixel(playerX,playerY,RED,true);
    if(_changed){
        _rgb->show();
        _changed=false;
    }
}


    

char Game::readFromSerial(){
    if(!_rgb->getSerialComm().readable())
        return 0;
    char c=_rgb->getSerialComm().getc();
    if(c!='a' && c!='d' && c!=32)
        return 0;
    return c; 
}

void Game::playerJump(){
    _player->setJumpValue(_player->getJumpValue()-1);
    _player->setY(_player->getY()-1);
}

void Game::playerGravity(){
    _player->setJumpValue(_player->getJumpValue()+1);
    _player->setY(_player->getY()+1);
    //_map->getPixel()
}

void Game::enemyWalk(Enemy* enemy){
    if(enemy->getOrientation() && enemy->getLoc()>=enemy->getLoc()-enemy->getRange()){
        enemy->setLoc(enemy->getLoc()-enemy->getSpeed());
        if(enemy->getLoc()==enemy->getLoc()-enemy->getRange())
            enemy->setOrientation(true);
    }
    else if(!enemy->getOrientation() && enemy->getLoc()<=enemy->getLoc()+enemy->getRange()){
        enemy->setLoc(enemy->getLoc()+enemy->getSpeed());
        if(enemy->getLoc()==enemy->getLoc()+enemy->getRange())
            enemy->setOrientation(false);
    }
}

void Game::performPlayerAction(){
    char c=0;
    c=readFromSerial();
    if(!c)
        return;
    if(c=='d'){ _player->moveRight(); _map->moveRight(); }
    if(c=='a'){ _player->moveLeft(); _map->moveLeft(); }
    if(c==32 && _player->getJumpValue()==0 && _player->getY()==_map->getPlayerBottom()) _player->jump();
    _changed=true;
}
