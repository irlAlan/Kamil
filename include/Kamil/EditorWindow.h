#ifndef KAMIL_EDITOR_WINDOW_HPP
#define KAMIL_EDITOR_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

#include <Kamil/TextBox.h>


// inherits from text box class and also makes rectangle for line number
// handles changes to the viewing of the text box i.e. handles background changes and font changes
// Draw editor to window
// Add Font
// sets boundries of text box (entire window -15px for line number)

class EditorWindow{
    public:
        EditorWindow(sf::RenderWindow&, TextBox&);
        void draw();
    private:
        sf::RenderWindow* m_window;
        TextBox* m_text;
};


#endif // KAMIL_EDITOR_WINDOW_HPP
