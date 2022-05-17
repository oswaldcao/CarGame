#include"Option.h"
#include"game.h"
TextOption::TextOption()
{
    optionrect1.x=30;
    optionrect1.y=30;
    Game::gFont=TTF_OpenFont("RobotoCondensed-Regular.ttf",28);
    gOption1=new LTexture();
    SDL_Color textcolor={255,255,255};
    gOption1->loadFromRenderedText("This game was developed by CTT",textcolor);
    optionrect1.w=gOption1->getWidth();
    optionrect1.h=gOption1->getHeight();
    optionrect2.x=30;
    optionrect2.y=80;
    gOption2=new LTexture();
    gOption2->loadFromRenderedText("Press 'space' to return menu",textcolor);
    optionrect2.w=gOption2->getWidth();
    optionrect2.h=gOption2->getHeight();


}

void TextOption::render()
{
    gOption1->render(optionrect1.x,optionrect1.y);
    gOption2->render(optionrect2.x,optionrect2.y);
}
TextOption::~TextOption()
{
    gOption1->free();
    gOption2->free();
}
