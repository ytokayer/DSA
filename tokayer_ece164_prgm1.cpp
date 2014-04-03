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
}

// function to create output stream by user input
void outputstrm( fstream *output ){
	string outfile;
	cout << "Enter name of output file: ";
	cin >> outfile;
	output->open(outfile.c_str(), ios::out);
}

// base class to provide singly-linked list functionality
template <typename T>
class SimpleList{
	private:
		struct Node{ // nested Node class for SimpleList
			T data; // Node data members
			Node *next;
			
			Node( const T & d, Node *n = NULL ) // Node constructor
				: data( d ), next( n ) {}
		}
		
		string name;
		Node *front; // pointers to front and back of list
		Node *back;
		
	protected:
		virtual void push_front( const T & x ){ // method to push at front of list
			Node *newnode =	new Node( x, front );
			front = newnode;
		}
		virtual void push_back( const T & x ){ // method to push at back of list
			Node *newnode = new Node( x );
			back = newnode;
		}
		virtual T pop_front( ){ //method to pop from the front of a list and return value
			T tmp1 = front.data;
			Node *tmp2 = front.next;
			delete front;
			front = ptr;
			return data;
		}
	
	public:
		string name( const SimpleList & nn ){
			return 
		}
}

// stack as a derived class of SimpleList
template <typename T>
class Stack: public SimpleList{
	public:
		Stack( string nn ){ // Stack constructor
			this.name = nn;
		}
		void push( const T & x){
			push_front( x );
		}
		T pop(){
			pop_front();
		}

}

// queue as a derived class of SimpleList
template <typename T>
class Queue: public SimpleList{
	public:
		Queue( string nn ){ // Queue contructor
			this.name = nn;
		}
		void push( const T & x){
			push_back( x );
		}
		T pop(){
			pop_front();
		}
}


int main()
{
	fstream input; // create input stream
	inputstrm( &input );
	
	fstream output; // create output stream
	outputstrm ( &output );
	
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