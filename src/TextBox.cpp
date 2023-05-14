#include <Kamil/MyRect.h>
#include <Kamil/TextBox.h>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>

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

TextBox::TextBox(sf::RenderWindow *win, sf::Vector2f pos, sf::Vector2f size,
                 std::string sfont, int fsize, sf::Color fcol,
                 sf::Color background, float thicc)
    : MyRect(pos, size, background, background, thicc), window{win},
      fname{sfont}, fsize{fsize}, fcol{fcol} {

  /**
   * @brief setting  up the text and font
   */
  font.loadFromFile(fname);
  tbox.setFont(font);
  tbox.setCharacterSize(fsize);
  tbox.setFillColor(fcol);
  tbox.setPosition(pos.x, pos.y);
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect);
    target.draw(tbox);
//      rect.setFillColor(fillColour);
//      rect.setSize(size);
//      target.draw(rect);
// //   sf::RectangleShape rec;
// //   rec.setSize(size);
// //   rec.setPosition(pos);
// //   rec.setFillColor(fillColour);
  // window->draw(rect);
  // window->draw(tbox);
}

bool TextBox::isMouseHover() {
  sf::Vector2i mousePos{sf::Mouse::getPosition(*window)};
  sf::Vector2f worldPos{window->mapPixelToCoords(mousePos)};
  if (sf::FloatRect::contains(worldPos))
    return true;
  return false;
}

void TextBox::setString(std::string nstring) { 
    sf::String val{nstring};
    // std::string s = val.toUtf16();
    tbox.setString(val.toWideString()); 
}




std::string TextBox::getString() const { return tbox.getString(); }

void TextBox::setFont(sf::Font &font) { font = font; }
void TextBox::setFont(std::string fnt) {
    font.loadFromFile(fnt);
}


void TextBox::setTextSize(int size) { fsize = size; }
int TextBox::getTextSize() const { return fsize; }

void TextBox::setTextColour(sf::Color fill) { fcol = fill; }
sf::Color TextBox::getTextColour() const { return fcol; }

sf::Text TextBox::getTextBox() const { return tbox; }
