#pragma once
#include "include/nlohmann/json.hpp"
#include <iostream>
#include <nlohmann/json_fwd.hpp>
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

    void write_json(nlohmann::json &json);
    nlohmann::json read_json();
    std::string read_all();

};

}