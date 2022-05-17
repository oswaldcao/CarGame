#include"game.h"

SDL_Renderer* Game::gRenderer;

Car* Game::maincar;

SDL_Event Game::e;

OpCar* Game::opcar;

TextManager* Game::text1;

vector<Fuel*> Game::fuel;

TTF_Font* Game::gFont;

int Game::Score=0;

//Energy* Game::energy;

int Game::energyscore=5;

TextOption* Game::TextInOption;






bool Game::init()
{
    bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		cout<< "SDL could not initialize! SDL Error: \n"<< SDL_GetError() ;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			cout<< "Warning: Linear texture filtering not enabled!" ;
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			cout<< "Window could not be created! SDL Error: \n"<< SDL_GetError() ;
			success = false;
		}
		else
		{

			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				cout<< "Renderer could not be created! SDL Error: %s\n"<< SDL_GetError() ;
				success = false;
			}
			else
			{

				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) && imgFlags ) )
				{
					cout<< "SDL_image could not initialize! SDL_image Error: %s\n"<< IMG_GetError() ;
					success = false;
				}
			}
			if ( TTF_Init() != 0 ) success = false;

		}
	}

	return success;

}
void Game::close()
{
    BGtexture1->free();
    BGtexture2->free();
    SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	delete opcar;
	fuel.clear();
	delete maincar;
	delete text1;
	delete TextInOption;

	delete energy;



	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}

void Game::SetUpGame()
{
    BGtexture1=new BackGround();
    BGtexture1->loadFromFile("background.png");
    BGtexture1->SetxyPos(0,-SCREEN_HEIGHT);
    BGtexture2=new BackGround();
    BGtexture2->loadFromFile("background.png");
    BGtexture2->SetxyPos(0,0);




    maincar=new Car();

    opcar=new OpCar();

    text1=new TextManager();
    time_start_fuel=SDL_GetTicks64();
    time_run_fuel=3000;
    time_start_energy=SDL_GetTicks64();
    time_run_energy=5000;

    energy = new LTexture[5];
    for(int i = 0 ; i<5;i++){
        energy[i].loadFromFile("stamina1." + to_string(i) + ".png");

    }

    //energy=new Energy();

}

void Game::Update()
{
    BGtexture1->scrollBG();
    BGtexture2->scrollBG();

    maincar->handleEvent(e);

    maincar->move();

    opcar->move();


    if ( SDL_GetTicks64() - time_start_fuel >= time_run_fuel ) {

        Fuel* f = new Fuel();
        fuel.push_back(f);
        time_start_fuel = SDL_GetTicks64();
    }
    if(SDL_GetTicks64() - time_start_energy >= time_run_energy ){
        energyscore--;
        time_start_energy=SDL_GetTicks64();
        if(energyscore==0){
            close();
        }


    }

    for(int i = 0;i<fuel.size();i++){
        fuel[i]->move();
    }

    text1->update();


}

void Game::Rendergame()
{
    BGtexture1->render(BGtexture1->getXpos(),BGtexture1->getypos());
    BGtexture2->render(BGtexture2->getXpos(),BGtexture2->getypos());


    maincar->render();

    opcar->render();



    text1->render();
    for(int i =  0 ;i<fuel.size();){
        if(maincar->colider(fuel[i]->GetFuelRect())){
            fuel.erase(fuel.begin()+i);
            if(energyscore<5){
                energyscore++;

            }
        }
        else if(fuel[i]->getYofFuel()>SCREEN_HEIGHT){
            fuel.erase(fuel.begin()+i);
        }
        else{
            fuel[i]->render();
            i++;
        }
    }
    //energy->render();
    energy[5-energyscore].render(286,8);

}

void Game::GamePlay()
{
    if(maincar->colider(opcar->getOpcarRect()))
    {
        close();

    }
    else{
        //cout<<"1233123"<<endl;
    }


}

bool Game::check_in_button(int x,int y, SDL_Rect buttonRect)
{
    if(x >= buttonRect.x && x <= buttonRect.x + buttonRect.w && y >= buttonRect.y && y <= buttonRect.y + buttonRect.h) return true;
    return false;
}



int Game::MakeMenu()
{
    LTexture*Menu_Background=new LTexture();
    Menu_Background->loadFromFile("menu.jpg");
    LTexture*button[3];
    for(int i = 0 ; i<3;i++){
        button[i]=new LTexture();
    }
    int x1=0;
    for(int  i = 0 ;i <3;i++){

        button[i]->SetxyPos(Menu_Background->getWidth()/2-75,Menu_Background->getHeight()/3+x1);
        x1+=115;
    }
    /*button[0]->SetxyPos(Menu_Background->getWidth()/2-75,Menu_Background->getHeight()/3+0);
    button[1]->SetxyPos(Menu_Background->getWidth()/2-75,Menu_Background->getHeight()/3+115);
    button[2]->SetxyPos(Menu_Background->getWidth()/2-75,Menu_Background->getHeight()/3+230);*/
    button[0]->loadFromFile("button1.1.1.png");
    button[1]->loadFromFile("button1.1.2-removebg-preview.png");
    button[2]->loadFromFile("button1.1.3-removebg-preview.png");
    bool check1=false;
    bool check2=false;
    bool check3=false;
    do {


        //SDL_RenderClear(gRenderer);


        while ( SDL_PollEvent(&e) ) {

            switch (e.type) {
            case SDL_QUIT :
                return 0;
                break;
            case SDL_MOUSEMOTION:
                if ( check_in_button(e.motion.x, e.motion.y, button[0]->getRect()) ) {
                    if ( !check1  ) {
                        check1 = true;
                        button[0]->loadFromFile("button1.1.1.shadow.png");

                    }
                }
                else if ( check1 ) {
                    check1 = false;
                    button[0]->loadFromFile("button1.1.1.png");

                }

                if ( check_in_button(e.motion.x, e.motion.y, button[1]->getRect()) ) {
                    if ( !check2  ) {
                        check2 = true;
                        button[1]->loadFromFile("button1.1.2-removebg-preview.shadow.png");

                    }
                }
                else if ( check2 ) {
                    check2 = false;
                    button[1]->loadFromFile("button1.1.2-removebg-preview.png");

                }

                if ( check_in_button(e.motion.x, e.motion.y, button[2]->getRect()) ) {
                    if ( !check3  ) {
                        check3 = true;
                        button[2]->loadFromFile("button1.1.3-removebg-preview.shadow.png");
                    }
                }
                else if ( check3 ) {
                    check3 = false;
                    button[2]->loadFromFile("button1.1.3-removebg-preview.png");
                }

                break;
            case SDL_MOUSEBUTTONDOWN :

                    if ( check_in_button(e.button.x, e.button.y, button[0]->getRect() )) {

                        //button.clear();

                            return 1;
                    }

                   else if ( check_in_button(e.button.x, e.button.y, button[1]->getRect() )) {

                        //buttons.clear();

                            return 2;
                    }

                    else if ( check_in_button(e.button.x, e.button.y, button[2]->getRect() )) {

                        //buttons.clear();

                            return 3;
                    }

                break;
            default:
                break;
            }
        }

        //deco->update();

        //menu_background->draw();
        //game_title1.draw();
        //game_title2.draw();

       // deco->draw();
        int x2 = 0;
        Menu_Background->render(0,0);
        for ( int i = 0; i < 3; i++ ) {

            button[i]->render(Menu_Background->getWidth()/2-75,Menu_Background->getHeight()/3+x2);
            x2+=115;
        }

        SDL_RenderPresent(gRenderer);
    } while ( true );
    return 0;

}


void Game::Option()
{
    LTexture*Menu_Background=new LTexture();
    Menu_Background->loadFromFile("menu.jpg");

    TextInOption=new TextOption();

    Menu_Background->render(0,0);
    TextInOption->render();


}
