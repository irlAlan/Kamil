#include "Kamil/TextBox.h"
#include <iostream>
#include <Kamil/EditorWindow.h>


int main()
{
      sf::RenderWindow window(sf::VideoMode(640, 480), "SFML = <3");

      TextBox text;
      EditorWindow editor{window, text};
      window.setFramerateLimit(60); 
  
  
      sf::Clock deltaClock;
      while (window.isOpen()) {
          sf::Event event;
          while (window.pollEvent(event)) {
  
              if (event.type == sf::Event::Closed) {
                  window.close();
              }
          }
  
  
          window.clear();
          editor.draw();
          window.display();
      }
      return 0;
}
  
