#ifndef KAMIL_MYRECT_H
#define KAMIL_MYRECT_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>


/**
 * @brief gives extra functionality to FloatRect
 *
 * Uses FloatRect for the ability to collision detect better than RectangleShape
 * and inherits from Drawable so we are able to keep uniform sytax of window.draw(Drawable object)
 */
class MyRect : public sf::FloatRect
             , public sf::Drawable
{
    public:
        /**
         * @brief constructor for MyRect
         * @param pos - position of rect
         * @param size - size of rect
         * @param fillColour - fill colour of rect
         * @param outlineColour - ouline colour of rect
         * @param outlineThicknes - outline thickness of rect
         */
        MyRect(sf::Vector2f, sf::Vector2f, sf::Color, sf::Color, float);

        /**
         * @brief sets the position of rect
         * @param sf::Vector2f pos
         */
        void setPosition(sf::Vector2f);

        /**
         * @brief get the position of rect
         * @return sf::Vector2f pos
         */
        sf::Vector2f getPos()const;

        /**
         * @brief set the fill colour
         * @param sf::Color colour
         */
        void setFillColour(sf::Color);

        /**
         * @brief set the size
         * @param sf::Vector2f size
         */
        void setSize(sf::Vector2f);

        /**
         * @brief get the size
         * @return sf::Vector2f  size
         */
        sf::Vector2f getSize()const;

        /**
         * @brief draw to window
         *
         * virutal method inherited from sf::Drawable
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

    protected:
        sf::FloatRect fRect; /**< for collision checking */
        sf::Vector2f pos;
        sf::Vector2f size;
        sf::Color fillColour;
        sf::Color outlineColour;
        float outlineThicknes;

};

#endif // KAMIL_MYRECT_H

