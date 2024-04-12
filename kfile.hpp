#pragma once

#include <iostream>
#include <streambuf>
#include<string>
#include<fstream>
#include<sstream>
#include<filesystem>
#include<optional>
namespace klewy {

using namespace std;
class File
{
private:
    string file_path;
public:

    File(std::string path);

    void write_text(std::string text, bool truncate);
    void write_text(int value, bool truncate);
    void write_text(double value, bool truncate);
    std::string read_all();

};

}