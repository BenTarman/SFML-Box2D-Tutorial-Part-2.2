#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.h" //doesn't' exist yet

class GameState
{
public:
   
    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;

protected:
    Game* game;
  
};

#endif /* GAME_STATE_HPP */