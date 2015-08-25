#include "RGBMatrix.h"


using namespace std;

class Player{
private:
	int x,y;
	bool power;
	uint16_t color;
public:
	Player(){ x=0; y=0; color=0; }
	Player(int x, int y, uint16_t color=0xE0):x(x),y(y),color(color){ }
	int getX(){ return x; }
	void setX(int x){ this->x=x; }
	int getY(){ return y; }
	void setY(int y){ this->y=y; }
	uint16_t getColor(){ return color; } 
};

class GameEngine{
private:
	static const int level_size=256
	static const int screen_size=64;
	Player* _player;
	RGBMatrix* _driver;
	uint16_t* _level;
	uint16_t* _screen;
	map<string, uint16_t> _colors;
	void displayGame(){
		_driver->refresh();
	}
	void positionPlayer(){
		int index=_player->getY()*8+_player->getX();
		_level[index]=_player->getColor();
	}
public:
	GameEngine(PinName msoi, PinName miso, PinName sclk, PinName chip);
	void playerMoveRight(int value=1){}
};

GameEngine::GameEngine(PinName msoi, PinName miso, PinName sclk, PinName chip):_driver(0),_level(0),_screen(0),_player(0){
	_driver=new RGBMatrix(msoi,mis,sclk,chip);
	_colors=_driver->generateColorsMap();
	_player=new Player(0,0);
	_level=new uint16_t[level_size];

	for(int i=0;i<level_size;i++) _level[i]=_colors["black"];

	_screen=new uint16_t[screen_size];
	for(int i=0;i<screen_size;i++) _screen[i]=_level[i];

}