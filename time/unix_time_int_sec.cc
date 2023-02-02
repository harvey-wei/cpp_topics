#include <iostream>
#include <chrono>

void
get_time(std::time_t &unix_timestamp, char* time_buf)
{
    std::tm ts;
    ts = *localtime(&unix_timestamp);
    strftime(time_buf, sizeof(time_buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
}

int
main(int argc, char** argv)
{
    // std::time(0) gives you the elapsed seconds since 00:00 hours, Jan 1, 1970 UTC
    // (i.e., a unix timestamp).
    // hat's true on a lot of systems (POSIX and Windows, I believe), but it's not guaranteed
    // by the language standard.
    std::time_t t = std::time(0); // t is an integer

    char time_buf[80];
    return 0;
}

/**
 * https://cplusplus.com/reference/ctime/time_t/
 * https://stackoverflow.com/questions/6012663/get-unix-timestamp-with-c
 */
