#include <iostream>
#include <cstdlib>

#include <fstream>

std::string getWorkingDir(const std::string& argvZero){
    size_t i{argvZero.find_last_of('/')};
    return argvZero.substr(0, i+1);
}


int main (int argc, char *argv[]) {
  
    std::ifstream fileP;
    std::string fileStuff;

    int i{0};
    
    fileP.open(argv[1], std::ios::in);
    if(!fileP)
        std::cerr << "CANNOT OPEN FILE\n";
    else{

        while(fileP >> fileStuff){
            std::cout << fileStuff;
            if(fileStuff[i] == '\n'){
                std::cout << '\n';
            }
            i++;
        }

    }
    return 0;
}
