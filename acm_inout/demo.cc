#include <iostream>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

/* https://ac.nowcoder.com/acm/contest/5657#question */

int main()
{
    /* use cin.get() */

    /* std::string str; */
    /* std::vector<std::string> strs; */
    /* while (std::cin >> str) */
    /* { */
    /*     strs.push_back(std::move(str)); */
    /**/
    /*     if ('\n' == std::cin.get()) */
    /*     { */
    /*         std::sort(strs.begin(), strs.end()); // in-place */
    /**/
    /*         for (size_t i = 0; i < strs.size(); ++i) */
    /*         { */
    /*             std::cout << strs[i] << " "; */
    /*         } */
    /**/
    /*         std::cout << std::endl; */
    /**/
    /*         strs.clear(); */
    /*     } */
    /* } */

    /* use getline */
    std::string line;

    while (std::getline(std::cin, line)) // delimiter is \n (newline)
    {
        std::stringstream line_ss(line);
        std::vector<std::string> strs;
        std::string str;

        while (std::getline(line_ss, str, ' '))
        {
            strs.push_back(std::move(str));
        }

        std::sort(strs.begin(), strs.end());
        for (const auto& s: strs)
        {
            std::cout << s << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
