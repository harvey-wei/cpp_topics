/* ref: https://www.geeksforgeeks.org/file-handling-c-classes/ */
/* ref: https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm */
#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
   char data[100];

   // ofstream defaults to be ios::out mode, automatically deletes
   // the content of file.
   // To append the content, open in ios:app
   // outfile.open("afile.txt", ios::app)
   // open a file in appending mode to avoid overwriting
   // To clear the content in the file before opening, use ios::trunc

   // Create and open a text file if it does not exists
   // Don't forget to close it.
   // https://stackoverflow.com/questions/48085781/what-is-the-difference-among-iosapp-out-and-trunc-in-c
   ofstream outfile;
   outfile.open("afile.txt", ios::app);

   cout << "Writing to the file" << endl;
   cout << "Enter your name: ";
   cin.getline(data, 100);

   // write inputted data into the file.
   outfile << data << endl;

   cout << "Enter your age: ";
   cin >> data;
   cin.ignore();

   // again write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();

   // open a file in read mode.
   ifstream infile;
   std::string infile_path = "afile.txt";
   infile.open(infile_path.c_str());

   if (infile.fail())
   {
       cerr << "Error - Failed to open " << infile_path << std::endl;
   }

   cout << "Reading from the file" << endl;
   infile >> data;

   // write the data at the screen.
   cout << data << endl;

   // again read the data from the file and display it.
   infile >> data;
   cout << data << endl;

   // close the opened file.
   infile.close();

   return 0;
}

/**
 * https://www.cs.uic.edu/~jbell/CourseNotes/CPlus/FileIO.html
 */
