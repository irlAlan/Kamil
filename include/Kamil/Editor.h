#ifndef KAMIL_EDITOR_WINDOW_HPP
#define KAMIL_EDITOR_WINDOW_HPP

/**
 * @file Editor.h
 *
 * @brief Interface file for the Editor class
 *
 * The Editor class is responsible for the interaction between the different
 * classes. All things outside the main while loop will be checked or
 * initialise. Anything to do with the Editor Window will happen here
 */

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window.hpp>

#include "CmdBox.h"
#include "Document.h"
#include "EditorCam.h"
#include "Keyboard.h"
#include "TextBox.h"

/**
 * @brief Class that handles and draws everything in the Editor
 */
class Editor {
public:
  /**
   * @brief Constructor for Editor
   * @param window - pointer to main RenderWindow
   * @param event - pointer to main event
   * @param doc - pointer to document
   */
  Editor(sf::RenderWindow *window, sf::Event *event, Document *doc);

  /**
   * @brief Destructor for Editor class
   */
  ~Editor();

  /**
   *
   * SOON DEPRECATED
   * @brief function that draws everything to RenderWindow
   */
  void draw();

  /**
   * @brief making the line numbers
   * @return void
   */
  void makeLineNum();

  /**
   * @brief handle the events for the Editor
   *
   * where all event handles are called when interacting with other classes
   * e.g. kb.handleEvent(); kb.handleMouseEvents();
   */
  void handleEvent();

private:
  Document *doc;            /**< pointer to the working document */
  TextBox *textBox;         /**< reference to textbox that we draw */
  CmdBox *cbox;             /**< reference to command box that we draw */
  sf::RenderWindow *window; /**< refernce to RenderWindow */
  sf::Event *event;         /**< refernce to event */
  // TextBox lineBox;          /**< for the line number */
  //EditorCam camera;         /**< for the camera */
  sf::View camera;
  Keyboard kb; /**< handles keyboard events */
  bool loadFromFile; /**< check if we are loading from file */
};

#endif // KAMIL_EDITOR_WINDOW_HPP
