#include <Kamil/MyRect.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>

        
MyRect::MyRect(){

}

MyRect::MyRect(sf::Vector2f pos, sf::Vector2f size, sf::Color fill, sf::Color outLine, float thicc)
    : fRect{pos.x, pos.y, size.x, size.y}
    , pos{pos}
    , size{size}
    , fillColour{fill}
    , outlineColour{outLine}
    , outlineThicknes{thicc}
{
}


void MyRect::draw(sf::RenderTarget& target, sf::RenderStates states) const{
     sf::RectangleShape rec;
     rec.setSize(size);
     rec.setPosition(pos);
     rec.setFillColor(fillColour);
     target.draw(rec);
}


void MyRect::setPosition(sf::Vector2f pos){
    left = pos.x;
    top = pos.y; 
    pos = pos;
}

sf::Vector2f MyRect::getPos()const{
    return pos;
}

void MyRect::setFillColour(sf::Color col){
   fillColour = col; 
}

void MyRect::setSize(sf::Vector2f size){
    width = size.x;
    height = size.y;
    size = size;
}

sf::Vector2f MyRect::getSize()const{
    return size;
}
