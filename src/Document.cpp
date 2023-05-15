#include "toml++/impl/parse_error.h"
#include "toml++/impl/parser.h"
#include "toml++/impl/table.h"
#include <cstddef>
#include <string_view>
#include <toml++/toml.h>
#include <Kamil/Document.h>
#include <cstdio>
#include <cstdlib>
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

/**
 * @file Document.cpp
 *
 * @brief The Implementation for Document.h
 *
 * This is the Implementation code for the interface file Document.h
 * It is where all the code for file I/O is handled.
 */


  /**
   * @brief Constructor for Document class
   *
   * Initialises the relPath by default
   */
Document::Document()
    : relPath{"Document.txt"}
{}

  /**
   * @brief Constructor for Document class
   *
   * Creates / Opens the file passed through depending on if the file exists
   *
   * @param fileP - file path
   */
Document::Document(std::string fileP) : relPath{fileP} {
  std::ifstream getFromFile;
  std::ostringstream val;
  getFromFile.open(fileP, std::ios::in);

  /**
   * @brief checks if the file can be opened
   */
  if (!getFromFile) {
    fmt::print(stderr, "File cannot open");
  }
  getFromFile.close();
}

  /**
   * @brief initialise the file
   * @param void
   * @return void
   */
void Document::init() {
    /**
     * We get all the contents of the file into the string buffInfo using the std::getline
     * Each time we read a line from getline the previous line in the string gets overwritten
     * so we store it in a large string buffer (stringstream).
     * Once all the data is read we then put it back into the string, buffInfo, 
     * for the rest of the program to use.
     */
  std::ostringstream val;
  std::ifstream inputF;
  inputF.open(relPath, std::ios::in);
  if (!inputF) {
    fmt::print(stderr, "File cannot open");
  }
  while (std::getline(inputF, buffInfo)) {
    val << buffInfo << '\n';
  }
  buffInfo = val.str();
  inputF.close();
  docChanged = true;
}

  /**
   * @brief initialise the file
   * An example of function overloading in cpp.
   * It does the same job as the normal init() function.
   * We can keep the name the same but have to make sure the parameters are different.
   * where we change the signature of a function by changing its parameters
   * essentially creating a new function.
   * @param std::string - file path
   * @return void
   */
void Document::init(std::string inF) {

    /**
     * We get all the contents of the file into the string buffInfo using the std::getline
     * Each time we read a line from getline the previous line in the string gets overwritten
     * so we store it in a large string buffer (stringstream).
     * Once all the data is read we then put it back into the string, buffInfo, 
     * for the rest of the program to use.
     */
  std::ostringstream val;
  std::ifstream inputF;
  relPath = inF;
  inputF.open(inF, std::ios::in);
  if (!inputF) {
    fmt::print(stderr, "File cannot open");
  }
  while (std::getline(inputF, buffInfo)) {
    val << buffInfo << '\n';
  }
  buffInfo = val.str();
  inputF.close();
}


/**
 * find the configuration file config.toml
 */
bool Document::findConfig(){
    std::string fileTofind{"./config.toml"}; // file to find
    std::string dirPath{"./"}; // the current directory
    for(const auto& file : std::filesystem::directory_iterator(dirPath)){ // iterate teh current directory for config.toml
        fmt::print("{}\n",file.path().c_str());
        if(file.path().string() == fileTofind){ // check if its the correct one
            return true;
        }
    }
    return false;
}

/**
 * get the config file
 * and parse it for the necessary information
 */
Document::Config Document::getConfig(){
    std::string_view confPath{"config.toml"}; // config file to open
    toml::table tbl; // using a toml table, all file data stored here
    try{
        tbl = toml::parse_file(confPath); // check if we can open the file and if we can we parse it into the toml::tbl

    }
    catch(const toml::parse_error& err){ // catch and show any errors that happen
        std::cerr << "Parsing failed\n" << err << '\n';
        exit(-1);
    }
    // std::optional<std::string> creates a string variable that may or may not hold a value
    // if it does not hold a value we pass in NULL
    std::optional<std::string> str{tbl["project"]["name"].value_or("NULL")}; // get the name of the program
    std::optional<std::string> font{tbl["theme"]["font"].value_or("NULL")}; // get the font or null
    std::optional<std::string> exe{tbl["cmd"]["exe"].value_or("NULL")};
    auto background{tbl["theme"]["background"]}; // type left to compiler to figure out
    auto textCol{tbl["theme"]["text"]};

    // return a Document::Config 
    return {
        exe.value(),
        font.value(),
        Document::Theme{
            sf::Color(background[0].value_or(255), background[1].value_or<int>(255), background[2].value_or<int>(255), background[3].value_or<int>(255)),
            sf::Color(textCol[0].value_or<int>(255), textCol[1].value_or<int>(255), textCol[2].value_or<int>(255), textCol[3].value_or<int>(255)),
        }
    };
}

std::string Document::readFile() { return buffInfo; }

std::string Document::getRelPath() { return relPath; }

std::string Document::getAbsPath() { return absPath; }

bool Document::hasChanged() { return docChanged; }

void Document::setChange() {docChanged = false; }

void Document::createFile(std::string filename) {
    // open the file if not exist then it is made
    relPath = filename;
    std::ifstream file{filename};
    file.close();
}


void Document::setBuffInfo(std::string info) { buffInfo = info; }

/**
 * save the file when a filename is passed through
 */
bool Document::saveFile(const std::string &filename) {
    // set the relative path to the file we save
    relPath = filename;
  std::ofstream outFile(filename); // open the file

  std::stringstream dataToSave;

  // stream the buffer information into a string
  for (auto str : buffInfo) {
    dataToSave << str; // send it to the stringstream to handle it
  }

  outFile << dataToSave.str(); // send it to the file
  outFile.close();
  docChanged = false;
  return true;
}

/**
 * save the file when a filename is passed through
 */
bool Document::saveFile() {
  std::ofstream outFile(relPath); // open the file

  std::stringstream dataToSave;

  // stream the buffer information into a string
  for (auto str : buffInfo) {
    dataToSave << str; // send it to the stringstream to handle it
  }

  outFile << dataToSave.str(); // send it to the file
  outFile.close();
  docChanged = false;
  return true;
}
