#include"Opcar.h"
#include"game.h"
OpCar::OpCar()
{
    opcar.x=a[(rand()*rand()*rand()-rand()*rand())%3];
    //opcar.x=20;
    opcar.y=0;
    gOpCar=new LTexture();
    gOpCar->loadFromFile("CarOp2.2.png");
    opcar.w=gOpCar->getWidth();
    opcar.h=gOpCar->getHeight();
}

void OpCar::move()
{
    opcar.y+=5;
    if(opcar.y>SCREEN_HEIGHT){
        Game::Score++;
        opcar.y=0;
        opcar.x=a[(rand()+rand()%2 + rand()*rand())%6];

    }

}
void OpCar::render()
{
    gOpCar->render(opcar.x,opcar.y);
}

OpCar::~OpCar()
{
    gOpCar->free();
}


