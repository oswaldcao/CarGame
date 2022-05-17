#include"maincar.h"


Car::Car()
{
    //Initialize the offsets
    maincar.x = 17;
    maincar.y = 641;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    gCarTexture=new LTexture();
    gCarTexture->loadFromFile("Car2.0.png");
    maincar.w=gCarTexture->getWidth();
    maincar.h=gCarTexture->getHeight();
}

void Car::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    SDL_PollEvent(&e);
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= Car_VEL; break;
            case SDLK_DOWN: mVelY += Car_VEL; break;
            case SDLK_LEFT: mVelX -= Car_VEL; break;
            case SDLK_RIGHT: mVelX += Car_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += Car_VEL; break;
            case SDLK_DOWN: mVelY -= Car_VEL; break;
            case SDLK_LEFT: mVelX += Car_VEL; break;
            case SDLK_RIGHT: mVelX -= Car_VEL; break;
        }
    }
}
void Car::move()
{
    //Move the dot left or right
    maincar.x += mVelX;

    //If the dot went too far to the left or right
    if( ( maincar.x < 0 ) || ( maincar.x + Car_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        maincar.x -= mVelX;
    }

    //Move the dot up or down
    maincar.y += mVelY;

    //If the dot went too far up or down
    if( ( maincar.y < 0 ) || ( maincar.y + Car_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        maincar.y -= mVelY;
    }
}




void Car::render()
{
    //Show the dot
	gCarTexture->render( maincar.x, maincar.y );
}

bool Car::colider(SDL_Rect rect)
{

    if(
       maincar.x+maincar.w>=rect.x&&
       rect.x+rect.w>=maincar.x&&
       maincar.y+maincar.h>=rect.y&&
       rect.y+rect.h>=maincar.y

       )
    {

        return true;
    }
    return false;

}

