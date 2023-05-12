#ifndef KAMIL_TEXTBOX_HPP
#define KAMIL_TEXTBOX_HPP

/**
 * @file Interface file for the TextBox class
 *
 * Inherits from MyRect class and defines a basic text box in SFML
 * Allowd text to be written and deleted from it aswell has check if anything
 * is hovering over or selcted.
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

/*
 *
 * TODO:
 *       Make a RectangleShape that acts as the bounds of the TextBox
 *       then add limits to the textbox so it stays in the limits
 *
 *       Add the Keybord manager class here and use its methods
 *       to handle the key events
 */

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
   */
  TextBox(sf::RenderWindow *win, sf::Vector2f pos, sf::Vector2f size,
          std::string sfont, int fsize, sf::Color fcol, sf::Color background,
          float thicc);
  TextBox();

  /**
   * @brief Set the size of the text
   * @param size text size
   * @return void
   */
  void setTextSize(int size);

  /**
   * @brief Get the size of the text
   * @param void
   * @return an int of the text size
   */
  int getTextSize() const;

  /**
   * @brief Set the colour of the text
   * @param fill font colour
   * @return void
   */
  void setTextColour(sf::Color colour);

  /**
   * @brief Get the colour of the text
   * @param void
   * @return sf::Colour textColour
   */
  sf::Color getTextColour() const;

  /**
   * @brief set what font you use
   * @param font file dir of font
   * @return void
   */
  void setFont(sf::Font &font);

  /**
   * @brief Get both the Text
   * @param void
   * @return type Boxv2 that contains textbox and cmdbox
   */
  sf::Text getTextBox() const;

  /**
   * @brief Delete last character entered
   * @param void
   * @return void
   */
  void deleteChar();

  /**
   * @brief Handles Enter key press
   * @param void
   * @return void
   */
  void enterPress();

  /**
   * @brief Sets the string
   * @param nstring - new string placed on tbox
   * @return void
   */
  void setString(std::string nstring);

  /**
   * @brief returns the text in tbox
   * @param void
   * @return type std::string
   */
  std::string getString() const;

  /**
   * @brief used to draw to the screen
   * virutal method inherited from MyRect -> sf::Drawable thats overrided here
   * is what allows us to draw to window using window.draw(TextBox)
   *
   * Example of polymorphism
   */
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  /**
   * @brief check if mouse is hovering over current textbox
   * @return bool - yes if hovering
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
