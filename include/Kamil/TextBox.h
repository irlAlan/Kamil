#ifndef KAMIL_TEXTBOX_HPP
#define KAMIL_TEXTBOX_HPP

/**
 * @file Interface file for the TextBox class
 *
 * @brief Creates a text box in SFML 
 * 
 * A class that inherits from MyRect class and defines a basic text box in SFML.
 * Allows for integrated use with other SFML objects as it has an sf::Drawable property
 * that allows it to nativly draw to a render target like every other SFML object through the shared
 * inheritance with sf::Drawable from MyRect.
 *
 * For the text box in SFML to work we use the size and position passed into the class constructor 
 * to create an sf::RectangleShape object and use it as the boundries of the text box while still drawing to the 
 * screen with an sf::Text object.
 *
 */

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "Keyboard.h"
#include "MyRect.h"

/**
 * @brief A class that makes a Textbox in SFML
 *
 * The class creates a textbox for inputting and handling text and Keyboard
 * commands and allows the use of commands in the secondary textbox cmdbox
 */
class TextBox : public MyRect {
public:
  /**
   * @brief Constructor for TextBox
   * @param win - RenderWindow the TextBox is drawn onto
   * @param pos - the initial position of the TextBox
   * @param size - the initial size of the TextBox
   * @param sfont - the initial font used by the TextBox
   * @param fsize - the inital font size
   * @param fcol - the initial font colour
   * @param background - the initial background colour
   * @param thicc - the padding for the RectangleShape
   *
   * \image latex textConstructor.eps
   */
  TextBox(sf::RenderWindow *win, sf::Vector2f pos, sf::Vector2f size,
          std::string sfont, int fsize, sf::Color fcol, sf::Color background,
          float thicc);
  TextBox();


  /**
   * @brief Set the size of the text
   *
   * A setter method that sets the size of the text
   *
   * @param size text size
   * @return void
   *
   * \image latex textSetTextSize.eps
   */
  void setTextSize(int size);

  /**
   * @brief Get the size of the text
   *
   * A getter method that returns the size of the text
   *
   * @param void
   * @return an int of the text size
   *
   *
   *  \image latex textGetTextSize.eps
   */
  int getTextSize() const;

  /**
   * @brief Set the colour of the text
   *
   * A setter mehod that sets the colour of the text
   *
   * @param fill font colour
   * @return void
   *
   *
   *  \image latex textSetTextCol.eps
   *
   */
  void setTextColour(sf::Color colour);

  /**
   * @brief Get the colour of the text
   *
   * A getter method that returns the colour of the text
   *
   * @param void
   * @return sf::Colour textColour
   *
   *  \image latex textGetTextCol.eps
   */
  sf::Color getTextColour() const;

  /**
   * @brief set what font you want to use
   *
   * A setter method overload of setFont function that sets the font using
   * an object of type sf::Font
   *
   * @param font file dir of font
   * @return void
   *
   *
   * \image latex textSetFont.eps
   */
  void setFont(sf::Font &font);

  
  /**
   * @brief set what font you use
   *
   * A setter method overload of setFont function that sets the font
   * Allows the passing of strings instead of sf::Font types.
   *
   * @param font file dir of font
   * @return void
   *
   * \image latex textSetFont2.eps
   */
  void setFont(std::string font);

  /**
   * @brief Get sf::Text of the textbox
   *
   * A getter method for getting the sf::Text part of the TextBox class
   * this is the part responsible for displaying all the text
   *
   * @param void
   * @return sf::Text - contains the part responsible for drawing text on the screen
   *
   *  \image latex textGetTextBox.eps
   *
   */
  sf::Text getTextBox() const;

  /**
   * @brief Sets the string
   *
   * A setter method that sets the string
   * that is displayed on the screen
   *
   * @param std::string - new string placed on tbox
   * @return void
   *
   * \image latex textSetString.eps
   *
   */
  void setString(std::string nstring);

  /**
   * @brief returns the text in tbox
   *
   * A getter method that returns the string 
   * thats displayed on the screen
   *
   * @param void
   * @return type std::string
   *
   * \image latex textGetString.eps
   */
  std::string getString() const;

  /**
   * @brief used to draw to the screen
   * virutal method inherited from MyRect which inherited it from sf::Drawable thats overrided here
   * it is an example of polymorphism as we are changing the behaviour of a method in the child class.
   * By inheriting from sf::Drawable it allows us to keep a similar syntax to other SFML shapes and drawable objects
   * window.draw(my_object).
   * This allows our code to be more modular and easy for other people to use since they dont need to fumble around with
   * my_object.draw(window)
   *
   *
   * \image latex textDraw.eps
   *
   */
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  /**
   * @brief check if mouse is hovering over current textbox
   *
   * Useful for when you want specific events to happen only when the mouse hovers over
   * like text inputting.
   *
   * We are able to check if the mouse is hovering through the extra collision functionality that FloatRect
   * gives us. see MyRect
   * 
   * @return bool - yes if hovering over the text box
   *
   * \image latex textIsMouseHover.eps
   *
   */
  bool isMouseHover();

private:
  sf::RenderWindow *window; /**< pointer to the main RenderWindow variable */
  sf::Text tbox{};          /**< the text that everything is written onto */
  sf::Font font{};          /**< the font that the TextBox uses */
  std::string fname{};      /**< the name of the font used */
  int fsize{};              /**< the font size */
  sf::Color fcol{};         /**< the font colour */
  bool mouseHover;          /**< if the mouse is hovering over */
};
#endif // KAMIL_TEXTBOX_HPP
