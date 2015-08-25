#include "Map.h"


void Map::allocate(){
	_map=new uint16_t[_size];
	_end=_size/8-64; 
}

void Map::deallocate(){
	if(_map!=0)
		delete[] map;
	_size=_pos=_end=_map=0;
}

Map::Map():_size(256),_map(0),_pos(0),_end(0){
	allocate(); 
}

Map::Map(const Map& m):_size(256),_map(0),_pos(0),_end(0){
	_size=m._size;
	_pos=m._pos;
	_end=m._end;
	allocate();
	for(int i=0; i<_size; i++)
		_map[i]=m._map[i];
}

Map::~Map(){
	deallocate();
}

uint16_t* Map::getMapBlock(){
	return _map(8*_pos);
}

uint16_t Map::getPixel(int x, int y){
	if(x==0 || y==0)
		return 0;
	return _map[8*x+y];
} 	 

bool Map::moveRight(){
	if(_pos==_end)
		return false;
	return _pos++;
}

bool Map::moveLeft(){
	if(_pos==0)
		return false;
	return _pos--;
}

bool Map::reachedEnd(status){
	if(status)
		return _pos==0;
	return _pos==_end;
}