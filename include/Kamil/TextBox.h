#ifndef KAMIL_TEXTBOX_HPP
#define KAMIL_TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include <iostream>

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
    private:
        sf::Text m_textbox{};
        sf::Font m_font{};
        int m_textsize{};
        sf::Color m_fontfill{};

};


#endif // KAMIL_TEXTBOX_HPP
