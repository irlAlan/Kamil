#include <Kamil/TextBox.h>
#include <SFML/Graphics/Font.hpp>


TextBox::TextBox()
{

    // Loading font
    m_font.loadFromFile("../resource/fonts/arial.ttf");
    m_fontfill = sf::Color::Black;
    m_textsize = 16;

    //setting  text
    m_textbox.setFont(m_font);
    m_textbox.setCharacterSize(m_textsize);
    m_textbox.setFillColor(m_fontfill);

}


TextBox::TextBox(sf::Font &font, int size, sf::Color colour)
    : m_font(font), m_textsize(size), m_fontfill(colour)
{

    //setting  text
    m_textbox.setFont(m_font);
    m_textbox.setCharacterSize(m_textsize);
    m_textbox.setFillColor(m_fontfill);
}


void TextBox::setFont(sf::Font &font){m_font = font;}

void TextBox::setTextSize(int size){m_textsize = size;}
int TextBox::getTextSize()const{return m_textsize;}

void TextBox::setFontFill(sf::Color fill){m_fontfill = fill;}
sf::Color TextBox::getFontFill()const{return m_fontfill;}
sf::Text TextBox::getTextBox()const{
    return m_textbox;
}



