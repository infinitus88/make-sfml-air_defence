#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace AD_Engine {

    struct GameData {

        StateMachine machine;
        sf::RenderWindow window;
        InputManager input;
        AssetManager assets;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
        
    public:
        Game(int width, int height, std::string title);

    private:
        // Updates run at 60 per second.
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData>();

        void Run();
    };
}