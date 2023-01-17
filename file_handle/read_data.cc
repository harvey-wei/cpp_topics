#include <iostream>
#include <fstream>

int main()
{
    std::ofstream fout("input_file.txt");
    fout << "a " << "b " << "c " << std::endl;
    fout << "1 " << "2 " << "3 " << std::endl;
    fout.close();

    std::ifstream fin("input_file.txt");

    std::cout <<" starting reading " << std::endl;


    /* Read all data until the end of file has been reached.*/
    /*
    All istreams ( and ifstreams ) have a method, eof( ), that returns a boolean value of true
    AFTER an attempt has been made to read past the end of the file, and false otherwise.
    (1) Read some data first, then (2) check to see if you've gone past the end of the file,
    and finally (3) use the data only after you have verified that the reading succeeded.
    In otherwords, ifstream.eof() returns true if the last read passes the end of the file,
    otherwise false because ifstream has a eof bit which is set to true when an attempt is
    made to read past the end of the file.
    */

    std::string x, y, z;
    fin >> x >> y >> z;
    while ( !fin.eof( ) ) {
        // Do something with x, y, z
        std::cout << x << y << z << std::endl;

        // Read in the new data for the next loop iteration.
        fin >> x >> y >> z;
    } // while loop reading until the end of file
    fin.close();
}

/*
https://www.cs.uic.edu/~jbell/CourseNotes/CPlus/FileIO.html
*/
