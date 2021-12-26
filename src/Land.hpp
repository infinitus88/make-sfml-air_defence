#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace AD_Engine {
    
    class Land {
    public:
        Land(GameDataRef data);

        void DrawLand();

    private:
        GameDataRef _data;

        sf::Sprite _landSprite;
    };
}