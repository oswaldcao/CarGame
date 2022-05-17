#ifndef sdl_menu_option
#define sdl_menu_option
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include"image.h"

class TextOption
{
public:
    TextOption();
    ~TextOption();
    void render();
    SDL_Rect getOptionRect1()
    {
        return optionrect1;
    }
    SDL_Rect getOptionrect2()
    {
        return optionrect2;
    }
private:
    LTexture* gOption1;
    SDL_Rect optionrect1;
    LTexture* gOption2;
    SDL_Rect optionrect2;

};


#endif // sdl_menu_option
