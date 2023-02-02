#include <iostream>
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string


using namespace std::chrono;

int
main(int argc, char** argv)
{
    int64_t timestamp = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

    std::cout << timestamp << "us" << " has elapsed since 1970-01-01 00:00" << std::endl;

    int64_t timestamp_sec = timestamp / 1000000;
    int64_t timestamp_us = timestamp % 1000000;

    std::stringstream date;
    date << std::put_time(std::localtime(&timestamp_sec), "%Y-%m-%d %X");
    std::cout <<  date.str() << ":" << timestamp_us << std::endl;


    /* seconds! */
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    std::cout << ss.str();

    return 0;
}

/**
 * https://stackoverflow.com/questions/6012663/get-unix-timestamp-with-c
 * https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono
 * https://cplusplus.com/reference/iomanip/put_time/
 */

