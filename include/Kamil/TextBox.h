#ifndef KAMIL_TEXTBOX_HPP
#define KAMIL_TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <sstream>
#include <iostream>


#define ENTER 0xD
#define DELETE 0x8
#define UP_ARROW 0x41

class TextBox{
    public:
        TextBox();
        TextBox(sf::Font&, int, sf::Color);
        
        void setTextSize(int);
        int getTextSize()const;
        void setFontFill(sf::Color);
        sf::Color getFontFill()const;
        void setFont(sf::Font&);
        sf::Text getTextBox()const;

        void typedOn(const sf::Event&);

        // TODO: Move all functions that manipulate teh text i.e. change colour and size
        // to its own class that will handle all the commands and special key things
        // the TextBox class will inherit from this and then used in the input logic
        // or the input logic ill also move to that class and will use a pointer to teh
        // textbox class
        void increaseTextSize(int);
        void decreaseTextSize(int);
    private:

        void inputLogic(int);

        sf::Text m_textbox{};
        sf::Font m_font{};
        int m_textsize{};
        sf::Color m_fontfill{};
        std::ostringstream m_osstream{};

};


#endif // KAMIL_TEXTBOX_HPP
