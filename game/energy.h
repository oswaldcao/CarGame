#ifndef sdl_energy_car
#define sdl_energy_car
#include"image.h"
class Energy
{
public:
    Energy();
    void render();
    SDL_Rect getEnergyRect()
    {
        return energy;
    }

private:
    SDL_Rect energy;
    LTexture* gEnergy;
};



#endif // sdl_energy_car
