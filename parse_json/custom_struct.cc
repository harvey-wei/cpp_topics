#include "json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;

namespace ns {
    struct Person {
        std::string name;
        std::string address;
        int age;
    };

    void to_json(json& j, const Person& p) {
        j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
    }

    void from_json(const json& j, Person& p) {
        j.at("name").get_to(p.name);
        j.at("address").get_to(p.address);
        j.at("age").get_to(p.age);
    }
} // namespace ns

namespace ann
{
    struct Ann
    {
        int point_index;
        std::string category;
    };

    void
    to_json(nlohmann::json& j, const Ann& a)
    {
        j = nlohmann::json{{"point_index", a.point_index}, {"category", a.category}};

        return;
    }

    void
    from_json(const nlohmann::json& j, Ann& a)
    {
        j.at("point_index").get_to(a.point_index);
        j.at("category").get_to(a.category);

        return;
    }
};

int
main(int argc, char** argv)
{
    // create a person
    ns::Person p1{"Ned Flanders", "744 Evergreen Terrace", 60};
    ns::Person p2{"Harvey", "Karlsruhe 111", 30};

    // conversion: person -> json
    std::vector<ns::Person> ps = {p1, p2};
    json j = ps;

    std::cout << j << std::endl;
    // {"address":"744 Evergreen Terrace","age":60,"name":"Ned Flanders"}

    // conversion: json -> person
    auto p_json = j.get<std::vector<ns::Person>>();

    std::ofstream person_file("person.json");
    person_file << std::setw(4) << j << std::endl;
    person_file.close();

    std::ifstream ann_json_path("000154.json");
    nlohmann::json ann_json = nlohmann::json::parse(ann_json_path);

    std::vector<ann::Ann> anns = ann_json["points"].get<std::vector<ann::Ann>>();

    std::cout << "anns[1]: " << anns[1].point_index << " " << anns[1].category << std::endl;


    // that's it
    /* assert(p == p2); */

    return 0;
}
