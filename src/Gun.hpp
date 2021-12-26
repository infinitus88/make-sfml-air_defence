#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

#include <vector>

namespace AD_Engine {
    
    class Gun {
    public:
        Gun(GameDataRef data);
        ~Gun();

        void Draw();
        
        void Animate(float dt);

        void Update(float dt);

        void Tap();

    private:
        GameDataRef _data;
        
        sf::RectangleShape _gunShape;
        sf::CircleShape _baseShape;

        sf::Vector2i _direction;
    };
}