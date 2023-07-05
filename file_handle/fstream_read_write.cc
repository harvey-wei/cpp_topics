// Copy a file
#include <fstream>      // std::ifstream, std::ofstream
#include <iostream>

int main ()
{
  std::ifstream infile ("test.txt",std::ifstream::binary);
  std::ofstream outfile ("new.txt",std::ofstream::binary);

  // get size of file
  infile.seekg(0,infile.end);  // seek to the end char of the fstream 
  long size = infile.tellg();  // current char position, and size is in byte, g for get()
  std::cout << "size of infile: " << size << std::endl;
  infile.seekg(0);

  // allocate memory for file content
  /* size ; */
  char* buffer = new char[size];

  // read content of infile
  // Extracts n characters from the stream and stores them in the array pointed to by s.
  std::cout << "current seek pos: " << infile.tellg() << std::endl;
  infile.read(buffer,size);
  std::cout << "current seek pos: " << infile.tellg() << std::endl;

  // write to outfile
  // insert the first size chars of array buffer into the outfile
  // https://cplusplus.com/reference/ostream/ostream/write/
  outfile.write (buffer, size);

  // release dynamically-allocated memory
  delete[] buffer;

  outfile.close();
  infile.close();
  return 0;
}
