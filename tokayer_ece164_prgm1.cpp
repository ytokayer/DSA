/**
Yaron Tokayer
DSA Programming Assignment 1

Follows commands from an input file to create and modify stacks and queues.
Records runtime to output file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function to create input stream by user input
void inputstrm (fstream *input){
	string infile;
	cout << "Enter name of input file: ";
	cin >> infile;
	input->open(infile.c_str());
	//fstream input (infile.c_str());
	// return input;
}

// function to create output stream by user input
void outputstrm( fstream *output ){
	string outfile;
	cout << "Enter name of output file: ";
	cin >> outfile;
	output->open(outfile.c_str(), ios::out);
	//fstream output (outfile.c_str(), ios::out | ios::app);
	//return output;
}

int main()
{
	fstream input;
	inputstrm( &input );
	
	fstream output;
	outputstrm ( &output );

	// fstream input = inputstrm(); // create input stream	
	/*
	string infile;
	cout << "Enter name of input file: ";
	cin >> infile;
	fstream input (infile.c_str());
	*/
	// fstream output = outputstrm(); // create output stream	
	/*
	string outfile;
	cout << "Enter name of output file: ";
	cin >> outfile;
	fstream output (outfile.c_str(), ios::out | ios::app);
	*/
	
	int i = 1;
	string currline; // string with current line
	while( getline (input, currline) ) // test for existence of line
	{
		output << currline << '\n';
		++i;
	}
	
	// close input and output streams
	input.close();
	output.close();
	
	return 0;
}
/*
// base class to provide singly-linked list functionality
template <typename T>
class SimpleList{
	protected:
		void push_front( const T & x ) // method to push at front of list
		void push_back( const T & x ) // method to push at back of list
		T pop( ) //method to pop from the front of a list always from front
}

// stack as a derived class template
template <typename T>
class Stack: public SimpleList{

}

// queue as a derived class template
template <typename T>
class Queue: public SimpleList{

}
*/