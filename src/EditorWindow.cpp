#include <Kamil/EditorWindow.h>
#include <SFML/Graphics/RenderWindow.hpp>


EditorWindow::EditorWindow(sf::RenderWindow& window, TextBox& text)
    : m_window(&window), m_text(&text)
{
}

EditorWindow::EditorWindow(sf::RenderWindow& window, TextBox& text, sf::Event& event)
    : m_window(&window), m_text(&text), m_event(&event)
{
}

void EditorWindow::draw(){
//    m_text->typedOn(*m_event);
    m_window->draw(m_text->getTextBox());
}
