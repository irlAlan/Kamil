#include <Kamil/Document.h>
#include <cstdio>
#include <cstdlib>
#include <fmt/core.h>
#include <iostream>
#include <sstream>

Document::Document(){
}

Document::Document(std::string fileP)
    : relPath{fileP}
{
}

void Document::init(){
    std::ostringstream val;
    std::ifstream inputF;
    inputF.open(relPath, std::ios::in);
    if(!inputF){
        fmt::print(stderr, "File cannot open");
    }
    while(std::getline(inputF, buffInfo)){
        val << buffInfo << '\n';
    }
    std::cout << val.str();
}

void Document::readFile(){

}

std::string Document::getRelPath(){
    return "";
}

std::string Document::getAbsPath(){
    return "";
}

bool Document::hasChanged(){
    return docChanged;
}


void Document::createFile(){

}

void Document::createDir(){

}

bool Document::saveFile(const std::string& filename){
    std::ofstream outFile(filename, std::ios::out);

    std::stringstream dataToSave;

    for(auto str : buffInfo){
        dataToSave << str;
    }

    outFile << dataToSave.str();
    outFile.close();
    docChanged = false;
    return true;
}
