#include "Kamil/MyRect.h"
#include <Kamil/TextBox.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

/**
 * Implementation of the TextBox class
 * @note other structs or classes may be used here
 */

/**
 * @brief Constrcutor Implementation for TextBox class
 * @param win - RenderWindow the TextBox is drawn onto
 * @param pos - the initial position of the TextBox
 * @param size - the initial size of the TextBox
 * @param sfont - the initial font used by the TextBox
 * @param fsize - the inital font size
 * @param fcol - the initial font colour
 * @param background - the initial background colour
 * @param thicc - the padding for the RectangleShape
 */


// Change the way we store the text into a 2d vector of strings


TextBox::TextBox(sf::RenderWindow* win, sf::Vector2f pos, sf::Vector2f size, std::string sfont, int fsize, sf::Color fcol, sf::Color background, float thicc)
    : MyRect(pos, size,background, background, thicc)
    , window{win}
    , fname{sfont}
    , fsize{fsize}
    , fcol{fcol}
{

  /**
   * @brief setting  up the text and font
   */
  font.loadFromFile(fname); 
  tbox.setFont(font); 
  tbox.setCharacterSize(fsize);
  tbox.setFillColor(sf::Color::Black);
  tbox.setPosition(15.0f,0.0f);
}
        
void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states)const {    
     sf::RectangleShape rec;
     rec.setSize(size);
     rec.setPosition(pos);
     rec.setFillColor(fillColour);
     window->draw(rec);
     window->draw(tbox);
}

bool TextBox::isMouseHover(){
    sf::Vector2i mousePos{sf::Mouse::getPosition(*window)};
    sf::Vector2f worldPos{window->mapPixelToCoords(mousePos)};
    if(fRect.contains(worldPos))
        return true;
    return false;
}


void TextBox::setString(std::string nstring){
    tbox.setString(nstring);
}

std::string TextBox::getString()const{
    return tbox.getString();
}


void TextBox::setFont(sf::Font& font) {
  font = font;
}

void TextBox::setTextSize(int size) {
  fsize = size;
}
int TextBox::getTextSize() const {
  return fsize;
}

void TextBox::setTextColour(sf::Color fill) {
  fcol = fill;
}
sf::Color TextBox::getTextColour() const {
  return fcol;
}

sf::Text TextBox::getTextBox() const {
  return tbox;
}
