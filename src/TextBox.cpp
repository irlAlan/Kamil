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
   *  setting  up the text and font
   */
  font.loadFromFile(fname);
  tbox.setFont(font);
  tbox.setCharacterSize(fsize);
  tbox.setFillColor(fcol);
  tbox.setPosition(pos.x, pos.y);
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    /**
     * An example of polymorphism, we are inheriting a virtual method from sf::Drawable
     * and overriding its behaviour here
     */
    target.draw(rect);
    target.draw(tbox);
}

bool TextBox::isMouseHover() {
    // checking if the mouse position is in the textbox rectangle
  sf::Vector2i mousePos{sf::Mouse::getPosition(*window)};
  sf::Vector2f worldPos{window->mapPixelToCoords(mousePos)}; // turning the pixels into coordinates
  if (sf::FloatRect::contains(worldPos))
    return true;
  return false;
}

void TextBox::setString(std::string nstring) { 
    sf::String val{nstring};
    tbox.setString(val.toWideString());  // allow wider characters like japanese characters
                                         // for future language expansion
}

std::string TextBox::getString() const { return tbox.getString(); }

void TextBox::setFont(sf::Font &font) { font = font; }

void TextBox::setFont(std::string fnt) {
    // overload function for setFont
    try{
        font.loadFromFile(fnt); // see if we can load the file
    }
    catch(...){
        std::cerr << "Cannot load font from file\n"; // if we arent able to load it
    }
}


void TextBox::setTextSize(int size) { fsize = size; }

int TextBox::getTextSize() const { return fsize; }

void TextBox::setTextColour(sf::Color fill) { fcol = fill; }

sf::Color TextBox::getTextColour() const { return fcol; }

sf::Text TextBox::getTextBox() const { return tbox; }
// get the sf::Text that draws text to teh screen
