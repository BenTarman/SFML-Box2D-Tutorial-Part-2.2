#pragma once
#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>

#include "gameState.h"


class PlayState : public GameState
{
public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    PlayState(Game* game);

private:
    void PauseGame();


};

#endif /* GAME_STATE_EDITOR_HPP */