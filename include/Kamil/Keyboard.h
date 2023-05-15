#ifndef KAMIL_KEYBOARD_H
#define KAMIL_KEYBOARD_H

/**
 * @file Keyboard.h
 *
 * @brief Interface file for Keyboard.h
 *
 * A class that handles all keyboard and mouse events for the editor
 * is responsible for manging input of keyboard data and their corresponding command
 */

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Document.h"
#include <fmt/core.h>

#include <array>
#include <sstream>

/**
 * @brief An enum for Keyboard characters in hex form
 *
 * Used for when we need to check if some characters are being entered into the textbox since
 * not all characters can be directly drawn to the screen but SFML will try to. 
 * We can intercept them here and change or mute their behaviour.
 */
namespace KEYS {
enum {
  ESCAPE = 0x1B,
  ENTER = 0xD,
  BS = 0x8,
  Shift_A = 0x41,
  CTRL = 0x11,
  DELETE = 0x7f,
  CR = 0x13,
  UP_ARROW = 0x48,
  DOWN_ARROW = 0x50,
  RIGHT_ARROW = 0x4D,
  LEFT_ARROW = 0x4B,
};
}

/**
 * @brief A class to handle Keyboard input
 */
class Keyboard {
public:
  /**
   * @brief Constructor for Keyboard class
   * @param win - reference to main window
   * @param bounds - bounds of the window we are working in
   *
   * \image html KeyConstructor.png
   * \image latex KeyConstructor.eps
   */
  Keyboard(sf::RenderWindow *win, Document *doc, sf::Vector2f bounds);


  /**
   * @brief checks if a key is pressed
   * @param sf::Keyboard::key enum from SFML
   * @return bool true if key is pressed false if not
   *
   *  \image html keyIsKeyPressed.png
   *  \image latex keyIsKeyPressed.eps
   */
  bool isKeyPressed(sf::Keyboard::Key);

  /**
   * @brief checks if a text is entered to the text box
   * @param void
   * @return bool true if key is pressed false if not
   *
   *  \image html keyIsTextEntered.png
   *  \image latex keyIsTextEntered.eps
   */
  bool isTextEntered();

  /**
   * @brief checks if text is entered to the command box
   * @param void
   * @return bool tru eif key is pressed false if not
   *
   *
   *  \image html keyIsCmdTextEntered.png
   *  \image latex keyIsCmdTextEntered.eps
   */
  bool isCmdTextEntered();

  /**
   * @brief check if text is being deleted
   * @param void
   * @return bool true if text is being deleted
   *
   *
   * \image html keyCheckDeleted.png
   * \image latex keyCheckDeleted.eps
   */
  bool isTextDeleted();

  /**
   * @brief returns text entered
   *
   * A getter method that returns the text entered
   *
   * @param void
   * @return std::string text entered
   *
   * \image html keyGTextEntered.png
   * \image latex keyGTextEntered.eps
   */
  std::string getTextEntered();

  /**
   * @brief returns text entered from the command box
   *
   * A getter method that returns the text entered to the command box
   *
   * @param void
   * @return std::string text entered
   *
   */
  std::string getCmdTextEntered();

  /**
   * @brief sets text
   *
   * A setter method that sets the new text
   *
   * @param std::string - new string
   * @return void
   *
   *
   * \image html keyTextEntered.png
   * \image latex keyTextEntered.eps
   *
   */
  void setTextEntered(std::string);

  /**
   * @brief sets text
   * A setter method that sets the new text
   * @param std::string - new string
   * @return void
   *
   *
   *  \image html keyCmdEntered.png
   *  \image latex keyCmdEntered.eps
   *
   */
  void setCmdTextEntered(std::string);


  /**
   * @brief when we backspace on teh text
   * @param void
   * @return void
   *
   * \image html keyBackspace.png
   * \image latex keyBackspace.eps
   * 
   */
  void backSpace();

  /**
   * @brief handle keyboard events
   * @param event - to get text entered from events
   * @return void
   *
   *  \image html keyHandleKeyEvent.png
   *  \image latex keyHandleKeyEvent.eps
   *
   */
  void handleKeyEvent(sf::Event &event);

  /**
   * @brief handle keyboard events
   * @param event - to get text entered from events
   * @return void
   *
   * \image html keyHandleCmdKeyEvent.png
   * \image latex keyHandleCmdKeyEvent.eps
   */
  void handleCmdKeyEvent(sf::Event& event);

  /**
   * @brief mouse keyboard events
   * @param event - to get text entered from events
   * @return void
   */
  void handleMouseEvent(sf::Event &event); // not implemented yet


private:
  sf::RenderWindow *window; /**< refernce to window */
  std::stringstream tEntered; /**< the text entered  to main box*/
  std::stringstream tDeleted; /**< the text deleted from main box*/


  std::string ctEntered; /**< temporary for text enterd to cmd  not working */
  std::string ctDeleted; /**< temporary for text deleted to cmd  not working*/
};
#endif // KAMIL_KEYBOARD_H
