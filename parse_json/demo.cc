#include "json.hpp"
#include <iostream>
#include <fstream>


/**
 * \note The lane equation is y = ax^3 + bx^2 + cx + d
 *       The coordinate system is as follows:
 *
 *                  x
 *                  |
 *                  |
 *                  |
 *                  |
 *    y <-----------z
 * z points to sky!
 */

struct LaneParams
{
};


namespace ns {
    // a simple struct to model a person
    struct person
    {
        std::string name;
        std::string address;
        int age;
    };

    void to_json(nlohmann::json& j, const person& p)
    {

        j = nlohmann::json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
    }

    void from_json(const nlohmann::json& j, person& p) {
        j.at("name").get_to(p.name);
        j.at("address").get_to(p.address);
        j.at("age").get_to(p.age);
    }
}

int main(int argc, char ** argv)
{
    /* Parse the parameters form json config file. */
    std::ifstream params_file("/home/harvey/catkin_ws/src/rain_filter/src/params.json");
    /* nlohmann::json is a class for representing a json object */
    nlohmann::json params = nlohmann::json::parse(params_file);  // parse is static member function

    std::ifstream j2_file_path("./j2.json");
    nlohmann::json j2_params = nlohmann::json::parse(j2_file_path);
    std::vector<float> dists = j2_params["dist_thres"].get<std::vector<float>>();
    std::cout << "distance threshold: " << std::endl;
    for (const auto& dist: dists)
    {
        std::cout << dist << " " << std::endl;
    }

    std::string paths = params["path_to_pcds"];
    int start_frame = params["start_frame"];
    bool is_vis_intensity = params["is_vis_intensity"];
    bool is_step_mode = params["is_step_mode"].get<bool>();

    // Using (raw) string literals and json::parse
    nlohmann::json ex1 = nlohmann::json::parse(R"(
      {
        "pi": 3.141,
        "happy": true
      }
    )");
    // creat an empty structure
    // create an empty structure (null)
    nlohmann::json j;

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = 3.141;

    // add a Boolean that is stored as bool
    j["happy"] = true;

    // add a string that is stored as std::string
    j["name"] = "Niels";

    // add another null object by passing nullptr
    j["nothing"] = nullptr;

    // add an object inside the object
    j["answer"]["everything"] = 42;

    // add an array that is stored as std::vector (using an initializer list)
    j["list"] = { 1, 0, 2 };

    // add another object (using an initializer list of pairs)
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };

    /* Parse the json paramters with specific type. */

    // instead, you could also write (which looks very similar to the JSON above)
    nlohmann::json j2 = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {
        {"everything", 42}
        }},
        {"list", {1, 0, 2}},
        {"object", {
        {"currency", "USD"},
        {"value", 42.99}
        }}
    };

    // Get a string
    std::string s_j2 = j2.dump();

    // serialization with pretty printing
    // pass in the amount of spaces to indent
    std::cout << j2.dump(4) << std::endl;

    std::ofstream j2_file("j2.json");

    /* std::setw(4) set the indent to 4 spaces. */
    j2_file << std::setw(4)<< j2 << std::endl;

    /* // read a JSON file */
    /* std::ifstream ii("file.json"); */
    /* nlohmann::json jj; */
    /* ii >> jj; */
    /**/
    /* // write prettified JSON to another file */
    /* std::ofstream oo("pretty.json"); */
    /* oo << std::setw(4) << jj << std::endl; */
    /**/

    std::string s1 = "Hello, world!";
    nlohmann::json js = s1;
    auto s2 = js.get<std::string>();


    return 0;
}

/**
 * Q: What is json?
 * A: https://www.tutorialspoint.com/json/json_data_types.htm
 * https://github.com/nlohmann/json
 */

