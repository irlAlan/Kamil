#include <Kamil/Editor.h>
#include <Kamil/TextBox.h>
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <regex>
#include <fmt/core.h>
#include <sstream>
#include <string>


Editor::Editor(sf::RenderWindow *window, sf::Event *event, Document *doc)
    : window(window), event{event}, doc{doc}
// dynamically create new classes
// allocate to the heap using the new keyword
      ,textBox{new TextBox{window, sf::Vector2f{0.f, 0.f}, 
                          sf::Vector2f{(float)window->getSize().x,// Starting position x
                                       (float)window->getSize().y - 25}, // starting position y
                          "../resource/fonts/arial.ttf", 20, sf::Color(171, 178, 191, 255), // font, font colour and font colour
                          sf::Color(40, 44,52, 255), 5}}, // background colour
      cbox{new CmdBox{window,
                      sf::Vector2f{0.f, (float)window->getSize().y - 25},
                      sf::Vector2f{(float)window->getSize().x, 25},
                      "../resource/fonts/arial.ttf", 20, sf::Color(171, 178, 191, 255),
                      sf::Color(40,44,52,255), 5}},
      kb{window, doc, textBox->getSize()}
{}

Editor::~Editor() { 
    delete textBox;
    delete cbox;
}


void Editor::regexPatternMatchin(){
        std::string tmpS{kb.getTextEntered()}; // get the text to check
        std::vector<std::string> s;
        std::stringstream ssVal;
        int val1;
        char op;
        int val2;

        std::regex patterns{R"(\d+\s*[\+\-\*/]\s*\d+)"}; // regex pattern to match math expressions

        std::smatch match; // matching operator
        int i{0};
        while (std::regex_search(tmpS, match, patterns)) {
            s.push_back(match.str()); // each match we push onto a dynamic array vector
            for(const auto& val : s){
                fmt::print("{}\n",val);
            }
            tmpS = match.suffix(); // recursivly loop through the string input 
                                   // starting after the last regex match
        }
        ssVal << s[1];
        ssVal >> val1 >> op >> val2;
}



void Editor::useConfig(const Document::Config& conf){
    // set the config information
    cmd = conf.cmd;
    textBox->setFont(conf.font);
    textBox->setTextColour(conf.theme.fcol);
    textBox->setFillColour(conf.theme.bcol);
}


void Editor::draw() {
    // testing purposes, check if the values are correct
  fmt::print("{}, {}\n", textBox->getPos().x, textBox->getPos().y);
  fmt::print("{}, {}\n", textBox->getSize().x, textBox->getSize().y);

  kb.setTextEntered(doc->readFile()); // get the file information
  fmt::print("file info: {}", doc->readFile());

    camera.setSize((sf::Vector2f)window->getSize()); // set the size of the view
    camera.setCenter({window->getSize().x * 0.5f, window->getSize().y * 0.5f}); // set the centre of the view to the 
                                                                                // centre of the window

    bool keyPressed{false};

  while (window->isOpen()) {
    while (window->pollEvent(*event)) {
      switch (event->type) {
      case sf::Event::Closed: // check if the window has been closed
        window->close();
        break;
      default:
        break;
      }
      // handle the key events
      kb.handleKeyEvent(*event);
      kb.handleCmdKeyEvent(*event);
    }

    // if text is entered we update the documnt buffer information
    if (kb.isTextEntered()) {
      doc->setChange();
      textBox->setString(kb.getTextEntered());
      doc->setBuffInfo(kb.getTextEntered().c_str());
    }

    if (kb.isCmdTextEntered()) {
      cbox->setString(kb.getCmdTextEntered() + "-");
      if (kb.getCmdTextEntered() == "open") {
        fmt::print("open says me\n");
      }
    }

    // check if LControl and R are pressed so we can run the executable
    if(kb.isKeyPressed(sf::Keyboard::LControl) && kb.isKeyPressed(sf::Keyboard::R) && !keyPressed){
        std::string run{cmd + ' ' + doc->getRelPath()};
        std::system(run.c_str());
    }
    else if(!kb.isKeyPressed(sf::Keyboard::LControl) && !kb.isKeyPressed(sf::Keyboard::R) && keyPressed)
        keyPressed = false;

    // check if LControl and A are pressed so we can match the patterns
    if(kb.isKeyPressed(sf::Keyboard::LControl) && kb.isKeyPressed(sf::Keyboard::A) && !keyPressed){
        keyPressed = true; 
        regexPatternMatchin();
    }
    else if(!kb.isKeyPressed(sf::Keyboard::LControl) && !kb.isKeyPressed(sf::Keyboard::A) && keyPressed)
        keyPressed = false;

    // check if Down arrow and LControl are pressed so we can move the camera down
    if(kb.isKeyPressed(sf::Keyboard::Down) && kb.isKeyPressed(sf::Keyboard::LControl) && !keyPressed){
        camera.move(0.0f,0.8f); // positive x since SFML draws from the top left so down brings us further from 0
    }
    else if(!kb.isKeyPressed(sf::Keyboard::Down) && !kb.isKeyPressed(sf::Keyboard::LControl) && keyPressed)
        keyPressed = false;

    // check if the Up arrow and LControl are pressed so we can move the camera up
    if(kb.isKeyPressed(sf::Keyboard::Up) && kb.isKeyPressed(sf::Keyboard::LControl) && !keyPressed){
        camera.move(0.0f,-0.8f); // negative x since SFML draws from top left  so up brings us closer to 0
    }
    else if(!kb.isKeyPressed(sf::Keyboard::Up) && !kb.isKeyPressed(sf::Keyboard::LControl) && keyPressed)
        keyPressed = false;

    // Check if S and LControl are pressed to save the file
    if (kb.isKeyPressed(sf::Keyboard::S) &&
        kb.isKeyPressed(sf::Keyboard::LControl) && !keyPressed) {
        if(doc->getRelPath().empty()){
            std::string filename;
            fmt::print("Enter a file name: ");
            std::cin >> filename;
            doc->createFile(filename);
        }
        fmt::print("File has saved\n");
        doc->saveFile();
    }
    else if (!kb.isKeyPressed(sf::Keyboard::S) && !kb.isKeyPressed(sf::Keyboard::LControl) && keyPressed)
        keyPressed = false;



    textBox->setPosition(camera.getCenter() - camera.getSize() *0.5f); // keeps the background rectangle in frame
    window->clear(sf::Color::Transparent);
    window->draw(*textBox);
    window->draw(*cbox);
    window->setView(camera); // set the view
    window->display(); // put everything on the screen
  }
}
