#ifndef sdl_opcar_main
#define sdl_opcar_main
#include"image.h"
#include"const.h"

class OpCar
{
public:
    OpCar();
    ~OpCar();
    void move();

    void render();
    SDL_Rect getOpcarRect()
    {
        return opcar;
    }

private:
    int a[6]={8,81,155,227,300,373};
    SDL_Rect opcar;
    LTexture* gOpCar;

};

#endif // sdl_opcar_main
