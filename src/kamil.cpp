#include "Kamil/TextBox.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <Kamil/EditorWindow.h>


int main()
{
      sf::RenderWindow window(sf::VideoMode(640, 480), "SFML = <3");

      sf::Event event;
      TextBox text;
      EditorWindow editor{window, text};
      window.setFramerateLimit(60); 
  
        int size{12}; 
      sf::Clock deltaClock;
      while (window.isOpen()) {
          while (window.pollEvent(event)) { 
              switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::TextEntered:
                    text.typedOn(event);
                    break;
                case sf::Event::KeyPressed:
//                    if(sf::Keyboard::Key::A){
//                        text.setTextSize(size+=1);
//                    }
                default:
                    break;
              }
          }
  
  
          window.clear();
          editor.draw();
          window.display();
      }
      return 0;
}
  
