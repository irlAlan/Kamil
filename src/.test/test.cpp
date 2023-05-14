#include <iostream>
#include <string>
#include <sstream>


int main(){

    std::stringstream myStream;

    myStream << "Hi there";


    std::string val = (!myStream.rdbuf()->in_avail()) ? "Stream is empty\n" : "Stream is not empty\n";

    std::cout << val;
    return 0;
}
