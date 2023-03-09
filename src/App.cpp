#include <Kamil/App.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


App::App(uint16_t width, uint16_t height)
    : mWindow({width,height}, "My App")
{
    mWindow.setFramerateLimit(60);
}


void App::run(){
    sf::Clock clock;
    // sf::Clock other;
    // sf::Time timeSinceLastUpdate = sf::Time::Zero;
    // sf::Time timePerFrame{sf::seconds(1.0f / 60.0f)};

    while(mWindow.isOpen()){
        processEvents();
        update(clock.restart());
        render();
    }
}


void App::processEvents(){
    while(mWindow.pollEvent(mEvent)){
        switch(mEvent.type)
        {
            case sf::Event::KeyPressed:
                handleUserInput(mEvent.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handleUserInput(mEvent.key.code, false);
                break;
            case sf::Event::Closed:
                closeApp();
            default:
                break;
        }
    }
}

void App::update(sf::Time dt){}

void App::render(){
        mWindow.clear(sf::Color::Black);
//        mWindow.draw(mUser);
        mWindow.display();
}


void App::handleUserInput(sf::Keyboard::Key key,bool isPressed){
    switch(key){
        case sf::Keyboard::W:
            break;
        case sf::Keyboard::S:
            break; 
        case sf::Keyboard::D:
            break;
        case sf::Keyboard::A:
            break;
        case sf::Keyboard::Q:
            closeApp();
            break;
        default:
            break;
    }
}

void App::closeApp(){
    mWindow.close();
}
