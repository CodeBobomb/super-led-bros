#include "Map.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "mbed.h"

char Game::readFromSerial(){
    if(!rgb->getSerialComm().readable())
        return 0;
    char c=rgb->getSerialComm().getc();
    if(c!='a' && c!='d' && c!=32)
        return 0;
    return c; 
}


void Game::performPlayerAction(){
    char c=0;
    if(!(c=getInput()))
        return;
    if(c=='d') _player.moveRight();
    if(c=='a') _player.moveLeft();
    if(c==32 && _player.getJumpValue==0 && jump==bottom) _player.jump();
}