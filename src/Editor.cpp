#include <Kamil/Editor.h>
#include <Kamil/TextBox.h>
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include <SFML/Window/Keyboard.hpp>
#include <fmt/core.h>
#include <string>

// Move the Number Lines into a seperate struct that is with teh textBox

Editor::Editor(sf::RenderWindow *window, sf::Event *event, Document *doc)
    : window(window), event{event}, doc{doc}, camera{window, 20, 5, 0.8f, 0.8f},
      textBox{new TextBox{window, sf::Vector2f{20.f, 0.f},
                          sf::Vector2f{(float)window->getSize().x,
                                       (float)window->getSize().y - 25},
                          "../resource/fonts/arial.ttf", 20, sf::Color(171, 178, 191),
                          sf::Color(40, 44,52, 255), 5}},
      cbox{new CmdBox{window,
                      sf::Vector2f{0.f, (float)window->getSize().y - 25},
                      sf::Vector2f{(float)window->getSize().x, 25},
                      "../resource/fonts/arial.ttf", 20, sf::Color::Black,
                      sf::Color::Blue, 5}},
      kb{window, doc, textBox->getSize()}, lineBox{
                                               window,
                                               {0, 0},
                                               {20.0f,
                                                (float)window->getSize().y},
                                               "../resource/fonts/arial.ttf",
                                               20,
                                               sf::Color(171, 178, 191),
                                               sf::Color(40, 44,52, 255),
                                               0.5} {}

Editor::~Editor() { 
    delete textBox;
    delete cbox;
}

void Editor::handleEvent() {
  kb.handleKeyEvent(*event);
  kb.handleMouseEvent(*event);
}

void Editor::makeLineNum() {
    //std::cout << doc->getLineCount() << '\n';
    // make a function that reads the string and checks for any new new Lines
    // when a new new line is detected it updates teh line numebrs
    // when a new line is deleted it updates the line numbers
  //for (int i{0}; i <= kb.getLineNumber(); i++) {
      // std::cout <<  << '\n';
     //std::cout << std::to_string(i) << '\n';
     // lineBox.setString(std::to_string(i) + '\n');
  //}
}

void Editor::draw() {
  int charTyped;
  fmt::print("{}, {}\n", textBox->getPos().x, textBox->getPos().y);
  fmt::print("{}, {}\n", textBox->getSize().x, textBox->getSize().y);

  kb.setTextEntered(doc->readFile());
  fmt::print("file info: {}", doc->readFile());
  //    fmt::print("Line Number: {}\n", lineCount(kb.getTextEntered()));

  while (window->isOpen()) {
    while (window->pollEvent(*event)) {
      switch (event->type) {
      case sf::Event::Closed:
        window->close();
        break;
      case sf::Event::Resized:
        camera.setCameraBounds(event->size.width, event->size.width);
      default:
        break;
      }
      // kb.handleKeyEvent(*event);
      kb.handleCmdKeyEvent();
    }
    makeLineNum();
    // lineBox.setString("0\n1\n2");

    if (kb.isTextEntered()) {
      doc->setChange();
      textBox->setString(kb.getTextEntered().c_str());
      doc->setBuffInfo(kb.getTextEntered().c_str());
    }

    if (kb.isCmdTextEntered()) {
      cbox->setString(kb.getCmdTextEntered() + "-");
      if (kb.getCmdTextEntered() == "open") {
        fmt::print("open says me\n");
      }
    }

    if (kb.isKeyPressed(sf::Keyboard::S) &&
        kb.isKeyPressed(sf::Keyboard::LControl)) {
        if(doc->getRelPath().empty()){
            std::string filename;
            fmt::print("Enter a file name: ");
            std::cin >> filename;
            doc->createFile(filename);
        }
        fmt::print("File has saved\n");
        doc->saveFile();
    }

    //            kb.kbrCmd<std::string, 3>("LControl", "S", "R");

    window->clear();
    window->draw(lineBox);
    window->draw(*textBox);
    //window->draw(*cbox);
    window->display();
  }
}
