#include"background.h"
#include"const.h"
void BackGround::scrollBG()
{
    yPos+=SCREEN_HEIGHT/84;
    if(yPos>=SCREEN_HEIGHT){
        yPos=-SCREEN_HEIGHT;
    }


}
