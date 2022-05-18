/* ref: https://www.geeksforgeeks.org/file-handling-c-classes/ */
/* ref: https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm */
#include <fstream>
#include <iostream>
using namespace std;
 
int main () {
   char data[100];

   // ofstream defaults to be ios::out mode, automatically deletes
   // the content of file. 
   // To append the content, open in ios:app
   // outfile.open("afile.txt", ios::app)
   // open a file in appending mode to avoid overwriting
   // To clear the content in the file before opening, use ios::trunc
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
   infile.open("afile.txt"); 
 
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
