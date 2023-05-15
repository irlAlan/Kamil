#include <Kamil/Document.h>
#include <Kamil/Editor.h>
#include <Kamil/Keyboard.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <Kamil/CmdBox.h>

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fmt/core.h>
#include <string>
#include <vector>

// Keyboard constructor
Keyboard::Keyboard(sf::RenderWindow *win, Document *doc, sf::Vector2f bounds)
    : window{win}
    // when a value is passed in a parameter it is copied over which can be expensive
    // performance wise for larger data types and classes
    //  so passing by pointer stops expensive copy constructor and gives us direct access
    // to that instance of the variabe
{}

void Keyboard::handleKeyEvent(sf::Event &event) {
  if (event.type == sf::Event::TextEntered) {
    if (event.text.unicode < 127) {
      std::cout << std::hex << event.text.unicode << ' ' << '\n'; // print the hex value of keys pressed
      switch (event.text.unicode) {
      case KEYS::ENTER:
        tEntered << "\n"; // when we press newline
        tEntered << static_cast<char>(event.text.unicode);
        break;
      case KEYS::BS:
        backSpace(); // backspace key
        break;
      case KEYS::CR: // when carrige return is entered we add newline
        tEntered << '\n';
        break;
      default:
        tEntered << static_cast<char>(event.text.unicode); // convert into text to draw
        break;
      }
    }
  }
}

void Keyboard::handleCmdKeyEvent(sf::Event& event) {
  if (event.type == sf::Event::TextEntered) {
    if (event.text.unicode < 128) { // get teh unicode characters up to 128
      std::cout << std::hex << event.text.unicode << ' ' << '\n'; // print out the hex value
      switch (event.text.unicode) {
        case KEYS::ENTER:
          ctDeleted = ctEntered;
          ctEntered.clear();
          break;
        case KEYS::BS:
          break;
        default:
          ctEntered += static_cast<char>(event.text.unicode); // convert back into text to draw
          break;
      }
    }
  }
}

void Keyboard::handleMouseEvent(sf::Event &event) // not implemented yet
{}

void Keyboard::backSpace() {
  std::string tmp{tEntered.str()}; // create a temporary string
  std::string nstring{};
  size_t endPos{tmp.length() - 1}; // ge the length -1 

  if(tmp.end() != tmp.begin()){ // check if the end of the string does not equal the start
                                // so if the string is not empty

      for (size_t i{0}; i < endPos; i++) {
        nstring += tmp[i]; // append each character to the new string minus the end char
      }
      tEntered.str(" "); // set tEntered to an empty string
      tEntered << nstring; // fill tEntered with the new string
  }
}


bool Keyboard::isKeyPressed(sf::Keyboard::Key key) {
  return sf::Keyboard::isKeyPressed(key);
  // check if key is pressed
}

bool Keyboard::isTextEntered() { 
    return (!tEntered.rdbuf()->in_avail()) ? false : true;
    // ternary operator to check if there is text inside the tEntered variable
    // returns false if there is no text and true if there is
}

bool Keyboard::isCmdTextEntered() { return !ctEntered.empty(); }

bool Keyboard::isTextDeleted() {
  bool check{isKeyPressed(sf::Keyboard::Key::Delete)};
  // checks if text is being deleted
  return check;
}
std::string Keyboard::getTextEntered() {
  return tEntered.str();
}

std::string Keyboard::getCmdTextEntered() {
  std::string text = ctEntered;
  return text;
}

void Keyboard::setTextEntered(std::string nstring) { 
    tEntered << nstring; 
}

void Keyboard::setCmdTextEntered(std::string nstring) { ctEntered = nstring; }
