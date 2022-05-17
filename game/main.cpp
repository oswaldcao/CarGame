#include"game.h"
int main(int argc, char* argv[]){
    Game* testgame=new Game();
    testgame->init();
    testgame->SetUpGame();
    while(true){
        //srand(time(0));

        int choice = testgame->MakeMenu();
        if (choice==1){
            while(true){
                SDL_RenderClear(Game::gRenderer);
                testgame->Update();
                testgame->Rendergame();
                testgame->GamePlay();

                SDL_RenderPresent(Game::gRenderer);
            }


        }
        if (choice==2){
                while(true){
                    SDL_RenderClear(Game::gRenderer);
                    testgame->Option();
                    SDL_RenderPresent(Game::gRenderer);
                    SDL_PollEvent(&Game::e);
                    if(Game::e.type==SDL_KEYDOWN){
                        if(Game::e.key.keysym.sym==SDLK_SPACE){
                            break;
                        }
                    }
                }

        }
        if (choice==3){
                testgame->close();

        }


    }

    return 0;
}
