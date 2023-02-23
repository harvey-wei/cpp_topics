#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

std::vector<boost::filesystem::path>
stream_lane_jsons(std::string lane_dir)
{
    /* std::vector<boost::filesystem::path> lane_jsons(boost::filesystem::directory_iterator{lane_dir}, */
    /*         boost::filesystem::directory_iterator{}); */

    std::vector<boost::filesystem::path> lane_jsons;

    if (boost::filesystem::exists(lane_dir) && boost::filesystem::is_directory(lane_dir))
    {
        for (const auto& entry: boost::filesystem::recursive_directory_iterator(lane_dir))
        {
            if (boost::filesystem::is_regular_file(entry) && entry.path().extension() == ".json")
            {
                lane_jsons.push_back(entry.path());
            }
        }
    }
    else
    {
        std::cerr << "The given lane json dir does exist!" << std::endl;
    }

    /* Sort files in accending order such that playback is chronological. */
    std::sort(lane_jsons.begin(), lane_jsons.end());

    return lane_jsons;
}

int main()
{
    path p = current_path();

    /* It points to the beginning of the directory */
    directory_iterator it{p};

    /**
     * To retrieve the end of a directory, the class must be instantiated with the default
     * constructor.
     */
    while (it != directory_iterator{})
    {
        std::cout << *(it++) << '\n';
    }
}


