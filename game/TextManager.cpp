#include "TextManager.h"
#include "game.h"

TextManager::TextManager()
{
    Game::gFont=TTF_OpenFont("RobotoCondensed-Regular.ttf",28);
    gText=new LTexture();
    TextRect.x=0;
    TextRect.y=0;
    SDL_Color textcolor={0,0,0};
    string score1=to_string(Game::Score);
    string score=textscore+score1;
    gText->loadFromRenderedText(score,textcolor);

    TextRect.w=gText->getWidth();
    TextRect.h=gText->getHeight();

}
void TextManager::render()
{
    gText->render(TextRect.x,TextRect.y);
}
void TextManager::update()
{
    gText->loadFromRenderedText(textscore+to_string(Game::Score),SDL_Color{0,0,0});
    TextRect.w=gText->getWidth();
    TextRect.h=gText->getHeight();
}
