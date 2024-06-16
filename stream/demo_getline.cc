#include <sstream>  // for stringstream
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    string serialize_str = "6, 7, 8, #, #, 20, #, 30, #";

    /* (>>) is an extraction operator. It can be used more than once to accept multiple inputs. It differentiates the multiple inputs through spaces or the next line.  */
    /* How to read number and # in serialize_str sequentially? */
    /* Method 1: Read character by character. */
    string curr = ""; // empty string
    vector<string> str_vec;

    for (unsigned int i = 0; i < serialize_str.size(); ++i)
    {
        /*
           Extended ASCII code use 8-bit numeric representation and ranges from 0 to 255;
           For 0-9, their ASCII (char or uint8) code order matches original order, i.e.
           '0' < '1' < ... < '9'. The difference of any two consecutive digit char is 1.
           For lowercase letters,
           'a' < 'b' < 'c' < ... < 'z'. The difference of any two consecutive lowercases is 1.
           For uppercase letters,
           'A' < 'B' < 'C' < ... < 'Z'. The difference of any two consecutive lowercases is 1.
        */
        if ((serialize_str[i] >= '0' && serialize_str[i] <= '9') || serialize_str[i] == '#')
        {
            curr.push_back(serialize_str[i]);
        }
        else if (serialize_str[i] == ' ')
        {
            continue;
        }
        else
        {
            /* comma */
            if ("#" == curr)
            {
                std::cout << " nullptr";
            }
            else
            {
                std::cout << " " << stoi(curr);
            }

            str_vec.push_back(std::move(curr));
            curr = "";
        }
    }

    /* comma */
    if ("#" == curr)
    {
        std::cout << " nullptr";
    }
    else
    {
        std::cout << " " << stoi(curr);
    }

    str_vec.push_back(std::move(curr));
    std::cout << std::endl;

    /* string int_str = " 122333"; */
    /* int num = stoi(int_str); */
    /* std::cout << num << std::endl; */

    for (const auto& str: str_vec)
    {
        std::cout << " " << str;
    }
    std::cout << std::endl;

    /* Method 2: use getline and stringstream.
       We can use getline(istream& is, string& str, char delim) function to split a sentence on
       the basis of a character.
       is: The object from which chars are extracted.
       str: string object where the extracted chars are stored.
       return is is!
       If the delimiter is found, ** what is extracted will be discarded **.
       The default delimiter is newline which means you can use getline read lines by line.
    */
    /*
       https://www.geeksforgeeks.org/getline-string-c/
    */
    stringstream ss(serialize_str);
    string node_val;
    std::cout << "Use getline()" << std::endl;

    /* When does the loop terminate?
       getline sets the eofbit of ss when it reaches the End Of File.
       This causes the operator bool of ss to evaluate to false, which then terminates your loop
       getline return input stream.
    */
    while (getline(ss, node_val, ','))
    {
        std::cout << " " << node_val;
    }

    std::cout << std::endl;

    std::cout << " input stream: " << ss.str() <<std::endl;

    fstream data_file;
    data_file.open("xyz.txt", ios::out);

    if (data_file.is_open())
    {
        data_file << "This is 1 line\n";
        data_file << "This is 2 line\n";
        data_file << "This is 3 line\n";
        data_file << "This is 4 line\n";
        data_file << "This is 5 line\n";
        data_file.close();
    }
    else
    {
        std::cout << "Failed to open xyz.txt!" << std::endl;
    }

    string data;
    data_file.open("xyz.txt", ios::in);
    if (data_file.is_open())
    {
        string data;
        /* You can image there is a pointer in getline function to mark where it stops at the
           previous iteration. */
		/* By default, the delimiter is \n*/
        while (getline(data_file, data))
        {
            cout << data << '\n';
        }

        data_file.close();
    }

    return 0;
}

/*
 * \ref https://stackoverflow.com/questions/67631098/what-is-the-difference-between-ifstream-ofstream-and-fstream
 * \ref https://cplusplus.com/reference/string/string/getline/
 */

