#include <Kamil/Document.h>
#include <cstdio>
#include <cstdlib>
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <sstream>

Document::Document() {}

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
