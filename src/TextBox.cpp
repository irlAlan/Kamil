#include <Kamil/TextBox.h>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>


TextBox::TextBox()
{

    // Loading font
    m_font.loadFromFile("../resource/fonts/arial.ttf");
    m_fontfill = sf::Color::Red;
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



void TextBox::inputLogic(int char_typed){
    switch(char_typed){
        case ENTER:
            m_osstream << " Enter ";
            break;
        case DELETE:
            m_osstream << " Delete ";
            break;
        case UP_ARROW:
            increaseTextSize(1);
            break;
        default:
            m_osstream << static_cast<char>(char_typed);
            break;
    }
    m_textbox.setString(m_osstream.str() + '-');
    std::cout << m_textsize;
}

void TextBox::typedOn(const sf::Event& event){
    int char_typed = event.text.unicode;
    if (char_typed <= 256) // only allow up to extended ascii
        inputLogic(char_typed);
}


void TextBox::increaseTextSize(int size){
    m_textsize += size;
    m_textbox.setCharacterSize(getTextSize());
}
void TextBox::decreaseTextSize(int size){
    m_textsize -= size;
    m_textbox.setCharacterSize(getTextSize());
}


void TextBox::setFont(sf::Font &font){m_font = font;}

void TextBox::setTextSize(int size){m_textsize = size;}
int TextBox::getTextSize()const{return m_textsize;}

void TextBox::setFontFill(sf::Color fill){m_fontfill = fill;}
sf::Color TextBox::getFontFill()const{return m_fontfill;}
sf::Text TextBox::getTextBox()const{
    return m_textbox;
}



