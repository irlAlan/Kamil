#include <Kamil/EditorWindow.h>
#include <SFML/Graphics/RenderWindow.hpp>


EditorWindow::EditorWindow(sf::RenderWindow& window, TextBox& text)
    : m_window(&window), m_text(&text)
{
}


void EditorWindow::draw(){
    m_window->draw(m_text->getTextBox());
}
