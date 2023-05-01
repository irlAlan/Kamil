#ifndef KAMIL_EDITOR_WINDOW_HPP
#define KAMIL_EDITOR_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

#include "TextBox.h"
#include "Keyboard.h"
#include "CmdBox.h"

/** 
 * @file Editor.h
 *
 * EditorWindow contains the textbox and keyboard stuff so nested classes will be used
 * EditorWindow is just a namespace not a class 
 *
 * 
 * anything to do with the Editor window always through the EditorWindow namespace i.e.
 * EditorWindow editor;
 *
 */


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
         * @brief function that draws everything to RenderWindow
         */
        void draw();
    private:
        TextBox* textBox; /**< reference to textbox that we draw */
        CmdBox* cbox; /**< reference to command box that we draw */
        sf::RenderWindow* window; /**< refernce to RenderWindow */
        sf::Event* event; /**< refernce to event */
        Keyboard kb; /**< handles keyboard events */
};

#endif // KAMIL_EDITOR_WINDOW_HPP
