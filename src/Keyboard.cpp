#include <Kamil/Keyboard.h>
#include <Kamil/Editor.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


Keyboard::Keyboard(sf::RenderWindow* win, sf::Vector2f bounds)
    :window{win}
    ,bounds{bounds}
{
}


void Keyboard::handleEvent(sf::Event& event){
    if(event.type == sf::Event::TextEntered){
        if(event.text.unicode < 256){
            std::cout << std::hex << event.text.unicode << ' ' << '\n' ;
            switch(event.text.unicode){
                case KEYS::ENTER:
                    tEntered += "\n";
                    if(tEntered.size() >= getBounds().x-5){
                        tEntered += "\n";
                    }
                    tEntered += static_cast<char>(event.text.unicode);
                   break; 
                case KEYS::BS:
                    backSpace();
                    break;
               //  case KEYS::DELETE:
               //      deleteKey();
               default:
                    tEntered += static_cast<char>(event.text.unicode);
                    break;
            }
        }
    }
}

void Keyboard::backSpace(){
    std::string tmp{};
    size_t endPos{tEntered.length()-1};

    for(size_t i{0}; i <= endPos; i++){
        if(i == endPos){
            tDeleted += tEntered[endPos];
        }
    }
    for(size_t i{0}; i < endPos; i++){
        tmp += tEntered[i];
//        tmp += "";
    }
    tEntered = "";
    tEntered += tmp;
   if (tmp.length() < 1) {
     tEntered += " ";
   }
}


sf::Vector2f Keyboard::getBounds() const{
    return bounds;
}


bool Keyboard::isKeyPressed(sf::Keyboard::Key key){
    return sf::Keyboard::isKeyPressed(key);
}


bool Keyboard::isTextEntered(){
    return !tEntered.empty();
}

bool Keyboard::isTextDeleted(){
    bool check{isKeyPressed(sf::Keyboard::Key::Delete)};
    return check;
}
std::string Keyboard::getTextEntered(){
    std::string text = tEntered;
    return text;
}

void Keyboard::setTextEntered(std::string nstring){
    tEntered = nstring;
}
