#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include "TextureManager.h"
#include <SFML/Graphics.hpp>

#include "gameState.h"  //we will be deriving this abstract classes functions.



class MenuState : public GameState  //make GameState functions public to this class so we can derive it's functions.
{
public:
    //constructor (compiler will automatically make a default one)
    MenuState(Game* game);

    //the three functions are teh three things we must do.
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

private:
    bool isTextClicked(sf::Text text);
    //let's make a view for this just in case we want it
    sf::View view;
    TextureManager menuScreen;  //menuScreen variable
    sf::Sprite menuSprite;
    

    //this will be used to change the game state to the "Play the actual fucking game" state.
    void loadgame();

    std::vector<sf::Text> buttons;
    sf::Font font;

    const int NUM_BUTTONS = 3;
};

#endif /* GAME_STATE_START_HPP */