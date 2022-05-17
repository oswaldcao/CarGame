#ifndef sdl_game_h
#define sdl_game_h
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"const.h"
#include"maincar.h"
#include"background.h"
#include"Opcar.h"
#include"TextManager.h"
#include"Option.h"
#include"Fuel.h"
#include"energy.h"
#include<ctime>
#include<vector>
using namespace std;

class Game
{
public:

    static SDL_Renderer* gRenderer;
    static Car* maincar;
    static SDL_Event e;
    static OpCar* opcar;
    static TextManager* text1;
    BackGround* BGtexture1;
    BackGround* BGtexture2;
    static vector<Fuel*> fuel;
    static TTF_Font* gFont;
    static int Score;
   // static Energy* energy;
    static int energyscore;
    static TextOption* TextInOption;
    Uint64 time_start_fuel;
    Uint64 time_run_fuel;
    Uint64 time_start_energy;
    Uint64 time_run_energy;
    LTexture* energy;




    void close();
    bool init();
    void SetUpGame();
    void Update();
    void Rendergame();
    void GamePlay();
    bool check_in_button(int x, int y, SDL_Rect buttonRect);
    int MakeMenu();

    void Option();

private:
    SDL_Window* gWindow ;

};

#endif // sdl_game_h
