#include "game.h"
#include "MenuState.h" //this doens't exist yet



const int WINDOWS_HEIGHT = 1024;

int main()
{
    Game game; //create game object (so far this constructor just intiializes our window)

               //we will call our menu class "MenuState"
    game.pushState(new MenuState(&game));  //we want to create a pointer at the game objects address. this will enter our menu.

                                           //now loop our game.
    game.gameLoop();

    
    
    return 0;
}
