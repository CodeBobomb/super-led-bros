#include <string>
#include <map>

using namespace std;
class RGBMatrix{
private:
    uint16_t black, red, green, blue, 
                 yellow, orange, magneta, 
                 teal, white;
    SPI* _spi;
    static const int array_size=64;
    DigitalOut* _cs;
    map<string, uint16_t> _colors;
    uint16_t* _matrix;
    void deallocate();
    void allocate(PinName msoi, PinName miso, PinName sclk, PinName chip);
    void displayBuffer();
    void clearBuffer();
public:
    RGBMatrix(PinName msoi, PinName miso, PinName sclk, PinName chip);
    ~RGBMatrix();
    map<string, uint16_t> generateColorsMap();
    void setup();
    void setPixel(int x, int y, string color);
    void setDisplay(uint16_t* array, int array_size=64);
    void refresh();
};

void RGBMatrix::refresh(){
	displayBuffer();
}

void RGBMatrix::setDisplay(uint16_t* array, int array_size){
	if(array==0)
		return 0;
	for(int i=0;i<array_size;i++) _matrix[i]=array[i];
	displayBuffer();
}

void RGBMatrix::setPixel(int x, int y, string color){
    int index=y*8+x;
    _matrix[index]=_colors[color];
    displayBuffer();
}

void RGBMatrix::displayBuffer(){
    _spi->write(0);
    wait_ms(0.5);
        for(int i=0;i<array_size;i++)
            _spi->write(_matrix[i]);
    wait_ms(0.5);
    _spi->write(1);
}
void RGBMatrix::clearBuffer(){
    for(int i=0;i<64;i++)
            _matrix[i]=_colors["black"];
    displayBuffer();
}
void RGBMatrix::setup(){
    clearBuffer();
}

RGBMatrix::~RGBMatrix(){
    deallocate();
}

RGBMatrix::RGBMatrix(PinName msoi, PinName miso, PinName sclk, PinName chip): _spi(0), _cs(0), _matrix(0){
    allocate(msoi,miso,sclk,chip);
}

void RGBMatrix::deallocate(){
    if(_spi!=0)
        delete _spi;
    if(_cs!=0)
        delete _cs;
    if(_matrix!=0)
        delete _matrix;
    _spi=0;
    _cs=0;
    _matrix=0;
}

map<string, uint16_t> RGBMatrix::generateColorsMap(){
    map<string, uint16_t> colors_map;
    colors_map["red"]=0xE0; colors_map["green"]=0x1C; colors_map["blue"]=0x03; 
    colors_map["yellow"]=colors_map["red"]|colors_map["green"]; colors_map["orange"]=0xFC; colors_map["magneta"]=colors_map["red"]|colors_map["blue"];
    colors_map["teal"]=colors_map["blue"]|colors_map["green"]; colors_map["white"]=(colors_map["red"]|colors_map["green"]|colors_map["blue"])-0xA0; 
    return colors_map;
}

void RGBMatrix::allocate(PinName msoi, PinName miso, PinName sclk, PinName chip){
    _spi=new SPI(msoi, miso, sclk);
    _cs=new DigitalOut(chip);
    _colors=generateColorsMap();
    _matrix=new uint16_t[array_size];
    for(int i=0; i<array_size;i++) _matrix[i]=_colors["black"];

}
