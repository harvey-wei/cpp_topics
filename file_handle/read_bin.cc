// Copy a file
#include <fstream>      // std::ifstream, std::ofstream
#include <iostream>

int main ()
{
    std::string bin_file_path = \
        "/home/harvey/Files/tasks/to_ann_by_baidu/pc_seg_2k/pc_seg_2k_jica_bin/20230327093750_merge_bin/000004.bin";

    std::ifstream bin_file(bin_file_path, std::ifstream::in | std::ifstream::binary);

    // get size of file
    bin_file.seekg(0, bin_file.end);  // seek to the end char of the fstream 
    long size = bin_file.tellg();  // current char position, and size is in byte, g for get()
    std::cout << "size of infile: " << size << std::endl;

    bin_file.seekg(0);
    /* seekg Sets the position of the next character to be extracted from the input stream. */
    int pt_cnt = 0;
    float x, y, z, r;

    int i = 0;
    /* std::cout << "before ... seek pos: " << bin_file.tellg() << std::endl; */
    /* while (bin_file.good() && !bin_file.eof()) */
    while ( i < size)
    {
        /* std::cout << "before ... seek pos: " << bin_file.tellg() << std::endl; */
        bin_file.read((char *) &x,  sizeof(float));
        bin_file.read((char *) &y,  sizeof(float));
        bin_file.read((char *) &z,  sizeof(float));
        bin_file.read((char *) &r,  sizeof(float));
        /* std::cout << "after ... seek pos: " << bin_file.tellg() << std::endl; */

        /* https://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line */
        /* if(bin_file.eof() ) break; */
        std::cout << "x, y, z, r: " << x << "," << y << ", " << z << ", "
                << r << std::endl;
        ++pt_cnt;
        i += 16;
    }

    std::cout << "Total point count: " << pt_cnt << std::endl;
    std::cout << "Total point count from bytes: " << size / (4 * sizeof(float)) << std::endl;
    std::cout << "Total bytes: " << size << std::endl;

    bin_file.close();



  return 0;
}


/*
 * The EOF flag is only set once a read tries to read past the end of the file.
 * \ref https://stackoverflow.com/questions/4533063/how-does-ifstreams-eof-work
 */
