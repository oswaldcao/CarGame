#ifndef sdl_Fuel_car
#define sdl_Fuel_car
#include"image.h"
#include"const.h"

class Fuel
{
public:
    Fuel();
    ~Fuel();
    void move();
    void render();
    SDL_Rect GetFuelRect()
    {
        return fuel;
    }
    void update();
    int getXofFuel(){
        return fuel.x;

    }
    int getYofFuel()
    {
        return fuel.y;
    }


private:
    int a[6]={8,81,155,227,300,373};
    SDL_Rect fuel;
    LTexture* gFuel;

};






#endif // sdl_Fuel_car
