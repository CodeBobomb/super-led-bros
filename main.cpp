#include "mbed.h"
#include "Game.h"
Game* game=new Game(PTD2,PTD3,PTD1,PTD5);


int main() {
    game->startGame();
    while(1) {
    }
}
