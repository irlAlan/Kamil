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

Keyboard::Keyboard(sf::RenderWindow *win, Document *doc, sf::Vector2f bounds)
    : window{win} //,doc{doc}
      ,
      bounds{bounds}
{
}

void Keyboard::handleKeyEvent(sf::Event &event) {
  if (event.type == sf::Event::TextEntered) {
    if (event.text.unicode < 127) {
      std::cout << std::hex << event.text.unicode << ' ' << '\n';
      switch (event.text.unicode) {
      case KEYS::ENTER:
        tEntered << "\n";
       //  if (tEntered.size() >= getBounds().x - 5) {
       //    tEntered << "\n";
       //  }
        tEntered << static_cast<char>(event.text.unicode);
        break;
      case KEYS::BS:
        backSpace();
        break;
      case KEYS::CR:
        tEntered << '\n';
        break;
      case KEYS::ESCAPE:
        //ctEntered = ;
        // backSpace();
        break;
      default:
        tEntered << static_cast<char>(event.text.unicode);
        break;
      }
    }
  }
}

void Keyboard::handleCmdKeyEvent(/**sf::Event& event*/) {
  sf::Event event;
  if (event.type == sf::Event::TextEntered) {
    if (event.text.unicode < 127) {
      std::cout << std::hex << event.text.unicode << ' ' << '\n';
      switch (event.text.unicode) {
        case KEYS::ENTER:
          ctDeleted = ctEntered;
          ctEntered.clear();
          break;
        case KEYS::BS:
        // backSpace();
          break;
      //  case KEYS::DELETE:
      //      deleteKey();
        default:
          ctEntered += static_cast<char>(event.text.unicode);
          break;
      }
    }
  }
}

void Keyboard::handleMouseEvent(sf::Event &event) // not implemented yet
{}

void Keyboard::backSpace() {
  std::string tmp{tEntered.str()};
  std::string nstring{};
  size_t endPos{tmp.length() - 1};

  if(tmp.end() != tmp.begin()){
      // for (size_t i{0}; i <= endPos; i++) {
      //   if (i == endPos) {
      //     tDeleted += tmp[i];
      //     fmt::print(tDeleted);
      //   }
      // }
      for (size_t i{0}; i < endPos; i++) {
        nstring += tmp[i];
      }
      tEntered.str(" ");
      tEntered << nstring;
  }
}


    
int Keyboard::getLineNumber() {
  int lineNumber;
  std::string vals{tEntered.str()};
  for (const auto &val : vals) {
    if (val == '\n')
      ++lineNumber;
  }
  return lineNumber;
}

sf::Vector2f Keyboard::getBounds() const { return bounds; }

bool Keyboard::isKeyPressed(sf::Keyboard::Key key) {
  return sf::Keyboard::isKeyPressed(key);
}

bool Keyboard::isTextEntered() { 
    return (!tEntered.rdbuf()->in_avail()) ? false : true;
}

bool Keyboard::isCmdTextEntered() { return !ctEntered.empty(); }

bool Keyboard::isTextDeleted() {
  bool check{isKeyPressed(sf::Keyboard::Key::Delete)};
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
