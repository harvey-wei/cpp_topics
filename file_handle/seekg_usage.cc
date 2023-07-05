// CPP Program to demonstrate the
// seekg function in file
// handling
// https://www.geeksforgeeks.org/set-position-with-seekg-in-cpp-language-file-handling/
// https://www.tutorialspoint.com/set-position-with-seekg-in-cplusplus-language-file-handling
#include <fstream>
#include <iostream>
using namespace std;

// Driver Code
int main(int argc, char** argv)
{
	// Open a new file for input/output operations
    // and discarding any current bytes in the file
	fstream myFile("test.txt",
				ios::in | ios::out | ios::trunc);

	// Add the characters "Hello World" to the file
	myFile << "Hello World";

	// Seek to 6 characters from the beginning of the file
    // set the pointer to the 6th characters(byte) from the beginning of the file
	/* myFile.seekg(6, ios::beg); */
	myFile.seekg(6, myFile.beg);

	// Read the next 5 characters from the file into a
	// buffer
	char A[6];
	myFile.read(A, 5);

	// End the buffer with a null terminating character
	A[5] = 0;

	// Output the contents read from the file and close it
	cout << A << endl;


	myFile.close();
}

/*
 * seekg() is a function in the iostream library that allows us to seek an arbitrary position in a file. It is mainly used to set the position of the next character to be extracted from the input stream from a given file in C++ file handling.
 */
