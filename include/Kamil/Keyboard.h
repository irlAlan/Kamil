#ifndef KAMIL_KEYBOARD_H
#define KAMIL_KEYBOARD_H

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
         */
        Keyboard(sf::RenderWindow*, sf::Vector2f);


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
         * @brief sets text
         * @param nstring - new string
         */
        void setTextEntered(std::string);


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
        void handleEvent(sf::Event& event);

    private:
        sf::RenderWindow* window; /**< refernce to window */
        sf::Vector2f bounds; /**< store the bounded area */
        std::string tEntered; /**< the text entered */
        std::string tDeleted; /**< the text deleted */
};
#endif // KAMIL_KEYBOARD_H
