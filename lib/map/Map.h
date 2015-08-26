#ifndef MAP_H
#define MAP_H

#include "mbed.h"

class Map{
private:
    void getTempMap();
    void allocate();
    void deallocate();
public:
    Map();
    Map(const Map& m);
    ~Map();
    uint16_t getPixel(int x, int y);
    uint16_t* getMapBlock();
    bool moveRight();
    bool moveLeft();
    int getPlayerBottom();
    void setPlayerBottom(int value);
    bool reachedEnd(bool status=false);
    int getPos();
    void setPos(int value);
private:
    uint16_t* _map;
    int _size;
    int _pos;
    int _end;
    int _playerBottom;
};

#endif