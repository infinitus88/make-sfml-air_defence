#include "Land.hpp"
#include "DEFINITIONS.hpp"

namespace AD_Engine {
    
    Land::Land(GameDataRef data) : _data(data) {
        this->_landSprite = sf::Sprite(this->_data->assets.GetTexture("Land"));
    }

    void Land::DrawLand() {
        this->_data->window.draw(_landSprite);
    }
}