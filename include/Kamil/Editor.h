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
#include "Keyboard.h"
#include "TextBox.h"

/**
 * @brief Class that is a centre for how the other classes interact with each other
 * and draws everything in the Editor to the screen
 */
class Editor {
public:
  /**
   * @brief Constructor for Editor
   * @param window - pointer to main RenderWindow
   * @param event - pointer to main event
   * @param doc - pointer to document
   *
   * \image html  editorConstructor.png
   * \image latex editorConstructor.eps
   */
  Editor(sf::RenderWindow *window, sf::Event *event, Document *doc);

  /**
   * @brief Destructor for Editor class
   * png/Editor/editorDestructor.png
   *  eps/Editor/editorDestructor.eps
   */
  ~Editor();

  /**
   * @brief function that draws everything to RenderWindow
   * @param void
   * @return void
   *
   * \image html  editorDraw.png
   * \image latex editorDraw.eps
   */
  void draw();


  /**
   * @brief changes the editor looks and workings
   *
   * uses the information of the config.toml
   * to change how the editor looks and how it can work
   *
   * @param const Document::Config& - the config.toml information
   * @reutrn void
   *
   * \image html  editorUseConfig.png
   * \image latex editorUseConfig.eps
   */
  void useConfig(const Document::Config& conf);

  /**
   * @brief match patterns in the string
   *
   * A method that is used to match and extract any math expressions in the text on the screen.
   *
   * Kamil enjoys maths alot and is even doing further maths at A-level. However,
   * he finds the small maths questions like 782*7 tedius to type into the calculator.
   * So to make sure he can focus only on the problem at hand and not any side questions I developed this 
   * regex method.
   *
   * It extracts the text on the screen and stores it as a string.
   * It then calls the regex_search() function passing in the string to search,  an smatch type that contains the matchedsubstr 
   * and the regex to use.
   * if the match is found then we extract it in the smatch type and preform the calculations on the substr.
   * we then recursivly search the string by calling the smatch::suffix() method checking the rest of the string after the last match
   * by doing this we ensure that any and all potential matches have been made
   *
   *
   * @param void
   * @return void
   *
   * \image html  editorRegex.png
   * \image latex editorRegex.eps
   */
  void regexPatternMatchin();

private:
  Document *doc;            /**< pointer to the working document */
  TextBox *textBox;         /**< reference to textbox that we draw */
  CmdBox *cbox;             /**< reference to command box that we draw */
  sf::RenderWindow *window; /**< refernce to RenderWindow */
  sf::Event *event;         /**< refernce to event */
  sf::View camera; /**< for the camera */
  Keyboard kb; /**< handles keyboard events */
  std::string cmd;
  bool loadFromFile; /**< check if we are loading from file */
};

#endif // KAMIL_EDITOR_WINDOW_HPP
