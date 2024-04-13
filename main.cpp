#include <fstream>
#include <ios>
#include <iostream>

#include <optional>
#include <string>
#include "kfile.hpp"
#include "include/nlohmann/json.hpp"

using namespace klewy;
using json = nlohmann::json;
//=============================================================
struct User
{
    std::string name;
    unsigned int age;
};

void to_json(json &j, const User &usr)
{
    j = json{{"name", usr.name}, {"age", usr.age}};
}
void from_json(const json &j, User &usr)
{
    j.at("name").get_to(usr.name);
    j.at("age").get_to(usr.age);
}
//=============================================================

int main()
{

    
    // Make sure you implement Serialize and Deserialize functions for your own struct.

    return 0;
}