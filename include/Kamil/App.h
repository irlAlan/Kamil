#ifndef KAMIL_App_HPP
#define KAMIL_App_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <SFML/Window/Keyboard.hpp>
#include <cstdint>

class App{
    public:
        App(uint16_t, uint16_t);
        void run();

    private:
        void processEvents();
        void closeApp();
        void render();
        void update(sf::Time);
        void handleUserInput(sf::Keyboard::Key, bool);

    private:
        sf::RenderWindow mWindow;
        sf::Event mEvent;
        
};


#endif // KAMIL_APP_HPP
