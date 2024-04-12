#include <iostream>
#include <optional>
#include <string>
#include "kfile.hpp"


using namespace klewy;
int main()
{
    File fil("fuck.txt");
    fil.write_text(10, false);
    string f = fil.read_all();

    
    std::cout << f << std::endl;



    // TODO: implement json lib

    return 0;
}