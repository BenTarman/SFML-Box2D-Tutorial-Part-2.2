#include "SFML/Graphics.hpp"

#include <iostream>

#include "MenuState.h"
#include"gameState.h"
#include "PlayState.h"


MenuState::MenuState(Game* game)
{
    menuScreen.AddResource("MenuImage"); //add MenuImage
    menuSprite.setTexture(*(menuScreen.GetResource("MenuImage")));

    //Text stuff
    sf::Text text;
    font.loadFromFile("data/arial.ttf");
    text.setFont(font);
    text.setPosition(100, 100);
    text.setCharacterSize(24); // in pixels, not points!                         
    text.setColor(sf::Color::White);   // set the color  
    text.setStyle(sf::Text::Bold); // set the text style

    //set positions of things
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        buttons.push_back(text);
        buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * 100);
    }

    //Since it's only 3 text its fine to just manually set each...
    buttons[0].setString("Play Game");
    buttons[1].setString("Options");
    buttons[2].setString("Quit");

    //TEMPORARY TO:DO DELETE THIS AND EDIT IMAGE APPRORIATELY
    sf::Vector2f targetSize(800.0f, 600.0f);
    menuSprite.setScale(targetSize.x / menuSprite.getLocalBounds().width, targetSize.y / menuSprite.getLocalBounds().height);


    this->game = game;
}


void MenuState::handleInput()
{
    sf::Event event;
    
    while (game->window.pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
        case sf::Event::Closed:
            game->window.close();
            break;

            /* Change Between game states */
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                game->window.close();
            else if (event.key.code == sf::Keyboard::Return)
                loadgame();
            break;

            //clickable text
        case sf::Event::MouseMoved:
            if (isTextClicked(buttons[0]))
                buttons[0].setColor(sf::Color::Red);
            else
                buttons[0].setColor(sf::Color::White);
            if (isTextClicked(buttons[1]))
                buttons[1].setColor(sf::Color::Red);
            else
                buttons[1].setColor(sf::Color::White);
            if (isTextClicked(buttons[2]))
                buttons[2].setColor(sf::Color::Red);
            else
                buttons[2].setColor(sf::Color::White);
            break;
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (isTextClicked(buttons[0]))
            loadgame();
        else if (isTextClicked(buttons[2]))
            game->window.close();

        
    }

}


void MenuState::update(const float dt)
{

}


void MenuState::draw(const float dt)
{
    game->window.draw(menuSprite);

    //draw text
    for (auto x : buttons)
        game->window.draw(x);
}


void MenuState::loadgame()
{

    game->pushState(new PlayState(game));


}


bool MenuState::isTextClicked(sf::Text text) 
{
    sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

    //If mouse position is in the rectangle do whatever
    if (rect.contains(sf::Mouse::getPosition(game->window)))
        return true;


    //Otherwise, don't do anything
    return false;
}