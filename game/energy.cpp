#include"energy.h"
Energy::Energy()
{
    energy.x=85;
    energy.y=8;
    gEnergy=new LTexture();
    gEnergy->loadFromFile("stamina1.4-removebg-preview (1).png");
    energy.w=gEnergy->getWidth();
    energy.h=gEnergy->getHeight();

}

void Energy::render()
{
    gEnergy->render(energy.x, energy.y);
}
