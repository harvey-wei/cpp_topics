// Copy a file
#include <fstream>      // std::ifstream, std::ofstream
#include <iostream>

int main ()
{
    std::string bin_file_path = "/home/harvey/Desktop/baidu_bin_label/bins/000004.bin";
    std::ifstream bin_file(bin_file_path, std::ifstream::in | std::ifstream::binary);

    // get size of file
    /* std::cout << "initial position " << bin_file.tellg() << std::endl; */
    bin_file.seekg(0, bin_file.end);  // seek to the end char of the fstream
    long bin_size = bin_file.tellg();  // *current* char position, and size is in byte, g for get()
    /* std::cout << "EOF?" << bin_file.eof() << std::endl; */
    /* std::cout << "size of infile: " << bin_size << std::endl; */
    bin_file.seekg(0);

    /* int pt_cnt = 0; */
    /* float x, y, z, r; */
    /**/
    /* int i = 0; */
    /* std::cout << "before ... seek pos: " << bin_file.tellg() << std::endl; */
    /* while (bin_file.good() && !bin_file.eof()) */
    /* while ( i < bin_size) */
    /* { */
        /* std::cout << "before ... seek pos: " << bin_file.tellg() << std::endl; */
        /* bin_file.read((char *) &x,  sizeof(float)); */
        /* bin_file.read((char *) &y,  sizeof(float)); */
        /* bin_file.read((char *) &z,  sizeof(float)); */
        /* bin_file.read((char *) &r,  sizeof(float)); */
        /* std::cout << "after ... seek pos: " << bin_file.tellg() << std::endl; */

        /* https://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line */
        /* if(bin_file.eof() ) break; */
    /*     std::cout << "x, y, z, r: " << x << "," << y << ", " << z << ", " */
    /*             << r << std::endl; */
    /*     ++pt_cnt; */
    /*     i += 16; */
    /* } */
    /**/
    /* std::cout << "Total point count: " << pt_cnt << std::endl; */
    /* std::cout << "Total point count from bytes: " << bin_size / (4 * sizeof(float)) << std::endl; */
    /* std::cout << "Total bytes: " << bin_size << std::endl; */
    /**/
    bin_file.close();
    /**/
    /**/
    std::string label_file_path = "/home/harvey/Desktop/baidu_bin_label/labels/000004.label";
    std::ifstream label_file(label_file_path, std::ifstream::in | std::ifstream::binary);
    // get size of file
    label_file.seekg(0, label_file.end);  // seek to the end char of the fstream
    long label_file_size = label_file.tellg();
    label_file.seekg(0);

    if ((4 * label_file_size) != bin_size)
    {
        std::cout << "label and bin do not match in point counts!" << std::endl;
        return -1;
    }


    int byte_cnt = 0;

    while (byte_cnt < label_file_size)
    {
        uint32_t label_id;
        label_file.read((char*) &label_id,  sizeof(uint32_t));

        std::cout << "label_id " << label_id << std::endl;

        /* if (7 == label_id) break; */

        byte_cnt += 4;
    }

    return 0;
}


/*
 * The EOF flag is only set once a read tries to read past the end of the file.
 * \ref https://stackoverflow.com/questions/4533063/how-does-ifstreams-eof-work
 * \ref https://stackoverflow.com/questions/4533063/how-does-ifstreams-eof-work
 * tellg [0, N-1] valid bytes seek to zero to end->N hence, the number of bytes of file
 */
