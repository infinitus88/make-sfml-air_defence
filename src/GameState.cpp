#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"

#include <iostream>

namespace AD_Engine {

    GameState::GameState(GameDataRef data) : _data(data) { }

    void GameState::Init() {
        gun = new Gun(_data);
    }

    void GameState::HandleInput() {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }

            if (this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window)) {
                std::cout << "Fire!" << std::endl;
            }
        }
    }

    void GameState::Update(float dt) {
        gun->Update(dt);
    }

    void GameState::Draw(float dt) {
        this->_data->window.clear(sf::Color::White);

        gun->Draw();

        this->_data->window.display();
    }
}