#include "Map.h"


void Map::allocate(){
    /*_map=new uint16_t[_size];
    _end=_size/8-64;*/
    getTempMap(); 
}

void Map::deallocate(){
    if(_map!=0)
        delete[] _map;
    _size=_pos=_end=0;
    _map=0;
}

void Map::getTempMap(){
    uint16_t game_map[]={3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252,
                    3, 0, 0, 0, 0, 0, 252, 252, 
                    3, 0, 0, 0, 0, 252, 252, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252,  
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252,
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252, 
                    3, 0, 0, 0, 0, 252, 252, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252, 
                    3, 0, 0, 0, 0, 0, 0, 252, 
                    3, 0, 0, 0, 0, 0, 252, 252};
    deallocate();
    _map=new uint16_t[8*32];
    for(int i=0; i<8*32; i++){
        _map[i]=game_map[i];
    }
    _pos=0;
    _end=24;
    _size=256;
}

Map::Map():_map(0),_size(256),_pos(0),_end(0){
    allocate(); 
}

Map::Map(const Map& m):_map(0),_size(256),_pos(0),_end(0){
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

void Map::setPlayerBottom(int value){
    _playerBottom=value;
}

int Map::getPlayerBottom(){
    return _playerBottom;
}

uint16_t* Map::getMapBlock(){
    return _map+8*_pos;
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
void Map::setPos(int value){
    _pos=value;
    
}

int Map::getPos(){
    return _pos;
}
bool Map::moveLeft(){
    if(_pos==0)
        return false;
    return _pos--;
}

bool Map::reachedEnd(bool status){
    if(status)
        return _pos==0;
    return _pos==_end;
}