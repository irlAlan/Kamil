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

Document::Document()
    : relPath{"Document.txt"}
{}

Document::Document(std::string fileP) : relPath{fileP} {
  std::ifstream getFromFile;
  std::ostringstream val;
  getFromFile.open(fileP, std::ios::in);

  if (!getFromFile) {
    fmt::print(stderr, "File cannot open");
  }
  getFromFile.close();
  //  while(std::getline(getFromFile, buffInfo)){
  //      val << buffInfo << '\n'; // just checking that buffInfo has the info
  //  }
  //   buffInfo = val.str();
  //    fmt::print("{}", buffInfo);
  //    std::cout << val.str();
}

void Document::init() {
  std::ostringstream val;
  std::ifstream inputF;
  inputF.open(relPath, std::ios::in);
  if (!inputF) {
    fmt::print(stderr, "File cannot open");
  }
  while (std::getline(inputF, buffInfo)) {
    val << buffInfo << '\n';
  }
  std::cout << val.str();
  inputF.close();
  docChanged = true;
}

void Document::init(std::string inF) {
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
  std::cout << val.str();
  inputF.close();
}


bool Document::findConfig(){
    std::string fileTofind{"./config.toml"};
    std::string dirPath{"./"};
    for(const auto& file : std::filesystem::directory_iterator(dirPath)){
        fmt::print("{}\n",file.path().c_str());
        if(file.path().string() == fileTofind){
            return true;
        }
    }
    return false;
}


Document::Config Document::getConfig(){
    using namespace std::string_view_literals;
    std::string_view confPath{"config.toml"};
    toml::table tbl;
    try{
        tbl = toml::parse_file(confPath);
        // std::cout << tbl << '\n';

    }
    catch(const toml::parse_error& err){
        std::cerr << "Parsing failed\n" << err << '\n';
        exit(-1);
    }
    std::optional<std::string> str{tbl["project"]["name"].value_or("NULL")};
    std::optional<std::string> font{tbl["theme"]["font"].value_or("NULL")};
    auto background{tbl["theme"]["background"]};
    auto textCol{tbl["theme"]["text"]};

    //toml::array* bArray{background.as_array()};
    //toml::array* tColArray{textCol.as_array()};

    // fmt::print("\n{}\n",str);
    // std::cout << background[1] << '\n';
    return {
        font.value(),
        Document::Theme{
            sf::Color(background[0].value_or(255), background[1].value_or<int>(255), background[2].value_or<int>(255), background[3].value_or<int>(255)),
            sf::Color(textCol[0].value_or<int>(255), textCol[1].value_or<int>(255), textCol[2].value_or<int>(255), textCol[3].value_or<int>(255)),
        }
    };
}

std::string Document::readFile() { return buffInfo; }

std::string Document::getRelPath() { return ""; }

std::string Document::getAbsPath() { return ""; }

bool Document::hasChanged() { return docChanged; }

void Document::setChange() {docChanged = false; }

void Document::createFile(std::string filename) {
    relPath = filename;
    std::ifstream file{filename};
    file.close();
}

void Document::createDir(std::string dirName) {
}

void Document::setBuffInfo(std::string info) { buffInfo = info; }

int Document::getLineCount() {
  int lineNumber{0};
  for (const auto &val : buffInfo) {
    if (val == '\n')
      ++lineNumber;
  }
  return lineNumber;
}

bool Document::saveFile(const std::string &filename) {
  std::ofstream outFile(filename);

  std::stringstream dataToSave;

  for (auto str : buffInfo) {
    dataToSave << str;
  }

  outFile << dataToSave.str();
  outFile.close();
  docChanged = false;
  return true;
}

bool Document::saveFile() {
  std::ofstream outFile(relPath);

  std::stringstream dataToSave;

  for (auto str : buffInfo) {
    dataToSave << str;
  }

  outFile << dataToSave.str();
  outFile.close();
  docChanged = false;
  return true;
}
