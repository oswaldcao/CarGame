#ifndef sdl_image_h
#define sdl_image_h
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );


        bool loadFromRenderedText( std::string textureText, SDL_Color textColor );


		//Deallocates texture
		void free();


		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();
		double getXpos(){
            return xPos;
		}
		double getypos(){
            return yPos;
		}
		void SetxyPos(double x,double y){
            xPos=x;
            yPos=y;

		}
		SDL_Rect getRect();



	protected:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
		double xPos;
		double yPos;
};


#endif // sdl_image_h
