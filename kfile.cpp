#include "kfile.hpp"
#include <cassert>
#include <filesystem>
#include <fstream>
#include <ios>
#include <nlohmann/json_fwd.hpp>
#include <optional>
#include <sstream>

namespace klewy
{

File::File(std::string path)
{
    assert(path.find(".") != string::npos && "Invalid file name");
    file_path = path;
    if(!filesystem::exists(path))
    {
        ofstream file;
        file.open(path);

        file.flush();
        file.close();
    }
   
}
void File::write_text(std::string text, bool truncate)
{
    ofstream file;
    file.open(file_path, (truncate) ? (ios_base::openmode::_S_trunc) : (ofstream::app));
    if(file.is_open())
    {
        file.write(text.c_str(), text.size());
        file.flush();
        file.close();
    }
}
std::string File::read_all()
{
    stringstream ss;
    ifstream file;
    file.open(file_path);
    if(file.is_open())
    {
        string text;
        file >> ss.rdbuf();
        text = ss.str();
        file.close();
        return text;
    }
    return "";
}
void File::write_text(int value, bool truncate)
{
    ofstream file;
    file.open(file_path, (truncate) ? (ios_base::openmode::_S_trunc) : (ofstream::app));
    if(file.is_open())
    {
        file << value;
        file.flush();
        file.close();
    }
}
void File::write_text(double value, bool truncate)
{
    ofstream file;
    file.open(file_path, (truncate) ? (ios_base::openmode::_S_trunc) : (ofstream::app));
    if(file.is_open())
    {
        file << value;
        file.flush();
        file.close();
    }
}
void File::write_json(nlohmann::json &json)
{
    ofstream file;
    file.open(file_path, ios_base::trunc);
    if(file.is_open())
    {
        file << json;
        file.flush();
        file.close();
    }
}
nlohmann::json File::read_json()
{
    nlohmann::json j;
    ifstream file;
    file.open(file_path);
    if(file.is_open())
    {
        j = j.parse(file);
        file.close(); 
    }
    return j;
}




}
