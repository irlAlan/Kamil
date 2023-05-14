#include <Kamil/MyRect.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>

MyRect::MyRect() {}

MyRect::MyRect(sf::Vector2f pos, sf::Vector2f size, sf::Color fill,
               sf::Color outLine, float thicc)
    : rect{pos}
    , sf::FloatRect{pos, size}
    , outlineColour{outLine}
    , fillColour{fill}
    , outlineThicknes{thicc}
    , pos{pos}
    , size{size}
   // : fRect{pos.x, pos.y, size.x, size.y}, pos{pos}, size{size},
   //   fillColour{fill}, outlineColour{outLine}, outlineThicknes{thicc}
   // , 
{
    rect.setPosition(pos);
    rect.setSize(size);
    rect.setFillColor(fill);
    rect.setOutlineThickness(thicc);
    rect.setOutlineColor(outLine);
}

void MyRect::draw(sf::RenderTarget &target, sf::RenderStates states) const {
}

void MyRect::setPosition(sf::Vector2f pos) {
    rect.setPosition(pos);
    sf::FloatRect::left = pos.x;
    sf::FloatRect::top = pos.y;
}

sf::Vector2f MyRect::getPos() const { return rect.getPosition(); }

void MyRect::setFillColour(sf::Color col) { 
    rect.setFillColor(col);
    fillColour = col;
}

void MyRect::setSize(sf::Vector2f size) {
    rect.setSize(size);
  width = size.x;
  height = size.y;
  size = size;
}

sf::Vector2f MyRect::getSize() const { return rect.getSize(); }
