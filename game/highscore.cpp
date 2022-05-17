#include"highscore.h"
#include"game.h"
Score_manager::ScoreManager()
{
    text_="";
    text_color_={0,0,0};
    font_size=30;
    file_path="RobotoCondensed-Regular.ttf";
    font = TTF_OpenFont(file_path, font_size);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
    texture = SDL_CreateTextureFromSurface(Game::gRenderer, surface);
    SDL_FreeSurface(surface);
    TTF_SizeText(font, text.c_str(), &srcRect.w, &srcRect.h);
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = 0;
    destRect.y = 2;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;

}
