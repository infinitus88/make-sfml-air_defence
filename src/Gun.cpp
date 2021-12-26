#include "Gun.hpp"

#include <iostream>
#include <cmath>

namespace AD_Engine {
    Gun::Gun(GameDataRef data) : _data(data) { 

        _gunShape.setSize(sf::Vector2f(100, 15));
        _gunShape.setFillColor(sf::Color::Black);
        _gunShape.setOrigin(this->_gunShape.getLocalBounds().width, this->_gunShape.getLocalBounds().height / 2);
        _gunShape.setPosition(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / 2);

        _baseShape.setFillColor(sf::Color::Black);
        _baseShape.setRadius(25.0f);
        _baseShape.setOrigin(_baseShape.getLocalBounds().height / 2, _baseShape.getLocalBounds().width / 2);
        _baseShape.setPosition(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / 2);
    }

    Gun::~Gun() { }

    void Gun::Update(float dt) {
        
        sf::Vector2i mousePosition = this->_data->input.GetMousePosition(this->_data->window);
        sf::Vector2i directionVector = sf::Vector2i(_gunShape.getPosition().y - mousePosition.y, _gunShape.getPosition().x - mousePosition.x);
        float angleInRadians = std::atan2(directionVector.x, directionVector.y);
        float angleInDegrees = (angleInRadians / M_PI) * 180.0f;
        this->_gunShape.setRotation(angleInDegrees);
        std::cout << this->_gunShape.getRotation() << std::endl;
    }

    void Gun::Draw()
    {
        _data->window.draw(_baseShape);
        _data->window.draw(_gunShape);
    }
}