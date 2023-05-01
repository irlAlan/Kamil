#include <Kamil/Editor.h>
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include <fmt/core.h>

// Move the Number Lines into a seperate struct that is with teh textBox

Editor::Editor(sf::RenderWindow* window, sf::Event* event)
    :window(window)
    , event{event}
    , textBox{ new TextBox{window,sf::Vector2f{15.f,0.f},sf::Vector2f{(float)window->getSize().x, (float)window->getSize().y-20},"../resource/fonts/arial.ttf",20, sf::Color::Black, sf::Color::White, 5}}
    , cbox{new CmdBox{window, sf::Vector2f{0.f,(float)window->getSize().y-15}, sf::Vector2f{(float)window->getSize().x, 15}, "../resource/fonts/arial.ttf", 15, sf::Color::Black, sf::Color::Blue, 5}}
    , kb{window, textBox->getSize()}
{
}

Editor::~Editor(){
    delete textBox;
}

void Editor::draw(){
    int charTyped;
    fmt::print("{}, {}\n", textBox->getPos().x, textBox->getPos().y);
    fmt::print("{}, {}\n", textBox->getSize().x, textBox->getSize().y);

    while(window->isOpen()){
        while(window->pollEvent(*event)){
            switch(event->type){
                case sf::Event::Closed:
                    window->close();
                    break; 
                default:
                    break;
            }
            kb.handleEvent(*event);
        }


        if(textBox->isMouseHover()){
            if(kb.isTextEntered()){
                textBox->setString(kb.getTextEntered() + "-");
            }
        }

        if(cbox->isMouseHover()){
            if(kb.isTextEntered()){
                cbox->setString(kb.getTextEntered() + "-");
                if(kb.getTextEntered() == "open"){
                    fmt::print("open says me\n");
                }
            }
        }

        window->clear();
        window->draw(*textBox);
        window->draw(*cbox);
        // textBox->write();
//        textBox->draw();
        // cbox->draw(*window, sf::RenderStates::Default);
        window->display();
    }
}
