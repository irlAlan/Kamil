#ifndef KAMIL_MYRECT_H
#define KAMIL_MYRECT_H


/**
 * @file MyRect.h
 *
 * @brief Interface file for the MyRect class
 *
 * Inherits from sf::FloatRect and sf::Drawable.
 * sf::FloatRect  is a templated class of sf::Rect<float> and its primary use is for defining
 * the border and creating a hollow rectangle, as such it only has methods for collision detection and intersections.
 * The normal RectangleShape class creates a basic rectangle without the collision and intersections checking so we inherit 
 * this functionality from FloatRect and in effect add it to the instantiated RectangleShape in the MyRect class.
 *
 * The sf::Drawable is only here to add a draw property to our class so when we draw to the RenderTarget, in this case RenderWindow,
 * we can use the same code of window.draw(our_own_object) instead of the general our_own_object.draw(window). This is done so when others use
 * this code it makes it easier for them to follow a standard way of drawing to the RenderTarget and not having to worry about passing parameters
 * into the objects. 
 * 
 */



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
        MyRect(sf::Vector2f pos, sf::Vector2f size, sf::Color fillColour, sf::Color outlineColour, float outlineThicknes);
        MyRect();

        /**
         * @brief sets the position of rect
         * @param sf::Vector2f pos
         */
        void setPosition(sf::Vector2f pos);

        /**
         * @brief get the position of rect
         * @return sf::Vector2f pos
         */
        sf::Vector2f getPos()const;

        /**
         * @brief set the fill colour of the rect
         * @param sf::Color colour
         */
        void setFillColour(sf::Color colour);

        /**
         * @brief set the size of the rect
         * @param sf::Vector2f size
         */
        void setSize(sf::Vector2f size);

        /**
         * @brief get the size of the rect
         * @return sf::Vector2f  size
         */
        sf::Vector2f getSize()const;

        /**
         * @brief virutal method to draw to window
         *
         * Inherited from sf::Drawable it is what allows us to draw to the screen
         * using window.draw(MyRect); instead of MyRect.draw(window)
         * keeping similar drawing standard to base SFML code making our class more modular
         * and familiar to those who use SFML
         *
         * Example of polymorphism
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

    protected:
        sf::FloatRect fRect; /**< for collision checking */
        sf::Vector2f pos; /**< position of rect */
        sf::Vector2f size; /**< size of rect */
        sf::Color fillColour; /**< colour of rect */
        sf::Color outlineColour; /**< outline colour of rect */
        float outlineThicknes; /**< outline thickness of rect */

};

#endif // KAMIL_MYRECT_H

