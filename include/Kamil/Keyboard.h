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

/**
 * @brief An enum for Keyboard characters in hex form
 */
namespace KEYS{
    enum {
        ESCAPE = 0x1B,
        ENTER = 0xD,
        BS = 0x8,
        Shift_A = 0x41,
        CTRL = 0x11,
        DELETE = 0x7f,
    };
}


/**
 * @brief A class to handle Keyboard input
 */
class Keyboard{
    public:
        /**
         * @brief Constructor for Keyboard class
         * @param win - reference to main window
         * @param bounds - bounds of the window we are working in
         */
        Keyboard(sf::RenderWindow* win, sf::Vector2f bounds);


        /**
         * @brief checks if a key is pressed
         * @return bool true if key is pressed false if not
         */
        bool isKeyPressed(sf::Keyboard::Key);

        /**
         * @brief checks if a text is entered
         * @return bool true if key is pressed false if not
         */
        bool isTextEntered();

        /**
         * @brief checks if text is entered to the command box
         * @return bool tru eif key is pressed false if not
         */
        bool isCmdTextEntered();

        /**
         * @brief check if text is being deleted
         * @return bool true if text is being deleted
         */
        bool isTextDeleted();

        /**
         * @brief returns text entered
         * @return std::string text entered
         */
        std::string getTextEntered();
        

        /**
         * @brief returns text entered
         * @return std::string text entered
         */
        std::string getCmdTextEntered();


        /**
         * @brief sets text
         * @param nstring - new string
         */
        void setTextEntered(std::string);
        

        /**
         * @brief sets text
         * @param nstring - new string
         */
        void setCmdTextEntered(std::string);


        /**
         * @brief get the bounds of the area we are in
         * @return sf::Vector2f bounded area
         */
        sf::Vector2f getBounds() const;

        /**
         * @brief when we backspace on teh text
         */
        void backSpace();

        /**
         * @brief handle keyboard events
         * @param event - to get text entered from events
         */
        void handleKeyEvent(sf::Event& event);


        /**
         * @brief handle keyboard events
         * @param event - to get text entered from events
         */
        void handleCmdKeyEvent(/**sf::Event& event*/);

        /**
         * @brief mouse keyboard events
         * @param event - to get text entered from events
         */
        void handleMouseEvent(sf::Event& event); // not implemented yet

    private:
        sf::RenderWindow* window; /**< refernce to window */
        sf::Vector2f bounds; /**< store the bounded area */
        std::string tEntered; /**< the text entered  to main box*/
        std::string tDeleted; /**< the text deleted from main box*/

        std::string ctEntered; /**< tmp for text enterd to cmd */
        std::string ctDeleted; /**< tmp for text deleted to cmd */
};
#endif // KAMIL_KEYBOARD_H
