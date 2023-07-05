#include <string>
#include <vector>
#include "json.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

std::string jsonSource = R"([
  {
    "Display": "abcd",
    "ID": 100,
    "Nested": {
      "Name": "Test Name",
      "Value": "Test Value"
    }
  },
  {
    "Display": "aaaa",
    "ID": 10,
    "Nested": {
      "Name": "Test aaName",
      "Value": "Test aaValue"
    }
  }
])";

struct Inner {
  std::string Name;
  std::string Value;
};

struct Outer {
  std::string Display;
  int    ID;
  Inner  Nested;
};

void from_json(const nlohmann::json& j, Inner& i) {
    j.at("Name").get_to(i.Name);
    j.at("Value").get_to(i.Value);
}

void from_json(const nlohmann::json& j, Outer& o) {
    j.at("Display").get_to(o.Display);
    j.at("ID").get_to(o.ID);
    j.at("Nested").get_to(o.Nested);
}

int main() {
    std::ifstream json_path("./array_struct.json");
    auto json = nlohmann::json::parse(json_path);
    auto parsed = json["structs"].get<std::vector<Outer>>();

    std::cout << "parsed size: " << parsed.size() << std::endl;

    /* assert(parsed.size() == 1); */
    /* assert(parsed[0].Display == "abcd"); */
    /* assert(parsed[0].ID == 100); */
    /* assert(parsed[0].Nested.Name == "Test Name"); */
    /* assert(parsed[0].Nested.Value == "Test Value"); */
}
