#ifndef KAMIL_EDITOR_WINDOW_HPP
#define KAMIL_EDITOR_WINDOW_HPP

/**
 * @file Editor.h
 *
 * @brief Interface file for the Editor class
 *
 * The Editor class is responsible for the interaction between the different classes.
 * All things outside the main while loop will be checked or initialise.
 * Anything to do with the Editor Window will happen here
 */



#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

#include "TextBox.h"
#include "Keyboard.h"
#include "CmdBox.h"


/**
 * @brief Class that handles and draws everything in the Editor
 */
class Editor{
    public:
        /**
         * @brief Constructor for Editor
         * @param window - reference to main RenderWindow
         * @param event - reference to main event
         */
        Editor(sf::RenderWindow*, sf::Event*);

        /**
         * @brief Destructor for Editor class
         */
        ~Editor();

        /**
         *
         * DEPRECATED
         * @brief function that draws everything to RenderWindow
         */
        void draw();

        /**
         * @brief handle the events for the Editor
         *
         * where all event handles are called when interacting with other classes
         * e.g. kb.handleEvent(); kb.handleMouseEvents();
         */
        void handleEvent();
    private:
        TextBox* textBox; /**< reference to textbox that we draw */
        CmdBox* cbox; /**< reference to command box that we draw */
        sf::RenderWindow* window; /**< refernce to RenderWindow */
        sf::Event* event; /**< refernce to event */
        Keyboard kb; /**< handles keyboard events */
};

#endif // KAMIL_EDITOR_WINDOW_HPP
