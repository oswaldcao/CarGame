#ifndef sdl_maincar_h
#define sdl_maincar_h

#include"image.h"
#include"const.h"

class Car
{
    public:

		Car();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move();

		//Shows the dot on the screen
		void render();
        SDL_Rect getMaincarRect()
        {
             return maincar;
        }
        bool colider(SDL_Rect rect);

    private:
		//The X and Y offsets of the dot


		//The velocity of the dot
		int mVelX, mVelY;

		SDL_Rect maincar;

		LTexture* gCarTexture;
};


#endif // sdl_maincar_h
