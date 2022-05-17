#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include"image.h"

class TextManager
{
private :
    std::string textscore="Score: ";


    SDL_Rect TextRect;
    LTexture* gText;

public :
    TextManager();
    void render();
    void update();
    void setText(std::string score)
    {
        textscore=score;
    }

    SDL_Rect getTextrect()
    {
        return TextRect;
    }


};

#endif // TEXT_OBJECT_H

