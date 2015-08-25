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
	bool reachedEnd(status=false);
private:
	uint16_t* _map;
	int _size;
	int _pos;
};

#endif