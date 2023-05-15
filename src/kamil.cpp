#include <Kamil/TextBox.h>
#include <Kamil/Editor.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <fmt/core.h>
#include <iostream>

#include <Kamil/Document.h>

int main(int argc, char *argv[]) {
  std::string dir;
  std::string saveFileName;
  std::string loadFileName;

  std::string commands[] {
        "-gpy",
        "-gcpp"
  };

  Document doc;

  if (argc == 2) {
    dir = argv[1];
    fmt::print("{}\n", dir);
    doc.init(dir);
  }
  // else if(argc == 3){
  //     if(argv[1] == commands[0]){
  //       loadFileName = argv[2];
  //       doc.init(loadFileName);
  //     }
   //dirInfo = getWorkingDirectory(argv[0]);
   //cmd = argv[1];
   //fileName = dirInfo + argv[2];
  // }
  else if (argc > 3) {
    std::cout << "NO MORE COMMANDS AND OR FILES {:(\n";
    return -1;
  }

  sf::RenderWindow window(sf::VideoMode(640, 480), "SFML = <3");
  sf::Event event;
  Editor edit{&window, &event, &doc};
  if(doc.findConfig()){
      fmt::print("config.toml exists\n");
      edit.useConfig(doc.getConfig());
  }else {
    fmt::print("config.toml does not exist\n");
  }
  edit.draw();

  //  while(window.isOpen())
  //  {
  //      while(window.pollEvent(event)){
  //          if(event.type == sf::Event::Closed)
  //              window.close();
  //          if(event.key.code == sf::Keyboard::S &&
  //          sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
  //             doc.saveFile(saveFileName);
  //             fmt::print("Saved file to: {}", saveFileName);
  //          }
  //          edit.handleEvent();

  //      }
  //  }

  return 0;
}
