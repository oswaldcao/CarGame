#include"Fuel.h"

Fuel::Fuel()
{
    fuel.x=a[ (rand()*rand())%6 ];
    fuel.y=0;
    gFuel=new LTexture();
    gFuel->loadFromFile("Delek.png");
    fuel.w=gFuel->getWidth();
    fuel.h=gFuel->getHeight();


}
Fuel::~Fuel()
{
    gFuel->free();
}

void Fuel::move()
{
    fuel.y+=5;
    /*if(fuel.y>=SCREEN_HEIGHT){
        fuel.y=0;
        i--;
        fuel.x=a[i];
        if(i<0){
            i=5;
        }
    }*/
}
void Fuel::render()
{
    gFuel->render(fuel.x,fuel.y);
}
