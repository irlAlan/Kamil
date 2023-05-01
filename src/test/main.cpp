#include <SFML/Graphics/Color.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <SFML/Graphics.hpp>


void deleteChar(int char_typed, std::ostringstream& inputStringBuffer, std::ostringstream* deleteStringBuffer){
    std::string str{inputStringBuffer.str()};
    std::string newString{};
    newString.append(str);
    char val{newString.back()};
    *deleteStringBuffer << val;
    newString.pop_back();
}

void deleteOtherChar(int char_typed, sf::Text* text, std::string& inputStringBuffer, std::string* deleteStringBuffer){
    std::string str{inputStringBuffer};
    std::string newString{};
    std::string valEnd{};
    for(int i{0}; i < str.length() -2;i++){
        newString += str[i];
    }
    inputStringBuffer = "";
    inputStringBuffer += newString;
    for(int i{0}; i < str.length();i++){
        if(i == str.length()-2){
            valEnd = str[i];
            //std::cout << "     VAL END: " << valEnd << '\n';
        }
    }
    *deleteStringBuffer += valEnd;
    // std::cout << deleteStringBuffer->str() << ' ';
    text->setString(inputStringBuffer + "_");
}

int main(){
//      pid_t c_fork{fork()};
//      if(c_fork < 0){
//          std::cout << "FORK ERROR\n";
//          std::exit(EXIT_FAILURE);
//      }
//      else if(c_fork > 0){
//          std::cout << "Parent process " << getpid() << '\n';
//      }
//      else{
//          std::cout << "child process " << getpid() << '\n';
//          char elt[]{"alacritty"};
//          char* args[]{elt, NULL};
//          execvp(args[0],args);
//      }
//  
//      std::cout << "Ending......";

    sf::RenderWindow window{sf::VideoMode(700,500), "Window"};
    sf::Event event;

    std::string textEntered;
    std::string deleteString;
    sf::Uint32 char_typed;
    sf::Text text;
    sf::Font font;
    if(!font.loadFromFile("../arial.ttf"))
        std::cout <<"FONT FAILED TO LOAD\n";
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(20);
    text.setFont(font);
    text.setPosition(20.f,20.f);
    int val{0};
    while(window.isOpen())
    {
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::TextEntered){
                char_typed = event.text.unicode;
                if(char_typed <= 256){
                    textEntered += static_cast<char>(char_typed);
                    text.setString(textEntered + "-");
                    if(char_typed == 0x8){
                        deleteOtherChar(char_typed, &text, textEntered, &deleteString);
                    }
                }

            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }


    return 0;
}


// int main(int argc, char* argv[]){
//     std::cout << argv[1];
//     std::ostringstream strings;
//     std::string final{"alacritty"};
//     strings << argv[1];
//     final += " -e " + strings.str() + " hey.py";
//     popen(final.c_str(), "r");
//     return 0;
// }
